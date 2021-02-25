#include "Map.h"
#include <stdio.h>
#include <Windows.h>
#include<string.h>
#include <conio.h>
/*
	conio.h =>console and port I/O ���� ����������� �� �� �ִ� ��ǥ���Լ���
	int _kbhit()	// keyboard hit�� ���� ���ۿ� ���� ������ 1 ������ 0 return
	int _getch()	// ���� �Է��� ������ ����ߴٰ� ���� ������ ���ۿ� �����ߴٰ� ���ۿ���
						������ �����Ѵ� Ȯ�� Ű����  getch()�� �ѹ��� ȣ���ϸ� �� �� �ִ�.
		ch = _getch();
		if(_kbhit())
		{
			ch = _getch();
		}
*/





// �����Ÿ��� Ŀ���� ������ �ʰ� �ϴ� �Լ�
void hidecursor() {
	//	HANDLE ���� ���� �ü�� ���� ���� API�� Ȯ��
	//	�輺���� ��α� ����  https://blog.naver.com/tipsware/221065382244
	HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);	//������ ǥ�� ����̽��� ���� �ڵ��� �˻�
	CONSOLE_CURSOR_INFO info;
	/*
	typedef struct _CONSOLE_CURSOR_INFO {
		DWORD dwSize;		// Ŀ���� ���� ä������ ���ڼ��� ����� 1~100���� Ŀ�� ������ �ǹ��ϴ� ��
		BOOL  bVisible;		//Ŀ���� ǥ�� ���� Ŀ���� ǥ�õǴ� ��� ���� TRUE
	} CONSOLE_CURSOR_INFO, *PCONSOLE_CURSOR_INFO;
	*/
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandler, &info);
}
void draw() {
	HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
	enum {
		BLACK, /* 0 : ������ */
		DARK_BLUE, /* 1 : ��ο� �Ķ� */
		DARK_GREEN, /* 2 : ��ο� �ʷ� */
		DARK_SKY_BLUE, /* 3 : ��ο� �ϴ� */
		DARK_RED, /* 4 : ��ο� ���� */
		DARK_VOILET, /* 5 : ��ο� ���� */
		DARK_YELLOW, /* 6 : ��ο� ��� */
		GRAY, /* 7 : ȸ�� */
		DARK_GRAY, /* 8 : ��ο� ȸ�� */
		BLUE, /* 9 : �Ķ� */
		GREEN, /* 10 : �ʷ� */
		SKY_BLUE, /* 11 : �ϴ� */
		RED, /* 12 : ���� */
		VIOLET, /* 13 : ���� */
		YELLOW, /* 14 : ��� */
		WHITE, /* 15 : �Ͼ�� */
	};
	SetConsoleTextAttribute(hand, SKY_BLUE);	
	// ���� ĥ���ִ� �Լ� ù���� ���� ���� �ڵ� �ڿ��� ����(numbering)
	
}
int main()
{
	int x = 1, y = 1;
	int ch;
	//printf("if you want to end press \"p\"");
	int arr[MAP_SIZE][MAP_SIZE];

	map_clear(arr);
	draw_map(arr);
	

	while (1)
	{
		drawMainMap(arr);
		
		gotoxy(x, y);
		printf("***");
		hidecursor();
		if (_kbhit())
		{
			ch = _getch();
			switch (ch)
			{
			case 72:  //up
				gotoxy(x, y);
				printf("   ");
				y--;
				break;
			case 75:	//left
				gotoxy(x, y);
				printf("   ");
				x--;
				break;
			case 77:	//right
				gotoxy(x, y);
				printf("   ");
				x++;
				break;
			case 80:	//down
				gotoxy(x, y);
				printf("   ");
				y++;
				break;
			case 'p':
				printf("end~~~");
				return 0;
			}
			//getchar();

			Sleep(10); //Sleep(1000) 1�ʸ� �̾߱��� 100�� 0.1���� 10�� 0.01
			//system("cls"); // ��ũ���� ������ �����!!! 
			//system() cmd â�� ��ɾ ���� ���� ȿ���� ����

		}

	}
	/*
	gotoxy(5, 6);
	draw();//�Ͼ������ ĥ���� ����
	printf("***");
	*/
	
}
