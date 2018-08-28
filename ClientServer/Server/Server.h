#ifndef SERVER_H
#define SERVER_H

#ifdef _WIN32
#include<WS2tcpip.h>//for win sockets
#include"../Socket/WinSocket/WinSocket.h"
#pragma comment (lib, "ws2_32.lib")//to link with Ws2_32.lib
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <strings.h>
#include"../Socket/LinSocket/LinSocket.h"
#define INVALID_SOCKET -1
#endif

#include<iostream>
#include <sstream>
#include<exception>
#include"../Socket/ISocket/ISocket.h"
#define PROCESSING_MESSAGE "processing..."

class Server
{
private:
	ISocket * listeningSocket;
	ISocket* clientSocket;
public:
	Server();
	~Server();
	void startServer();
	void acceptClient();
	void requestSearch();
	void endListening();
};

#endif