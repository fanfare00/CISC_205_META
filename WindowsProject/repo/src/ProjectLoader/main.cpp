#pragma once

#include "../util/cwt/CursesWindowToolkit.h"
//#include "../util/cwt/Components/Component.h"
#include "..\CellularAutomata\JamesCA.h"
#include "..\PointerPower\JamesPP.h"

#include "..\util\JamesOptionPanes.h"

#include "..\TestingGround\TestingGround.h"


int main(int argc, char *argv[])
{
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	resize_term(40, 90);
	cwt::loadColor();


	WINDOW *loaderWin = newwin(40, 90, 0, 0);
	int choice = 0;

	while (true)
	{
		switch (choice)
		{
		case 0:
			break;

		case 1:
			JamesCA::getInstance().start();
			break;

		case 2:
			JamesOptionPanes::showMessage(stdscr, "SORRY", "This program is under construction and is currently unavailable.");
			wclear(stdscr);
			wrefresh(stdscr);
			break;
		case 3:
			JamesPP::getInstance().start();
			break;

		case 4:
			TestingGround::getInstance().start();
			break;
			
		default: 
			exit(1);
			break;
		}

		 choice = JamesOptionPanes::showNavMenu(loaderWin,
			"-SELECT PROGRAM-",
			"CELLULAR AUTOMATA",
			"AFFIRMATIVE INTERACTION",
			"POINTER POWER",
			"TESTING GROUND",
			"EXIT");
	}
	

	
	return 0;
}

