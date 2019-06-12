#include "pch.h"
#include "WebServer.h"
#include <cstring>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

WebServer::WebServer() //:WebServer("default.com", {0,0,0,0}, "defaultOS")
{
	int temp[] = { 0,0,0,0 };
	setURL("default.com");
	setIP(temp);
	setOS("defaultOS");
}


WebServer::WebServer(const char _url[500], const int _ip[4], const char _os[20])
{
	setURL(_url);
	setIP(_ip);
	setOS(_os);
}


WebServer::~WebServer()
{}

void WebServer::setURL(const char _url[500])
{
	strcpy_s(this->URL, 500, _url);
}

char * WebServer::getURL()
{
	return this->URL;
}

void WebServer::setIP(const int ip[4])
{
	for (size_t i = 0; i < 4; i++)
	{
		this->IPv4Address[i] = ip[i];
	}
}

int * WebServer::getIP()
{
	return this->IPv4Address;
}

void WebServer::setOS(const char _os[20])
{
	strcpy_s(this->OS, 20, _os);
}

char * WebServer::getOS() 
{
	return this->OS;
}

bool WebServer::operator<(const WebServer & _other)
{
	for (int i = 0; i < 4; i++)
	{
		if (!(this->IPv4Address[i] < _other.IPv4Address[i]))
		{
			return false;
		}
	}
	return true;
}

bool WebServer::operator==(const WebServer & _other)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->IPv4Address[i] != _other.IPv4Address[i])
		{
			return false;
		}
	}
	return strcmp(this->URL,_other.URL)==0 && 
		strcmp(this->OS, _other.OS) == 0;
}

bool WebServer::operator==(const int _other[4] )
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->IPv4Address[i] != _other[i])
		{
			return false;
		}
	}
	return true;
}

bool WebServer::operator^=(const WebServer& _other)
{
	for (int i = 0; i < 3; i++)
	{
		if (this->IPv4Address[i] != _other.IPv4Address[i])
		{
			return false;
		}
	}
	return true;
}

void WebServer::print() const
{
	cout << "URL: " << this->URL<<endl;
	cout << "IP: ";
	for (int i = 0; i < 4; i++)
	{
		cout << this->IPv4Address[i];
		if (i < 3)
		{
			cout << ".";
		}
	}
	cout << endl;
	cout << "OS: " << this->OS << endl;
	cout << endl;
}

void WebServer::read()
{
	cout << "URL: ";
	cin.getline(this->URL, 500);

	cout << "IP: ";
	for (int i = 0; i < 4; i++)
	{
		cin>> this->IPv4Address[i];
	}
	cin.get();
	cout << "OS: ";
	cin.getline(this->OS, 20);
}