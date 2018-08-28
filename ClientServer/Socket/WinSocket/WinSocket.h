#ifndef _WINSOCKET_H_
#define _WINSOCKET_H_
#include<iostream>
#include"../ISocket/ISocket.h"


class Socket : public ISocket
{
private:
	int init();
public:
	Socket();
	~Socket();
	SOCKET acceptClient();
	void close();
	int receiveInfo(char* info, int infoSize);
};

#endif
