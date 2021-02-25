#include "Map.h"
#include <stdio.h>
#include <Windows.h>
#include<string.h>
#include <conio.h>
/*
	conio.h =>console and port I/O 약자 윈도우즈에서만 쓸 수 있는 비표준함수들
	int _kbhit()	// keyboard hit의 약자 버퍼에 값이 있으면 1 없으면 0 return
	int _getch()	// 값을 입력할 때까지 대기했다가 값이 들어오면 버퍼에 저장했다가 버퍼에서
						꺼내서 리턴한다 확장 키들은  getch()를 한번더 호출하면 알 수 있다.
		ch = _getch();
		if(_kbhit())
		{
			ch = _getch();
		}
*/





// 깜빡거리는 커서를 보이지 않게 하는 함수
void hidecursor() {
	//	HANDLE 내가 직접 운영체재 접근 위험 API로 확인
	//	김성엽님 블로그 내용  https://blog.naver.com/tipsware/221065382244
	HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);	//지정된 표준 디바이스에 대한 핸들을 검색
	CONSOLE_CURSOR_INFO info;
	/*
	typedef struct _CONSOLE_CURSOR_INFO {
		DWORD dwSize;		// 커서에 의해 채워지는 문자셀의 백분율 1~100사이 커서 사이즈 의미하는 듯
		BOOL  bVisible;		//커서의 표시 여부 커서가 표시되는 경우 값은 TRUE
	} CONSOLE_CURSOR_INFO, *PCONSOLE_CURSOR_INFO;
	*/
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandler, &info);
}
void draw() {
	HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
	enum {
		BLACK, /* 0 : 검은색 */
		DARK_BLUE, /* 1 : 어두운 파랑 */
		DARK_GREEN, /* 2 : 어두운 초록 */
		DARK_SKY_BLUE, /* 3 : 어두운 하늘 */
		DARK_RED, /* 4 : 어두운 빨강 */
		DARK_VOILET, /* 5 : 어두운 보라 */
		DARK_YELLOW, /* 6 : 어두운 노랑 */
		GRAY, /* 7 : 회색 */
		DARK_GRAY, /* 8 : 어두운 회색 */
		BLUE, /* 9 : 파랑 */
		GREEN, /* 10 : 초록 */
		SKY_BLUE, /* 11 : 하늘 */
		RED, /* 12 : 빨강 */
		VIOLET, /* 13 : 보라 */
		YELLOW, /* 14 : 노랑 */
		WHITE, /* 15 : 하얀색 */
	};
	SetConsoleTextAttribute(hand, SKY_BLUE);	
	// 색을 칠해주는 함수 첫번쨰 인자 현재 핸들 뒤에는 색깔(numbering)
	
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

			Sleep(10); //Sleep(1000) 1초를 이야기함 100은 0.1초임 10은 0.01
			//system("cls"); // 스크린을 깨끗이 비워라!!! 
			//system() cmd 창에 명령어를 직접 쓰는 효과와 동일

		}

	}
	/*
	gotoxy(5, 6);
	draw();//하얀색으로 칠해줄 것임
	printf("***");
	*/
	
}
