#pragma once
#include"Character.h"
class House
{
private:

	char* name;
	char* location;
	char* houseWords;
	Character** team;

	int size;
	int capacity;

	void resizeUp();
	void resizeDown();

	void copy(const House&);
	void destroy();

public:
	House();
	House(const char*, const char*, const char*);
	House(const House&);
	House& operator=(const House&);
	~House();

	void setName(const char*);
	void setLocation(const char*);
	void setHouseWords(const char*);

	char* getName()const;
	char* getLocation()const;
	char* getHouseWords()const;

	int getSize()const;
	int getCapacity()const;

	bool hasCharacter(const char* )const;
	bool isFull()const;
	void add(const Character&);
	void remove(const Character&); 
	
	void srinkShow()const;
	void showTeam()const;
	int getTotalScore()const;

	Character& getExtreme(bool(*comparator)(const Character&, const Character&));
	void sort(bool(*comparator)(const Character&, const Character&));
};

