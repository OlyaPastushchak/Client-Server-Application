#ifndef CLIENT_H
#define CLIENT_H

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
#include <pthread.h>
#endif

#include<iostream>
#include<string>
#include<exception>
#include<thread>
#include<future>
#include"FileSearch/FileSearch.h"
#include"../Socket/ISocket/ISocket.h"
#define PROCESSING_MESSAGE "processing..."
#define STEP 500

class Client
{
private:
	ISocket * connectSocket;
	FileSearch* fileSearch;
private:
	std::string search(std::string requestedFile);
	void sendReply();
public:
	Client();
	~Client();
	void connectToServer();
	void receiveRequest();
};

#endif