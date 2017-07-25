#include"item.h"
#include"weapon.h"
#include"armor.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{
	Weapon b("°Ë", "Ä®ÀÌ´Ù", 5, 5, 5);
	b.Describe();

	Armor c("°©¿Ê", "Æ°Æ°ÇÏ´Ù", 5, 5, 5);
	c.Describe();
}




