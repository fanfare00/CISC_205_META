#pragma once

#include "../util/cwt/CursesWindowToolkit.h"

#include "..\CellularAutomata\JamesCA.h"
#include "..\PointerPower\JamesPP.h"
#include "..\TestingGround\TestingGround.h"




int main(int argc, char *argv[])
{
	cwt::initializeScreen();

	Frame mainFrame(0, 0, COLS, LINES, "JAMES' CISC 205 PROJECT LOADER", COLOR_WHITE, COLOR_BLUE);

	NavigationMenu NM((mainFrame.getLength() / 2) - 25, (mainFrame.getWidth() / 2) - 7, 50, 13, 
		"SELECT PROGRAM", "Cellular Automata", "Affirmative Interaction", "Pointer Power", "Testing Ground");

	NM.setMenuOptions("< Select >", "< Exit >", "< Help >");
	
	switch (NM.getMenuChoice())
	{
		case 0:
			exit(1);
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
			JamesPP::getInstance().start(mainFrame);
			break;
		
		case 4:
			TestingGround::getInstance().start();
			break;
					
		default: 
			exit(1);
			break;
	}
}

