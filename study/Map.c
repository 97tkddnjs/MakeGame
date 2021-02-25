#include "Map.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include<conio.h>

void map_clear(MData (*arr)[MAP_SIZE])
{
	int i, j;
	for (i = 0; i < MAP_SIZE; i++)
	{
		for (j = 0; j < MAP_SIZE; j++)
		{
			arr[i][j] = EMPTY;
		}
	}
}
void draw_map(MData(*arr)[MAP_SIZE])
{
	int i;
	for (i = 0; i < MAP_SIZE - 1; i++)
	{
		arr[i][0] = WALL;
		arr[MAP_SIZE - 1][i] = WALL;
		arr[MAP_SIZE - 1 - i][MAP_SIZE - 1] = WALL;
		arr[0][MAP_SIZE - 1 - i] = WALL;
	}
}
//draw game map
void gotoxy(int x, int y)	//C,C++���� �ܼ�ȭ�鿡 Ŀ���� ���ϴ� ��ġ�� �̵��Ͽ� �ش���ġ�� ���� ����ϴ� ���
{
	COORD pos = { x,y };
	/* �ܼ� ȭ�� ���ۿ� ���� ��ǥ�� �������ִ� ����ü (0,0)�� ���� ���� ����� ��
	typedef struct _COORD{
		SHORT X; // ���� ��ǥ�� ���� �� ������ �Լ� ȣ�⿡ ���� �޶���
		SHORT Y; // ���� ��ǥ�� ���� �� ������ �Լ� ȣ�⿡ ���� �޶���

	}COORD, *PCOORD;
	*/
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//���ϴ� ��ġ�� �̵������ִ� �Լ�
	//STD_OUTPUT_HANDLE ǥ�� ��� ����̽� Ȱ�� �ܼ� ȭ�� ����
}

void drawMainMap(MData (*map)[MAP_SIZE]) {
	HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hand, 15);

	int i, j;
	for (i = 0; i < MAP_SIZE; i++) {
		for (j = 0; j < MAP_SIZE; j++) {
			if (map[i][j] == WALL) {
				gotoxy(i, j);
				printf("#");
			}
			else if (map[i][j] == EMPTY) {
				gotoxy(i, j);
				printf(" ");
			}
		}
	}
	SetConsoleTextAttribute(hand, 7);
}
