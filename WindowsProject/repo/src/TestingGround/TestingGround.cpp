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
	
	//int keyPress;

	int XEE = 5;
	int YEE = 5;
	keypad(stdscr, true);

	//Component CRM(5, 5, 60, 15);
	//CRM.setBackground(COLOR_BLUE);

	Frame base(0, 0, COLS, LINES, "JAMES' TESTING GROUND", COLOR_WHITE, COLOR_BLUE);
	//base.setBackground(COLOR_BLUE);


	//Frame FRM((base.getLength() / 2) - 40, (base.getWidth() / 2) - 18, 80, 36, "Game History");
	//FRM.addTextArea("The quick brown fox jumps over the lazy dog.");
	//FRM.addButtonMenu("Continue", "Back");

	getch();

	DialogFrame::showMessageDialog(base, "TEST", "The quick brown fox jumps");

	getch();
	//FRM.enableMoveMode(true);
	exit(1);
	
	

}