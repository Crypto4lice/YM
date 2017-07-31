#include"item.h"
#include<iostream>
#include<string>

using namespace std;

Item::Item(string Name, string Description, int Weight, int Value)
{
	name = Name;
	description = Description;
	weight = Weight;
	value = Value;
}

void Item::Describe()
{
	cout << "Name        = " << name << endl;
	cout << "Description = " << description << endl;
	cout << "Weight      = " << weight << " lbs" << endl;
	cout << "Value       = " << value << " gold coin" << endl;	
}

