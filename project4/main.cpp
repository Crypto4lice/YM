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
		char cstr[150]; // ���Ͽ��� ���� �о�� �� �� �迭�� ����
		char copy[150]; // ��Ʈ�� ¥���� ���� �ʿ��� ���纻 
		int i;
		int j = 0;		// ��Ʈ�� ¥���� �ʿ��� ģ��
		int flag = 0;   // ¥�� ��Ʈ���� ��� ������ �� �� ������
		ips.getline(cstr, 150);

		for (i = 0; i < 150; i++)
		{
			copy[j] = cstr[i];   // �纻�� ����ϴ�

			if (cstr[i] == '\t') // �� ���ڸ� ������
			{
				copy[j] = '\0';  // cstr[i]���� �ǹ��ڰ� ���� -> copy[j]���� �ǹ��ڰ� �ִµ� �װ��� �ι��ڷ� ġȯ�ϸ� ¥���� ����
				if (flag == 0)
				{
					firstname[h] = copy; // h�� Ű�� ���� copy��� ��Ʈ���� ����
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
				j = -1; // ���⼭ -1�� ������ �صθ� �������� j++�� ������ for���� ó������ ���ư��� j�� 0 �� ���°� ��
			}
			else if (cstr[i] == '\0') // �� ���ڸ� ���� ��� -> �� ���� ���� ���� ����� -> �� �� �÷����� ������ �˸´� ��ġ�� ������ ����
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
				break; // �� ���ڸ� ���� ��� 150�� ���� ���� �ݺ����� �ȵ����� Ż�������
			}
			j++;
		}
		h++;
	}

	string input;
	cout << "Enter a search string : ";
	cin >> input;
	
	map<int, string>::iterator iter = firstname.begin(); // Ű����� ó������ �����Դϴ�
	map<int, string>::iterator iter1 = lastname.begin();
	
	while (iter != firstname.end()) // ������ Ű�������� ������
	{		
		if ((iter->second).find(input) != string::npos) // firstname���� Ž�� ���� (find �Լ��� Ž�� ���н� string::npos�� ��ȯ)
		{		
			if (iter->first != 1) 
				cout << iter->second << " " << lastname[iter->first] << " " << position[iter->first] << " " << separation_date[iter->first] << endl;
		}
		else
		{							
			if ((iter1->second).find(input) != string::npos) // lastname���� Ž�� ����
			{
				if (iter->first != 1)
					cout << firstname[iter1->first] << " " << iter1->second << " " << position[iter1->first] << " " << separation_date[iter1->first] << endl;
			}			
		}
		iter++;	
		iter1++;
	}		
	return 0;
}

