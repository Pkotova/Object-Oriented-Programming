// Accounts Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include"Account.h"
#include"GroupAccount.h"
#include"UserAccount.h"
int main()
{
	while (1) {
		//Storage e izlishna trqbva da se doizbarva

		UserAccount u1, u2("Zdr@abv", true);
		//u1.showInfo();
		GroupAccount g1, g2;
		g1.add(u1);
		g1.add(u2);
		g1.add(g1);
		//g1.remove(u1);
		g1.showInfo();
	}
}