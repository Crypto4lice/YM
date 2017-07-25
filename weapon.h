#pragma once
#include"item.h"
#include<iostream>
#include<string>

using namespace std;

class Weapon : public Item
{
public:
	Weapon();
	Weapon(string Name, string Description, int Weight, int Value, int Damage);
	void Describe();
private:
	int damage;
};