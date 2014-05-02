#include "RakPeerInterface.h"
#include "Config.h"

class Server
{
public:
	Server();
	~Server();

	void update();
	bool quit();

private:
	RakNet::RakPeerInterface*        m_Server;
	
	bool                             b_Quit;
};
