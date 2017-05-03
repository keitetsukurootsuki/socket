#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(int argc , char *argv[])
{
	int clientSocket;
	struct sockaddr_in serverAddr;
	char message[1000] , server_reply[2000];
	
	//Create socket
	sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1)
	{
		printf("Could not create socket");
	}
	puts("Socket created");
	
	serverAddr.sin_addr.s_addr = inet_addr("192.168.118.1");
	server.sin_family = AF_INET;
	server.sin_port = htons( 7891 );
	memset(serverAddr.sin_zero, '/0', sizeof 	serverAddr.sin_zero);

	//Connect to remote server
	if (connect(clientSocket , (struct sockaddr *)
	&serverAddr , sizeof(serverAddr)) < 0)
	{
		perror("Connect failed. Error");
		return 1;
	}
	
	puts("Connected\n");
	
	//keep communicating with server
	while(1)
	{
		printf("Enter message : ");
		scanf("%s" , message);
		
		//Send some data
		if( send(clientSocket , msg , strlen(msg) , 0) < 0)
		{
			puts("Send Failed");
			return 1;
		}
		
		//Receive a reply from the server
		if( recv(clientSocket , server_reply , 2000 , 0) 			< 0)
		{
			puts("Received Failed");
			break;
		}
		
		puts("Server reply :");
		puts(server_reply);
	}
	
	//close(clientSocket);
	return 0;
}
