#include"item.h"
#include"weapon.h"
#include"armor.h"
#include<iostream>
#include<string>

using namespace std;

int main()
{
	Weapon b("��", "Į�̴�", 5, 5, 5);
	b.Describe();

	Armor c("����", "ưư�ϴ�", 5, 5, 5);
	c.Describe();
}




