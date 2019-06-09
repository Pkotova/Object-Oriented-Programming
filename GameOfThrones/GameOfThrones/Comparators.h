#pragma once
#include"Character.h"

bool isEldest(const Character& c1, const Character& c2)
{
	return c1.getAge() > c2.getAge();
}

bool isBest(const Character& c1, const Character& c2)
{
	return (c1.getScore() > c2.getScore());
}

bool byName(const Character& c1, const Character& c2)
{
	return (strcmp(c1.getFullName(), c2.getFullName()) > 0);
}

bool byScore(const Character& c1, const Character& c2)
{
	return (c1.getScore() > c2.getScore());
}

bool byAge(const Character& c1, const Character& c2)
{
	return (c1.getAge() > c2.getAge());
}