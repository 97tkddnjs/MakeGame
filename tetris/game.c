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

	gotoxy(x - 2, y); // -2�� �� ������ >����� ���ؼ�
	printf("> �� �� �� ��");
	gotoxy(x, y + 1);
	printf("�� �� �� ��");
	gotoxy(x, y + 2);
	printf("  ��  ��   ");
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
	printf("                            [ �� �� �� ]\n\n");
	printf("                     �� �� : W,  A,  S,  D\n");
	printf("                     �� �� : �� �� �� �� ��\n\n\n\n\n\n");
	printf("                  �� �� �� : L    S    W\n\n");
	printf("             �� �� �� �� �ٸ� �� �� ��  ���� ȭ������ �̵��մϴ�.");
	while (1)
	{
		if (keyControl() == SUBMIT) {
			break;
		}
	}
}