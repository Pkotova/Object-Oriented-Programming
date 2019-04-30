#pragma once

class Branch {
private:
	char* location;
	int id;
	int workCoeff;
public:
	char* getLocation() const;
	int getId() const;
	int getWorkCoeff() const;

	void setLocation(const char*);
	void setId(const int&);
	void setWorkCoeff(const int&);

	Branch();
	Branch(const char*, const int&, const int&);
	Branch(const Branch&);

	Branch& operator=(const Branch&);

	Branch& operator++();
	Branch& operator++(int);
	~Branch();

};

