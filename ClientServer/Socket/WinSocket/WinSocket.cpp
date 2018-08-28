#include"WinSocket.h"
#ifdef _WIN32

int Socket::init()
{
	WSADATA wsData;
	WORD ver = MAKEWORD(2, 2);
	int isInitialized = WSAStartup(ver, &wsData);

	if (isInitialized != 0)
	{
		return FAIL;
	}
	return SUCCESS;
}

Socket::Socket() :ISocket()
{
	int isInitialized = init();
	if (isInitialized)
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
	else
	{
		throw std::runtime_error("can't initialize winsock");
	}

}

SOCKET Socket::acceptClient()
{
	sockaddr_in client;
	int clientSize = sizeof(client);

	SOCKET clientSocket = accept(socket, (sockaddr*)&client, &clientSize);
	if (clientSocket == INVALID_SOCKET)
	{
		return INVALID_SOCKET;
	}
	char remoteHost[NI_MAXHOST];
	char rPort[NI_MAXSERV];
	ZeroMemory(remoteHost, NI_MAXHOST);
	ZeroMemory(rPort, NI_MAXSERV);

	if (getnameinfo((sockaddr*)&client, sizeof(client), remoteHost, NI_MAXHOST, rPort, NI_MAXSERV, 0) == 0)
	{
		std::cout << remoteHost << " connected on port " << rPort << std::endl;
	}

	return clientSocket;
}

int Socket::receiveInfo(char * info, int infoSize)
{
	ZeroMemory(info, infoSize);
	int bytesReceived = recv(socket, info, infoSize, 0);
	if (bytesReceived == SOCKET_ERROR)
	{
		return -1;
	}
	return bytesReceived;
}

void Socket::close()
{
	closesocket(socket);
}

Socket::~Socket()
{
	close();
	WSACleanup();
}

#endif