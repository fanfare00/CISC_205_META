
#include "..\CellularAutomata\JamesCA.h"
#include "..\PointerPower\JamesPP.h"

#include "..\util\JamesCurses.h"
#include "..\util\JamesOptionPanes.h"

int main(int argc, char *argv[])
{
	JamesCurses::initscr();
	JamesCurses::noecho();
	JamesCurses::cbreak();
	JamesCurses::curs_set(0);
	JamesCurses::resize_term(40, 90);
	JamesOptionPanes::loadColors();


	WINDOW *loaderWin = JamesCurses::newwin(40, 90, 0, 0);
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
			
		default: 
			exit(1);
			break;
		}

		 choice = JamesOptionPanes::showNavMenu(loaderWin,
			"-SELECT PROGRAM-",
			"CELLULAR AUTOMATA",
			"AFFIRMATIVE INTERACTION",
			"POINTER POWER",
			"EXIT");
	}
	

	
	return 0;
}