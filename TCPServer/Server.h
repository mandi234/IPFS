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


class Server
{
	WSADATA wsaData;
	int iResult;

	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;

	struct addrinfo *result = NULL;
	struct addrinfo hints;

	int iSendResult;
	char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;

	int initServer();
public:
	Server();
	~Server();
	std::vector<std::shared_ptr<std::thread> > connectionHandlers;
	int startListening();

	void handleConnection(SOCKET ClientSocket);
};

