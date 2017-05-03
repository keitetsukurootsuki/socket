#include<stdio.h>
#include<string.h>   
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
 
int main(int argc , char *argv[])
{
    int welcomeSocket , client_sock , c , read_size;
    struct sockaddr_in serveraddr , clientaddr;
    char client_message[2000], temp;
    int a, b = 0;
     
    welcomeSocket = socket(AF_INET , SOCK_STREAM , 0);
    if (welcomeSocket == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    //Prepare the sockaddr_in structure
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr( "192.168.118.1" );
    serveraddr.sin_port = htons( 7891 );
     
    if( bind(welcomeSocket,(struct sockaddr *)&serveraddr , sizeof(serveraddr)) < 0)
    {
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");
    listen(welcomeSocket , 5);
     
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
     
    //accept connection from incoming client
    client_sock = accept(welcomeSocket, (struct sockaddr *)&clientaddr, (socklen_t*)&c);
    if (client_sock < 0)
    {
        perror("Accept failed");
        return 1;
    }
    puts("Connection accepted");

    //Receive message from client
    while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 )
    {
    
	//Reverse message from client
	a = 0;
	b = strlen(client_message) - 1;

	while(a < b){
		temp = client_message[a];
		client_message[a] = client_message[b];
		client_message[b] = temp;
		a++;
		b--;
	}
	
	//Send the message back to client 
        write(client_sock , client_message, strlen(client_message));
		//memset(client_message,'\0',sizeof(client_message));
    }
     
    if(read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        perror("Receive failed");
    }
     
    return 0;
}

