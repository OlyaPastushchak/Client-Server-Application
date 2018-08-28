#include"LinSocket.h"

#ifdef __linux__

Socket::Socket() :ISocket()
{
	SOCKET sock = ::socket(AF_INET, SOCK_STREAM, 0);//:: global namespace

	if (sock == INVALID_SOCKET)
	{
		throw std::runtime_error("Can't create socket");
	}
	else
	{
		socket = sock;
	}
}

SOCKET Socket::acceptClient()
{
	sockaddr_in client;
	socklen_t clientSize = sizeof(client);

	SOCKET clientSocket = accept(socket, (sockaddr*)&client, &clientSize);
	if (clientSocket == INVALID_SOCKET)
	{
		throw std::runtime_error("Didn't accept client socket");
		return INVALID_SOCKET;
	}
	char remoteHost[NI_MAXHOST];
	char rPort[NI_MAXSERV];
	bzero(remoteHost, NI_MAXHOST);
	bzero(rPort, NI_MAXSERV);

	if (getnameinfo((sockaddr*)&client, sizeof(client), remoteHost, NI_MAXHOST, rPort, NI_MAXSERV, 0) == 0)
	{
		std::cout << remoteHost << " connected on port " << rPort << std::endl;
	}
	return clientSocket;
}

int Socket::receiveInfo(char * info, int infoSize)
{
	bzero(info, infoSize);
	int bytesReceived = recv(socket, info, infoSize, 0);
	if (bytesReceived == SOCKET_ERROR)
	{
		return -1;
	}
	return bytesReceived;
}

void Socket::close()
{
	::close(socket);
}

Socket:: ~Socket()
{
	close();
}

#endif