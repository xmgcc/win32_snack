// t.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

//���
#define WIDE 60
//�߶�
#define HIGH 20

//����ṹ��
struct Position
{
	int X;
	int Y;
};

typedef struct
{
	struct Position pos[WIDE*HIGH];//����
	int size;//����
}SNAKE;

typedef struct
{
	struct Position pos;
}FOOD;

enum MyEnum
{
	UP='W',DOWN='S',LEFT='A',RIGHT='D'
};
//����ȫ�ֱ���
SNAKE snake;
FOOD food;
int score = 0;
//��ȡβ������
int tx = 0;
int ty = 0;

//��ʼ���ߵ���Ϣ
void SnakeInit()
{
	snake.size = 2;
	snake.pos[0].X = WIDE / 2;
	snake.pos[0].Y = HIGH / 2;

	snake.pos[1].X = WIDE / 2 - 1;
	snake.pos[1].Y = HIGH / 2;
}

//��ʼ��ʳ�����Ϣ
void FoodInit()
{
	food.pos.X = rand() % WIDE;
	food.pos.Y = rand() % HIGH;
}

//��ʼ����ͼ��Ϣ
void MapInit()
{
	for (int i = 0; i <= HIGH; i++)
	{
		for (int j = 0; j <= WIDE; j++)
		{
			
			if (i == HIGH && j == WIDE)
			{
				printf("+");
			}
			else if (j == WIDE)
			{
				printf("|");
			}else if (i == HIGH)
			{
				printf("-");
			}
			else
			{
				printf(" ");
			}

		}
		printf("\n");
	}
}

//��ʾ��Ϸ����
void ShowUI()
{
	COORD  coord;
	//ȥ����Ӱ
	coord.X = tx;
	coord.Y = ty;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');
	//��ӡ�ߵ���Ϣ
	for (int i = 0; i < snake.size; i++)
	{
		coord.X = snake.pos[i].X;
		coord.Y = snake.pos[i].Y;
		//���ÿ���̨���λ��
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		if (i == 0)
			putchar('@');
		else
			putchar('*');
	}

	//��ӡʳ����Ϣ

	coord.X = food.pos.X;
	coord.Y = food.pos.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('#');

	
}

//��ʼ��Ϸ
void PlayGame()
{
	//���ƶ�ƫ����
	int i;
	int dx = 0;
	int dy = 0;
	char key = 'D';
	//�ߺ�ǽ����ײ���
	while (snake.pos[0].X >= 0 && snake.pos[0].X < WIDE 
		&& snake.pos[0].Y >= 0 && snake.pos[0].Y < HIGH)
	{
		
		//�ߺ��������ײ���
		for (i = 1; i < snake.size; i++)
		{
			if (snake.pos[0].X == snake.pos[i].X && snake.pos[0].Y == snake.pos[i].Y)
			{
				return;
			}
		}

		//�ߺ�ʳ�����ײ���
		if (snake.pos[0].X == food.pos.X && snake.pos[0].Y == food.pos.Y)
		{
			//�����ʳ��
			FoodInit();
			//����������
			snake.size++;
			//��������
			score += 10;


		}

		//�����ߵ��ƶ�
		//_kbhit �жϼ����Ƿ������� ����н�������
		if (_kbhit())
		{
			key = _getch();
		}
		switch (key)
		{
		case UP:
			dx = 0;
			dy = -1;
			break;
		case DOWN:
			dx = 0;
			dy = 1;
			break;
		case LEFT:
			dx = -1;
			dy = 0;
			break;
		case RIGHT:
			dx = 1;
			dy = 0;
			break;
		}

		//��¼β������
		tx = snake.pos[snake.size - 1].X;
		ty = snake.pos[snake.size - 1].Y;

		//�ı��ߵ�����
		for (i = snake.size - 1; i > 0; i--)
		{
			//��ǰһ����������λ��ǰ�������긳ֵ
			snake.pos[i].X = snake.pos[i - 1].X;
			snake.pos[i].Y = snake.pos[i - 1].Y;
		}
		//�ı���ͷ����
		snake.pos[0].X += dx;
		snake.pos[0].Y += dy;

		//system("cls");
		//MapInit();
		ShowUI();
		Sleep(200);
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	//ȥ������̨���
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE;
	cci.dwSize = sizeof(cci);
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);


	//��ʼ���ߵ���Ϣ
	SnakeInit();

	//��ʼ��ʳ�����Ϣ
	FoodInit();
	//��ʼ����ͼ����Ϣ
	MapInit();
	//��ʾ�ߺ�ʳ�����Ϣ
	//ShowUI();
	PlayGame();
	system("cls");
	printf("��Ϸ����\n������%d\n", score);
	return EXIT_SUCCESS;
}

