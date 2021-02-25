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
void gotoxy(int x, int y)	//C,C++에서 콘솔화면에 커서를 원하는 위치로 이동하여 해당위치에 문자 출력하는 방법
{
	COORD pos = { x,y };
	/* 콘솔 화면 버퍼에 셀의 좌표를 정의해주는 구조체 (0,0)은 버퍼 왼쪽 상단의 셀
	typedef struct _COORD{
		SHORT X; // 수평 좌표나 열의 값 단위는 함수 호출에 따라 달라짐
		SHORT Y; // 수직 좌표나 행의 값 단위는 함수 호출에 따라 달라짐

	}COORD, *PCOORD;
	*/
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//원하는 위치로 이동시켜주는 함수
	//STD_OUTPUT_HANDLE 표준 출력 디바이스 활성 콘솔 화면 버퍼
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
