#pragma once
struct WebServer
{
private:
	char URL[500];
	int IPv4Address[4];
	char OS[20];

public:												//po delault sa si public
	WebServer();
	WebServer(const char[500], const int[4], const char[20]);
	~WebServer();

	void setURL(const char[500]);
	char* getURL() ;

	void setIP(const int[4]);
	int* getIP() ;

	void setOS(const char[20]);
	char* getOS();

	bool operator<(const WebServer&);
	bool operator==(const WebServer&);
	bool operator==(const int[4]);
	bool operator^=(const WebServer&);
	void print() const;
	void read();
};

