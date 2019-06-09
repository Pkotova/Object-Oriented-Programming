// Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include"Catalog.h"
#include"TextFile.h"
#include"File.h"
#include <iostream>
#include <queue>
using namespace std;

void collectNames(const string& path, vector<string>& names)
{
	string name;
	for (size_t i = 0; i < path.size(); i++)
	{
		if (path[i] == NULL)
		{
			names.push_back(name);
			return;
		}
		if (path[i] == '/')
		{
			names.push_back(name);
			name.clear();
		}
		else
		{
			name.push_back(path[i]);
		}
	}
}

int main()
{
	Catalog root("oop");

	Catalog sub("hw");

	sub.addFile(TextFile("vector", "#include <vector>"));

	sub.addFile(TextFile("filesystem", "TODO"));

	root.addFile(TextFile("test1", "web server"));

	root.addFile(TextFile("test2", "... as if"));
	root.addFile(sub);

	std::cout << sub.size() << std::endl;
	std::cout << root.size() << std::endl;

	root.print();
	std::cout << std::endl;
}

