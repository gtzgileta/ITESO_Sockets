/*
	Autor: Oswaldo Daniel Arroyo Vasquez Ing. Redes y Telecomunicaciones
	Fechar: 13 de Marzo de 2014
	Programación de Sockets
*/          

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>  

int main (int argc, char const *argv[])
{
	int udpSocket;
	struct sockaddr_in udpServer, udpClient;
	
	socklen_t addrlen = sizeof(udpClient);
	char buffer[255];
	char ip[17];
	u_short ClientPort;
	
	char *SendString = "Mi PC";
	unsigned int SendStringLen;
	int Status;
	
	//Se crea el Socket
	udpSocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if(udpSocket == -1)
			{
				fprintf(stderr,"Can´t created UDP Socket");
				return 1;
			}            
	
	udpServer.sin_family = AF_INET;
	inet_pton(AF_INET,"0.0.0.0",&udpServer.sin_addr.s_addr);
	udpServer.sin_port = htons(5000);
	
	Status = bind(udpSocket,(struct sockaddr*)&udpServer,sizeof(udpServer));
		if(Status != 0)
			{
				fprintf(stderr,"Can´t bind"); 
			}
	          
	bzero(buffer, 255);
	SendStringLen = strlen(SendString); 
	Status = recvfrom(udpSocket,buffer,255,0,(struct sockaddr*)&udpClient,&addrlen);
	udpServer.sin_family = AF_INET;
	inet_ntop(AF_INET,&(udpClient.sin_addr),ip,INET_ADDRSTRLEN);
	ClientPort = ntohs(udpClient.sin_port);
	printf("Recived from [%s:%i]:%s\n",ip,ClientPort,buffer);
	
	Status = sendto(udpSocket,SendString,SendStringLen,0,(struct sockaddr*)&udpClient,sizeof(udpClient));
	fflush(stdout);
	close (udpSocket);
	return 0;
}


