#pragma once
#include"item.h"
#include<iostream>
#include<string>

using namespace std;

class Armor : public Item
{
public:
	Armor();
	Armor(string Name, string Description, int Weight, int Value, int Defense);
	void Describe();
private:
	int defense;
};