#pragma once
#include"File.h"
class Catalog : public File
{
private:
	File** files;
	
	int length;
	int capacity;

	void resizeUp();
	void destroy();
	void copy(const Catalog&);
public:
	Catalog();
	Catalog(const char*);
	Catalog(const Catalog&);
	Catalog& operator=(const Catalog&);
	void addFile(const File&);
	bool isFull()const;

	Catalog* clone() const;
	
	int size()const;
	void print()const;

	~Catalog();
};

