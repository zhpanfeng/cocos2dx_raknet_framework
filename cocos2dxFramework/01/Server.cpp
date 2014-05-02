#include "Server.h"
#include "RakSleep.h"
#include "BitStream.h"
#include "MessageIdentifiers.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

Server::Server() : b_Quit(false)
{

	int port;
	int maxClients;
	std::string ipAddress;
	std::string password;
	const char ConfigFile[]= "config"; 
	Config configSettings(ConfigFile);
	
	port = configSettings.Read("port", 0);
	maxClients = configSettings.Read("maxClients",maxClients);
	ipAddress = configSettings.Read("ipAddress", ipAddress);
	password = configSettings.Read("password", password);	
	// 创建服务器连接
	m_Server = RakNet::RakPeerInterface::GetInstance();
	// 初始化监听端口
	RakNet::SocketDescriptor socketDescriptor(port, 0);
	cout<<"----------------cocos2dx and raknet framework------------"<<endl;
	cout<<"---------------------------server-----------------------"<<endl;
   cout<<"port :"<<port<<endl;
   cout<<"maxClients :"<<maxClients<<endl;
   cout<<"ipAddress :"<<ipAddress<<endl;
   cout<<"password : "<<password<<endl;
}
//---------------------------------------------------------------------------------------------------------
Server::~Server()
{
	RakNet::RakPeerInterface::DestroyInstance(m_Server);
}
void Server::update()
{/* 
	for(RakNet::Packet* packet = m_Server->Receive(); packet != NULL; packet = m_Server->Receive())
	{
		unsigned char packetID = packet->data[0];
		if(packetID == ID_TIMESTAMP)
			//packetID = packet->data[sizeof(unsigned char) + sizeof(RakNetTime)];
			packetID = packet->data[sizeof(unsigned char) + sizeof(uint32_t)];
		switch (packet->data[0])
		{
		case ID_NEW_INCOMING_CONNECTION:
			handleClientStartup(packet);
			break;
		default:
			SetConsoleTextAttribute(m_Handle, FOREGROUND_RED);
			std::cout << "Received Type " << (int)packet->data[0] << " message，did not define the handler !\n";
			break;
		}
		m_Server->DeallocatePacket(packet);
	} */
}
//---------------------------------------------------------------------------------------------------------
bool Server::quit()
{
	return b_Quit;
}
