#include<iostream>
#include<fstream>
#include<string>
#include<map>

using namespace std;

int main()
{
	map<int,string> firstname;
	map<int,string> lastname;
	map<int,string> position;
	map<int,string> separation_date;

	ifstream ips("abc.txt");
	
	int h = 1;

	while (!ips.eof())
	{
		char cstr[150];
		char copy[150];
		int i;
		int j = 0;		
		int flag = 0;
		ips.getline(cstr, 150);

		for (i = 0; i < 150; i++)
		{
			copy[j] = cstr[i];

			if (cstr[i] == '\t')
			{
				copy[j] = '\0';
				if (flag == 0)
				{
					firstname[h] = copy;
					flag++;
				}
				else if (flag == 1)
				{
					lastname[h] = copy;
					flag++;
				}
				else if (flag == 2)
				{
					position[h] = copy;
					flag++;
				}
				else
				{
					separation_date[h] = copy;
				}
				j = -1;
			}
			else if (cstr[i] == '\0')
			{
				if (flag == 0)
				{
					firstname[h] = copy;
				}
				else if (flag == 1)
				{
					lastname[h] = copy;
					flag = 0;
				}
				else if (flag == 2)
				{
					position[h] = copy;
					flag = 0;
				}
				else
				{
					separation_date[h] = copy;
					flag = 0;
				}
				break;
			}
			j++;
		}
		h++;
	}

	string input;
	cout << "Enter a search string : ";
	cin >> input;
	
	map<int, string>::iterator iter = firstname.begin();
	map<int, string>::iterator iter1 = lastname.begin();
	
	while (iter != firstname.end())
	{		
		if ((iter->second).find(input) != string::npos) // 탐색 실패시 string::npos를 반환
		{						
			cout << iter->second << " " << lastname[iter->first] << " " << position[iter->first] << " " << separation_date[iter->first] << endl;
		}
		else
		{							
			if ((iter1->second).find(input) != string::npos)
			{
				cout << firstname[iter1->first] << " " << iter1->second << " " << position[iter1->first] << " " << separation_date[iter1->first] << endl;
			}			
		}
		iter++;	
		iter1++;
	}		
	return 0;
}

