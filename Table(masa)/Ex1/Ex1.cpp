// Ex1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct Table {
	char material[32];
	double height;
	double weight;
};
void input(Table* tables, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << "table" << endl;
		cin.ignore();
		cin.getline(tables[i].material, 32);
		cin >> tables[i].height;
		cin >> tables[i].weight;
	}
}
void output(Table * tables, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << tables[i].material << endl;
		cout << tables[i].height << endl;
		cout << tables[i].weight << endl;
	}
}
void outputSingle(Table table)
{
	    cout << table.material << endl;
		cout << table.height << endl;
		cout << table.weight << endl;

}
Table  maxHeight(Table * tables, int size)
{
	double max = tables[0].height;
	Table currentTable = tables[0];
	for (size_t i = 0; i < size; i++)
	{
		if (tables[i].height > max)
		{
			max = tables[i].height;
			currentTable = tables[i];
		}
	}
	return currentTable;
}
void outputWood(Table * tables, int size)
{
	char wood[] = "wood";
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(tables[i].material,wood)==0)
		{
			outputSingle(tables[i]);
		}
	}
}
void sortWeight(Table * tables, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0 ; j < size- i -1; j++)
		{
			if (tables[j].weight < tables[j+1].weight)
			{
				swap(tables[j + 1], tables[j]);
			}
		}
	}
}
int main()
{
	Table tables[2];
	input(tables, 2);
	Table maxTable = maxHeight(tables, 2);
	cout << "_____________________" << endl;
	//outputSingle(maxTable);
	cout << "_____________________" << endl;
	//outputWood(tables, 3);
	cout << "Sorterd by weight" << endl;
	sortWeight(tables, 2);
	output(tables, 2 );

    return 0;
}

