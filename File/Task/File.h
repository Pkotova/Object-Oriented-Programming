#pragma once
class File
{
protected:
	char* name;
	//double size;
public:
	File();
	File(const File&);
	File& operator=(const File&);
	File(const char*);

	//virtual File** get() const = 0;
	virtual File* clone() const = 0;

	void setName(const char*);
	char* getName()const;
	virtual int size()const = 0;
	virtual void print()const = 0;


	virtual ~File();
};

