#pragma once
#include"File.h"
class TextFile : public File
{
	char* content;
public:
	TextFile();
	TextFile(const TextFile&);
	TextFile& operator=(const TextFile&);
	TextFile(const char*,const char*);

	void addContent(const char*);
	char* getContent() const;

	//TextFile** get() const;
	TextFile* clone() const;

	int size()const;
	void print()const;


	bool operator==(const TextFile&);

	~TextFile();

};

