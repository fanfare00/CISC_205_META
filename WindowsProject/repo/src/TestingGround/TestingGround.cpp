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
	string testStr;

	//Component CRM(5, 5, 60, 15);
	//CRM.setBackground(COLOR_BLUE);

	Frame base(0, 0, COLS, LINES, "JAMES' TESTING GROUND", COLOR_WHITE, COLOR_BLUE);
	//base.setBackground(COLOR_BLUE);


	//Frame FRM((base.getLength() / 2) - 40, (base.getWidth() / 2) - 18, 80, 36, "Game History");
	//FRM.addTextArea("The quick brown fox jumps over the lazy dog.");
	//FRM.addButtonMenu("Continue", "Back");

	getch();

	DialogFrame::showMessageDialog(base, "< Continue >", "Welcome", "Welcome to James' Testing Ground!");
	//DialogFrame::showMessageDialog(base, "< Continue >", "Welcome", "Thank you for joining us Uknown User!");
	//testStr = DialogFrame::showInputDialog(base, "< Submit >", "Log In", "Please enter your name");
	base.drawWin();

	//DialogFrame::showMessageDialog(base, "< Continue >", "Burp Back", testStr);
	base.drawWin();

	NavigationMenu NM(10, 5, 50, 15, "MAIN MENU");

	getch();
	//FRM.enableMoveMode(true);
	exit(1);
	
	

}