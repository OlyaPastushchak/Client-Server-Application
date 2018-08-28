#include"Server.h"

int main()
{
	Server server;
	try
	{
		server.startServer();
		while (true)
		{
			server.acceptClient();
			server.requestSearch();

		}
		server.endListening();
	}
	catch (const std::runtime_error& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}