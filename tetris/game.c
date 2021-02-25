#include "util.h"
#include "game.h"

void titleDraw()
{
	printf("\n\n\n\n");
	printf("        ####    ###   ###     #      ####   ####\n");
	printf("        #      #     #       # #     #  #   #   \n");
	printf("        ####   ####  #      #####    ####   ####\n");
	printf("        #         #  #     #     #   #      #   \n");
	printf("        ####   ####   ###  #     #   #      ####\n");
}

int menuDraw() {

	int x = 24;
	int y = 12;

	gotoxy(x - 2, y); // -2를 한 이유는 >출력을 위해서
	printf("> 게 임 시 작");
	gotoxy(x, y + 1);
	printf("게 임 정 보");
	gotoxy(x, y + 2);
	printf("  종  료   ");
	while (1)
	{
		int n = keyControl();
		switch (n) {
		case UP:
			if (y > 12)
			{
				gotoxy(x - 2, y);
				printf("  ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		case DOWN:
			if (y < 14) {
				gotoxy(x - 2, y);
				printf("  ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		case SUBMIT:
			return y - 12;
		}
	}
}

int keyControl()
{
	char temp = _getch();

	if (temp == 'w' || temp == 'W')
		return UP;
	else if (temp == 'a' || temp == 'A')
		return LEFT;
	else if (temp == 's' || temp == 'S')
		return DOWN;
	else if (temp == 'd' || temp == 'D')
		return RIGHT;
	else if (temp == ' ')
		return SUBMIT;

}
void infoDraw()
{
	system("cls");
	printf("\n\n");
	printf("                            [ 조 작 법 ]\n\n");
	printf("                     이 동 : W,  A,  S,  D\n");
	printf("                     선 택 : 스 페 이 스 바\n\n\n\n\n\n");
	printf("                  개 발 자 : L    S    W\n\n");
	printf("             스 페 이 스 바를 누 르 면  메인 화면으로 이동합니다.");
	while (1)
	{
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}