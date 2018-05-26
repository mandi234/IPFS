#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <memory>
#include <thread>
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"
#define SERVERPORT 4950
class Broadcast
{
	int sockfd;
	struct sockaddr_in their_addr; // connector's address information
	struct hostent *he;
	int numbytes;
	char broadcast = '1';
public:
	Broadcast();
	~Broadcast();




	int sendBroadcast();
};

