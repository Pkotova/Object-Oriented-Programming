// Web Farm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "WebServer.h"
#include "ServerFarm.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int ip1[] = { 2,0,1,1 };
	int ip2[] = { 2,1,1,0 };
	int ip3[] = { 2,1,0,0 };
	int ip4[] = { 2,1,0,0 };
	WebServer a, b, c, d;
	a.setIP(ip1);
	b.setIP(ip2);
	c.setIP(ip3);
	d.setIP(ip4);
	ServerFarm f;
	f.addServer(a);
	f.addServer(a);
	f.addServer(a);
	f.addServer(b);
	f.addServer(c);
	f.addServer(d);
	
	f.sort().print();

	f.findMaxNetwork();
	
	return 0;
}