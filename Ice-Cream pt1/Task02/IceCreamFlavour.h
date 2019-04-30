#pragma once
#include<cstring>

struct IceCreamFlavour
{
	char flavourName[32];
	double pricePerBall;

	IceCreamFlavour(const char* flavourName = "default flavour", double pricePerBall = 0.0)
	{
		strcpy_s(this->flavourName, strlen(flavourName) + 1, flavourName);
		this->pricePerBall = pricePerBall;
	}
};
