#include"Server.h"

Server::Server()
{
	//initializes and creates socket
	listeningSocket = new Socket();
	clientSocket = new Socket();
}

void Server::startServer()
{
	//link this ip address and port to the socket
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(listeningSocket->getPort());
	hint.sin_addr.s_addr = htonl(INADDR_ANY);

	if (!listeningSocket->bind(hint))
	{
		throw std::runtime_error("can't link ip address and port to socket.");
	}

	//start listening to clients for connection
	if (!listeningSocket->listen())
	{
		throw std::runtime_error("can't place socket for listening.");
	}

	std::cout << "Server started! Listening for connection..." << std::endl;
}

void Server::acceptClient()
{
	//accept client
	clientSocket->setSocket(listeningSocket->acceptClient());

	if (clientSocket->getSocket() == INVALID_SOCKET)
	{
		throw std::runtime_error("Didn't accept client socket");
	}
}


void Server::endListening()
{
	listeningSocket->close();
}

void Server::requestSearch()
{
	char buf[BUF_SIZE];
	std::string fileName;
	do
	{
		//ask server for some text
		std::cout << "enter file name" << std::endl;
		getline(std::cin, fileName);

		if (fileName.size() > 0)
		{
			//send the text
			int sendResult = clientSocket->sendInfo(fileName.c_str(), fileName.size());
			if (sendResult != 0)
			{
				int bytesReceived;
				//wait for client's reply
				do
				{
					bytesReceived = clientSocket->receiveInfo(buf, BUF_SIZE);
					if (bytesReceived > 0)
					{
						std::string reply = std::string(buf, 0, bytesReceived);
						std::cout << "Client replied: " << reply << std::endl;
						if (reply != PROCESSING_MESSAGE)
						{
							break;
						}
					}
					else
					{
						return;
					}
				} while (bytesReceived > 0);
			}
			else
			{
				std::cout << "Client disconnected!" << std::endl;
				return;
			}
		}
		else
		{
			return;
		}
	} while (fileName.size() > 0);
}

Server::~Server()
{
	clientSocket->close();
	delete listeningSocket;
	delete clientSocket;
}