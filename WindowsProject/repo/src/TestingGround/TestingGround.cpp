#include "TestingGround.h"




TestingGround::~TestingGround()
{
	endwin();
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

	Component mainComponent(0, 0, COLS, LINES);
	mainComponent.setBackground(COLOR_BLACK);
	box(mainComponent.component, 0, 0);
	mainComponent.drawWin();

	Component coolComponent(0, 0, 20, 11);
	coolComponent.setBackground(COLOR_GREEN);
	coolComponent.drawWin();

	
	//coolComponent.addText(0, 0, "     JJJJJJJJJJJJJJJ", COLOR_RED, COLOR_BLACK);
	//coolComponent.addText(0, 1, "     J.............J", COLOR_RED, COLOR_BLACK);
	//coolComponent.addText(0, 2, "     JJJJJJJ...JJJJJ", COLOR_RED, COLOR_BLACK);
	//coolComponent.addText(0, 3, "           J...J    ", COLOR_RED, COLOR_BLACK);
	//coolComponent.addText(0, 4, "           J...J    ", COLOR_RED, COLOR_BLACK);
	//coolComponent.addText(0, 5, "           J...J    ", COLOR_RED, COLOR_BLACK);
	//coolComponent.addText(0, 6, "JJJJJJ     J...J    ", COLOR_RED, COLOR_BLACK);
	//coolComponent.addText(0, 7, "J....J     J...J    ", COLOR_RED, COLOR_BLACK);
	//coolComponent.addText(0, 8, "J.....JJJJJ....J    ", COLOR_RED, COLOR_BLACK);
	//coolComponent.addText(0, 9, " J............J     ", COLOR_RED, COLOR_BLACK);
	//coolComponent.addText(0, 10, "  JJJJJJJJJJJJ      ", COLOR_RED, COLOR_BLACK);


	int xMove;
	int yMove = 5;
	bool goRight = true;
	bool goUp = true;

	nodelay(mainComponent.component, TRUE);
	while (wgetch(mainComponent.component) == ERR)
	{
		if (xMove+coolComponent.getLength() == mainComponent.getLength() - 2)
		{
			
			xMove -= 1;
			goRight = false;
		}
		
		if (xMove == mainComponent.getBegX() + 2)
		{
			
			xMove += 1;
			goRight = true;
		}

		if (yMove+coolComponent.getWidth() == mainComponent.getWidth() - 2)
		{
			yMove -= 1;
			goUp = false;

		}

		if (yMove == mainComponent.getBegY() + 2)
		{

			yMove += 1;
			goUp = true;
		}

		if (goRight)
		{
			
			xMove += 1;
		}
		else
		{
			
			xMove -= 1;
		}

		if (goUp)
		{

			yMove += 1;
		}
		else
		{
			yMove -= 1;
		}
	
		
		coolComponent.setLocation(xMove, yMove);
		werase(mainComponent.component);


		napms(95);

		

	}

	coolComponent.enableMoveMode(true);



	getch();

	//
	////int keyPress;

	//keypad(stdscr, true);
	//string testStr;

	////Component CRM(5, 5, 60, 15);
	////CRM.setBackground(COLOR_BLUE);

	//Frame base(0, 0, COLS, LINES, "JAMES' TESTING GROUND", COLOR_WHITE, COLOR_BLUE);
	////base.setBackground(COLOR_BLUE);


	////Frame FRM((base.getLength() / 2) - 40, (base.getWidth() / 2) - 18, 80, 36, "Game History");
	////FRM.addTextArea("The quick brown fox jumps over the lazy dog.");
	////FRM.addButtonMenu("Continue", "Back");

	//getch();

	//DialogFrame::showMessageDialog(base, "< Continue >", "Welcome", "Welcome to James' Testing Ground!");
	//base.drawWin();

	//NavigationMenu NM((base.getLength()/2) - 25, (base.getWidth()/2)-7, 50, 15, "MAIN MENU", "Sign In", "Display Logo", "ID Information", "Credits", "Examples", "Exit");
	//int PP = NM.getMenuChoice();

	//base.drawWin();

	//DialogFrame::showMessageDialog(base, "< Continue >", "TEST", "You selected option " + to_string(PP));
	//base.drawWin();

	////int PPP = NM.getMenuChoice();


	////DialogFrame::showMessageDialog(base, "< Continue >", "Welcome", "Thank you for joining us Uknown User!");
	////testStr = DialogFrame::showInputDialog(base, "< Submit >", "Log In", "Please enter your name");
	////base.drawWin();

	////DialogFrame::showMessageDialog(base, "< Continue >", "Burp Back", testStr);
	////base.drawWin();


	//Component moveTest(25, 10, 10, 5);
	//moveTest.setBackground(COLOR_RED);

	//moveTest.enableMoveMode(true);
	////NavigationMenu NM(10, 5, 50, 15, "MAIN MENU");
	
	//FRM.enableMoveMode(true);
	

	
	

}