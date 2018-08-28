#ifndef _LIN_SOCKET_H_
#define _LIN_SOCKET_H_
#include"../ISocket/ISocket.h"


class Socket : public ISocket
{
public:
	Socket();
	~Socket();
	SOCKET acceptClient();
	void close();
	int receiveInfo(char* info, int infoSize);
};

#endif
