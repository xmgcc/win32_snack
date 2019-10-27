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

//宽度
#define WIDE 60
//高度
#define HIGH 20

//坐标结构体
struct Position
{
	int X;
	int Y;
};

typedef struct
{
	struct Position pos[WIDE*HIGH];//坐标
	int size;//长度
}SNAKE;

typedef struct
{
	struct Position pos;
}FOOD;

enum MyEnum
{
	UP='W',DOWN='S',LEFT='A',RIGHT='D'
};
//定义全局变量
SNAKE snake;
FOOD food;
int score = 0;
//获取尾巴坐标
int tx = 0;
int ty = 0;

//初始化蛇的信息
void SnakeInit()
{
	snake.size = 2;
	snake.pos[0].X = WIDE / 2;
	snake.pos[0].Y = HIGH / 2;

	snake.pos[1].X = WIDE / 2 - 1;
	snake.pos[1].Y = HIGH / 2;
}

//初始化食物的信息
void FoodInit()
{
	food.pos.X = rand() % WIDE;
	food.pos.Y = rand() % HIGH;
}

//初始化地图信息
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

//显示游戏界面
void ShowUI()
{
	COORD  coord;
	//去掉重影
	coord.X = tx;
	coord.Y = ty;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');
	//打印蛇的信息
	for (int i = 0; i < snake.size; i++)
	{
		coord.X = snake.pos[i].X;
		coord.Y = snake.pos[i].Y;
		//设置控制台光标位置
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		if (i == 0)
			putchar('@');
		else
			putchar('*');
	}

	//打印食物信息

	coord.X = food.pos.X;
	coord.Y = food.pos.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('#');

	
}

//开始游戏
void PlayGame()
{
	//蛇移动偏移量
	int i;
	int dx = 0;
	int dy = 0;
	char key = 'D';
	//蛇和墙的碰撞检测
	while (snake.pos[0].X >= 0 && snake.pos[0].X < WIDE 
		&& snake.pos[0].Y >= 0 && snake.pos[0].Y < HIGH)
	{
		
		//蛇和身体的碰撞检测
		for (i = 1; i < snake.size; i++)
		{
			if (snake.pos[0].X == snake.pos[i].X && snake.pos[0].Y == snake.pos[i].Y)
			{
				return;
			}
		}

		//蛇和食物的碰撞检测
		if (snake.pos[0].X == food.pos.X && snake.pos[0].Y == food.pos.Y)
		{
			//随机新食物
			FoodInit();
			//蛇身体增长
			snake.size++;
			//分数增长
			score += 10;


		}

		//控制蛇的移动
		//_kbhit 判断键盘是否有输入 如果有结束数据
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

		//记录尾巴坐标
		tx = snake.pos[snake.size - 1].X;
		ty = snake.pos[snake.size - 1].Y;

		//改变蛇的坐标
		for (i = snake.size - 1; i > 0; i--)
		{
			//用前一个身体坐标位当前身体坐标赋值
			snake.pos[i].X = snake.pos[i - 1].X;
			snake.pos[i].Y = snake.pos[i - 1].Y;
		}
		//改变蛇头坐标
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

	//去掉控制台光标
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE;
	cci.dwSize = sizeof(cci);
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);


	//初始化蛇的信息
	SnakeInit();

	//初始化食物的信息
	FoodInit();
	//初始化地图的信息
	MapInit();
	//显示蛇和食物的信息
	//ShowUI();
	PlayGame();
	system("cls");
	printf("游戏结束\n分数：%d\n", score);
	return EXIT_SUCCESS;
}

