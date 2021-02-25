#define _CRT_SECURE_NO_WARNINGS


#include "main.h"
#include "game.h"
#include "util.h"

int main()
{
	init();
	while (1) {
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			//start Game
		}
		else if (menuCode == 1)
		{
			infoDraw();//Game info
		}
		else if (menuCode == 2)
		{
			return 0;	//end Game
		}system("cls");
	}
	return 0;
}


