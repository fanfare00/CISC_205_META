#include "TestingGround.h"

TestingGround::~TestingGround()
{
	//endwin();
}

TestingGround& TestingGround::getInstance()
{
	static TestingGround instance;
	return instance;
}

void TestingGround::start()
{
	wclear(stdscr);
	wrefresh(stdscr);
	
	int keyPress;

	int XEE = 5;
	int YEE = 5;
	keypad(stdscr, true);

	Component CRM(25, 1, 10, 5);
	CRM.setBackground(COLOR_BLUE);

	Frame FRM(1, 1, 30, 10, "TEST TITLE");
	

	getch();
	FRM.enableMoveMode(true);
	
	

}