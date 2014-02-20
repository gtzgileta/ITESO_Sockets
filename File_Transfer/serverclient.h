/*
  Oswaldo Daniel Arroyo Vasquez rt689444
  Programación de Sockets 19/02/14
*/

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#ifndef _SERVERCLIENT_H
#define _SERVERCLIENT_H


//prototypes
int start_server(int args,char *argv[],struct sockaddr_in *server_addr);
int start_client(int args,char *argv[],struct sockaddr_in *server_addr);

#endif
