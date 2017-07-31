#include<iostream>
#include<string>
#include"armor.h"
#include"item.h"

using namespace std;

Armor::Armor(string Name, string Description, int Weight, int Value, int Defense)
	:Item(Name, Description, Weight, Value), defense(Defense) {} // 초기화 섹션

void Armor::Describe()
{	
	Item::Describe();
	cout << "defense     = " << defense << endl;
	cout << endl;
}