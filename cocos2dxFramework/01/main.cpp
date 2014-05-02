#include "Server.h"

int main()
{
	Server *server = new Server();

	while(!server->quit())
		server->update();

	delete server;

	return 0;
}