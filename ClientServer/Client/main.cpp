#include"Client.h"

int main()
{
	Client client;
	try
	{
		client.connectToServer();
		client.receiveRequest();
	}
	catch (const std::runtime_error& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}