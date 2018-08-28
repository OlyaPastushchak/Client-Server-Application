#ifndef ISOCKET_H
#define ISOCKET_H

#ifdef _WIN32
#include<WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#define SOCKET_ERROR -1
#define INVALID_SOCKET -1
#define SOCKET int
#endif

#include<string>
#include<exception>
#include<iostream>
#define BUF_SIZE 4096
#define SUCCESS 1
#define FAIL 0
#define PORT 56000
#define iP_ADDRESS "127.0.0.1"

class ISocket
{
protected:
	int port;
	std::string ipAddress;
	SOCKET socket;
public:
	ISocket() :port(PORT), ipAddress(iP_ADDRESS) {}
	virtual ~ISocket();
	int getPort();
	std::string getIpAddress();
	void setSocket(SOCKET);
	SOCKET getSocket();
	int connect(sockaddr_in& hint);//for client
	int bind(sockaddr_in& hint);//for server
	int listen();//for server
	int sendInfo(const char * info, int infoSize);
	virtual int receiveInfo(char * info, int infoSize) = 0;
	virtual void close() = 0;
	virtual SOCKET acceptClient() = 0;//for server
};



#endif