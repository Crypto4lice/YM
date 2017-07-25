#include<iostream>
#include<string>
#include"weapon.h"
#include"item.h"

using namespace std;

Weapon::Weapon(string Name, string Description, int Weight, int Value, int Damage)
	:Item(Name, Description, Weight, Value), damage(Damage) {} // 초기화 섹션

void Weapon::Describe()
{
	Item::Describe();
	cout << "damage      = " << damage << endl;
	cout << endl;
}
