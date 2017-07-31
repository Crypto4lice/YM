#include<iostream>
#include<cstdlib>
#include<ctime>
#include<process.h>

using namespace std;

char field[20][20]; 

void print_screen(int NUM);

int main()
{
	int player = 0; // 캐릭터 수
	int squirrel = 0; // 다람쥐 수
	int row, col; // 행과 열
	int x, y; // rand 함수에서 사용하는 변수
	int N; // 게임 화면 크기
	char INPUT; // 입력받은 문자

	cout << "필드 크기 입력 : ";
	cin >> N; // 첫줄에 게임화면크기 N 입력받음

	for (row = 0; row < N; row++)
	{		
		for (col = 0; col < N; col++)
		{
			cin >> INPUT;

			if (INPUT == '.' || INPUT == 'D' || INPUT == 'C')
			{
				field[row][col] = INPUT;
			}
			else
			{
				cout << ".이나 D나 C이외에 다른 것 입력 불가" << endl;
				exit(1);
			}				

			if (INPUT == 'D') // 다람쥐 개수 저장
				squirrel++;
			else if (INPUT == 'C') // 캐릭터 개수 저장
				player++;
		}
	}

	cout << endl << "결과" << endl;

	if (player == 0 || (player * 2 <= squirrel)) // 플레이어가 없거나 충분히 다람쥐가 있는 경우 바로 출력
		print_screen(N);

	else // 다람쥐가 모자랄 때 -> 캐릭터 수 X 2 가 다람쥐 수 보다 큰 경우
	{
		while (player * 2 > squirrel)
		{
			srand(time(NULL));
			x = rand() % N;
			y = rand() % N;

			if (field[x][y] == '.') // 공백 필드인 경우에만 다람쥐를 생성 
			{
				field[x][y] = 'D';
				squirrel++;
			}
		}
		print_screen(N);
	}	
}

void print_screen(int NUM)
{
	int ROW, COL;

	for (ROW = 0; ROW < NUM; ROW++)
	{
		for (COL = 0; COL < NUM; COL++)
		{
			cout << field[ROW][COL];
		}
		cout << endl;
	}
}


