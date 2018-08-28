#include"ISocket.h"

int ISocket::getPort()
{
	return port;
}

std::string ISocket::getIpAddress()
{
	return ipAddress;
}

void ISocket::setSocket(SOCKET sock)
{
	socket = sock;
}

SOCKET ISocket::getSocket()
{
	return socket;
}

int ISocket::connect(sockaddr_in& hint)
{
	int connectionResult = ::connect(socket, (sockaddr*)&hint, sizeof(hint));
	if (connectionResult == SOCKET_ERROR)
	{
		return FAIL;
	}
	return SUCCESS;
}

int ISocket::bind(sockaddr_in& hint)
{
	int isBinded = ::bind(socket, (sockaddr*)&hint, sizeof(hint));
	if (isBinded == SOCKET_ERROR)
	{
		return FAIL;
	}
	return SUCCESS;
}

int ISocket::listen()
{
	int isListening = ::listen(socket, SOMAXCONN);
	if (isListening == SOCKET_ERROR)
	{
		return FAIL;
	}
	return SUCCESS;
}

int ISocket::sendInfo(const char * info, int infoSize)
{
	int bytesSent = send(socket, info, infoSize, 0);
	if (bytesSent == SOCKET_ERROR)
	{
		return FAIL;
	}
	return bytesSent;
}

ISocket::~ISocket()
{
	ipAddress.clear();
}