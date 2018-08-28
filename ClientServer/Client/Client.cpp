#include"Client.h"

Client::Client()
{
	//initialize and create socket
	connectSocket = new Socket();
	fileSearch = new FileSearch();
}

void Client::connectToServer()
{
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(connectSocket->getPort());
	inet_pton(AF_INET, connectSocket->getIpAddress().c_str(), &hint.sin_addr);

	//connect to server
	if (!connectSocket->connect(hint))
	{
		throw std::runtime_error("can't connect to server.");
	}
	std::cout << "Connected to server!" << std::endl;
}

void Client::sendReply()
{
	std::string processing = PROCESSING_MESSAGE;
	while (!fileSearch->isFound)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(STEP));
		connectSocket->sendInfo(processing.c_str(), processing.size());
	}
}

std::string Client::search(std::string requestedFile)
{
	return fileSearch->doSearch(requestedFile);
}

void Client::receiveRequest()
{
	char buf[BUF_SIZE];
	while (true)
	{
		//wait for server to send fileName

		int bytesReceived = connectSocket->receiveInfo(buf, BUF_SIZE);
		if (bytesReceived == -1)
		{
			throw std::runtime_error("error while receiving");
		}
		std::string requestedFile = std::string(buf, 0, bytesReceived);
		fileSearch->isFound = false;
		std::cout << "Server requested file: " << requestedFile << std::endl;

		std::thread sendingReply(&Client::sendReply, this);
		auto future = std::async(&Client::search, this, requestedFile);
		sendingReply.join();
		std::string reply = future.get();

		//send answer on server's request to him
		connectSocket->sendInfo(reply.c_str(), reply.size());
	}
}

Client::~Client()
{
	connectSocket->close();
	delete connectSocket;
	delete fileSearch;
}
