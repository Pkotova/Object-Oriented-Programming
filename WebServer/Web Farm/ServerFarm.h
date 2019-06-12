#pragma once
#include "WebServer.h"

class ServerFarm
{
private:
	WebServer* farm;
	int size;
	int capacity;

	void resizeUp();
	void resizeDown();
	void copy(const ServerFarm&);
	void destroy();
public:
	ServerFarm();
	ServerFarm(const ServerFarm&);
	ServerFarm& operator=(const ServerFarm&);
	~ServerFarm();

	int countInNetwork(const int);
	void findMaxNetwork();
	ServerFarm& sort();

	ServerFarm& operator-=(const int[4]);
	ServerFarm& addServer(const WebServer&);
	void removeServer(const int[4]);
	void print();
	bool isFull();
};

