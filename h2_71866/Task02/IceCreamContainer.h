#pragma once
#include "IceCream.h"
class IceCreamContainer
{
private:
	IceCream * iceCreams;
	int size;
	int capacity;

	void resizeUp();
	void resizeDown();

	void copy(const IceCreamContainer&);
	void destroy();
public:
	IceCreamContainer();
	IceCreamContainer(const IceCreamContainer&);
	IceCreamContainer& operator=(const IceCreamContainer&);
	IceCreamContainer(IceCream*, const int&, const int&);
	~IceCreamContainer();

	void setSize(const int&);
	int getSize()const;

	void setCapacity(const int&);
	int getCapacity()const;

	void add(const IceCream&);
	void remove(const int&);

	IceCream* getIceCreams()const;

	friend ostream& operator<<(ostream&, const IceCreamContainer&);
	friend istream& operator>>(istream&, IceCreamContainer&);

	bool has(const IceCream&);
	double report();
};

