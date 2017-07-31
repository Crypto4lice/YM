#include<iostream>
#include<cstdlib>
#include<ctime>
#include<process.h>

using namespace std;

char field[20][20]; 

void print_screen(int NUM);

int main()
{
	int player = 0; // ĳ���� ��
	int squirrel = 0; // �ٶ��� ��
	int row, col; // ��� ��
	int x, y; // rand �Լ����� ����ϴ� ����
	int N; // ���� ȭ�� ũ��
	char INPUT; // �Է¹��� ����

	cout << "�ʵ� ũ�� �Է� : ";
	cin >> N; // ù�ٿ� ����ȭ��ũ�� N �Է¹���

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
				cout << ".�̳� D�� C�̿ܿ� �ٸ� �� �Է� �Ұ�" << endl;
				exit(1);
			}				

			if (INPUT == 'D') // �ٶ��� ���� ����
				squirrel++;
			else if (INPUT == 'C') // ĳ���� ���� ����
				player++;
		}
	}

	cout << endl << "���" << endl;

	if (player == 0 || (player * 2 <= squirrel)) // �÷��̾ ���ų� ����� �ٶ��㰡 �ִ� ��� �ٷ� ���
		print_screen(N);

	else // �ٶ��㰡 ���ڶ� �� -> ĳ���� �� X 2 �� �ٶ��� �� ���� ū ���
	{
		while (player * 2 > squirrel)
		{
			srand(time(NULL));
			x = rand() % N;
			y = rand() % N;

			if (field[x][y] == '.') // ���� �ʵ��� ��쿡�� �ٶ��㸦 ���� 
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


