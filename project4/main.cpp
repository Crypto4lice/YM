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
		char cstr[150]; // 파일에서 한줄 읽어올 때 이 배열에 저장
		char copy[150]; // 스트링 짜르기 위해 필요한 복사본 
		int i;
		int j = 0;		// 스트링 짜를때 필요한 친구
		int flag = 0;   // 짜른 스트링이 어느 맵으로 들어갈 지 결정함
		ips.getline(cstr, 150);

		for (i = 0; i < 150; i++)
		{
			copy[j] = cstr[i];   // 사본을 만듭니다

			if (cstr[i] == '\t') // 탭 문자를 만나면
			{
				copy[j] = '\0';  // cstr[i]에는 탭문자가 있음 -> copy[j]에도 탭문자가 있는데 그것을 널문자로 치환하면 짜를수 있음
				if (flag == 0)
				{
					firstname[h] = copy; // h가 키인 곳에 copy라는 스트링을 저장
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
				j = -1; // 여기서 -1로 선언을 해두면 마지막에 j++와 만나서 for문의 처음으로 돌아갈땐 j가 0 인 상태가 됨
			}
			else if (cstr[i] == '\0') // 널 문자를 만난 경우 -> 그 줄의 끝을 만난 경우임 -> 이 때 플래그의 값으로 알맞는 위치에 저장이 가능
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
				break; // 널 문자를 만난 경우 150번 쓸데 없이 반복문을 안돌리고 탈출시켜줌
			}
			j++;
		}
		h++;
	}

	string input;
	cout << "Enter a search string : ";
	cin >> input;
	
	map<int, string>::iterator iter = firstname.begin(); // 키값대로 처음부터 시작함니다
	map<int, string>::iterator iter1 = lastname.begin();
	
	while (iter != firstname.end()) // 마지막 키값때까지 돌린다
	{		
		if ((iter->second).find(input) != string::npos) // firstname에서 탐색 성공 (find 함수는 탐색 실패시 string::npos를 반환)
		{		
			if (iter->first != 1) 
				cout << iter->second << " " << lastname[iter->first] << " " << position[iter->first] << " " << separation_date[iter->first] << endl;
		}
		else
		{							
			if ((iter1->second).find(input) != string::npos) // lastname에서 탐색 성공
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

