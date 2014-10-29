#include "JamesAI.h"
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
////	START OOPS COMMON FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////////////

JamesAI::~JamesAI()
{
	//endwin();
}

JamesAI& JamesAI::getInstance()
{
	static JamesAI instance;
	return instance;
}

void JamesAI::start(Frame mFrame)
{
	mainFrame = mFrame;
	mainFrame.setTitle("JAMES' AFFIRMATIVE INTERACTION");
	mainFrame.setBackground(COLOR_RED);
	mainFrame.drawWin();

	ofstream ofs;
	ofs.open("scores.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	welcomeScreen();

}

void JamesAI::welcomeScreen()
{

	mainFrame.addTextHorCentered((mainFrame.getWidth() / 2), "Welcome to James' Affirmative Interaction!", COLOR_GREEN, COLOR_RED);
	mainFrame.addTextHorCentered((mainFrame.getWidth() / 2) + 1, "Press <ENTER> to Begin.", COLOR_GREEN, COLOR_RED);

	cwt::hitEnter();
	mainFrame.addText((mainFrame.getLength() / 2) - 18, (mainFrame.getWidth() / 2), "                                     ");
	mainFrame.addText((mainFrame.getLength() / 2) - 11, (mainFrame.getWidth() / 2) + 1, "                       ");

	mainFrame.drawWin();
	mainMenu();

}

void JamesAI::signIn()
{
	userName = DialogFrame::showInputDialog(mainFrame, "Continue", "SIGN IN", "Please enter your full name:");
	defaultStatus = "You are currently signed in as: " + userName;
	
	mainFrame.drawWin();
	mainMenu();

}

void JamesAI::displayLogo()
{
	Frame logoFrame(mainFrame.getLength() / 2 - 32, mainFrame.getWidth() / 2 - 9, 65, 17, "JAMES' LOGO");
	logoFrame.setBackground(COLOR_WHITE);
	logoFrame.setForeground(COLOR_BLACK);

	TextArea TA = logoFrame.addTextArea();
	TA.setBackground(COLOR_WHITE);

	TA.addText(0, 0,
		"     JJJJJJJJJJJJJJJ DDDDDDDDDDDDD    MMMMMM        MMMMMM\n"
		"     J.............J D............D   M.....M      M.....M\n"
		"     JJJJJJJ...JJJJJ D....DDDDD....D  M......M    M......M\n"
		"           J...J      D...D    D....D M.......M  M.......M\n"
		"           J...J      D...D    D....D M........MM........M\n");

	TA.addText(0, 5,
		"           J...J      D...D    D....D M....MM......MM....M\n"
		"JJJJJJ     J...J      D...D    D....D M....M MM..MM M....M\n"
		"J....J     J...J      D...D    D....D M....M   MM   M....M\n"
		"J.....JJJJJ....J     DD...DDDDDD...D  M....M        M....M\n"
		" J............J      D............D   M....M        M....M\n"
		"  JJJJJJJJJJJJ       DDDDDDDDDDDDD    MMMMMM        MMMMMM\n");


	logoFrame.addButtonMenu("< Continue >");
	cwt::hitEnter();
	mainFrame.drawWin();

	mainMenu();


}

void JamesAI::displayIDInfo()
{
	requireLogin();

	DialogFrame::showMessageDialog(
		mainFrame,
		"Continue", "ID INFORMATION",
		"      Programmer         : James McCarthy   \n"
		"      Assignment #       : TA #1.2CA        \n"
		"      Assignment Name    : Cellular Automata\n"
		"      Course # and Title : CISC 205 - OOPS  \n"
		"      Class Meeting Time : TTh 9:35 - 12:40 \n"
		"      Instructor         : Professor Forman \n"
		"      Hours              : 15               \n"
		"      Difficulty         : 5                \n"
		"      Completion Date    : 9/11/2014        \n"
		"      Project Name       : JamesCA          ");

	mainFrame.drawWin();
	mainMenu();
}

void JamesAI::displayCredits()
{
	requireLogin();

	DialogFrame::showMessageDialog(
		mainFrame,
		"< CONTINUE >", "CREDITS",
		"This program was created by James McCarthy for Larry Forman's CISC 205 Object Oriented C++ class\n"
		"\nThank you to Nils for providing support with debugging and for giving me many   ideas and of course, introducing me to PDCurses.\n"
		"\nThank you to the creators of ncurses/PDCurses for providing a wonderful library to create this program's UI.\n\n"
		"PDCurses website   : www.pdcurses.sourceforge.net/doc/PDCurses.txt\n"
		"ncurses tutorials  : www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/\n"
		"My Github          : www.github.com/fanfare00");

	mainFrame.drawWin();
	mainMenu();
}


void JamesAI::displayStars()
{
	requireLogin();

	DialogFrame::showMessageDialog(
		mainFrame,
		"< CONTINUE >", "STARS",
		"Insert stars here");

	mainFrame.drawWin();
	mainMenu();
}

void JamesAI::farewell()
{
	DialogFrame::showMessageDialog(mainFrame, "< EXIT >", "GOODBYE", "Farewell, " + userName + ". Thank you for using " + MY_NAME + "' Pointer Power");
	exit(1);


}

void JamesAI::requireLogin()
{
	if (userName == "Unknown User")
	{
		DialogFrame::showMessageDialog(mainFrame, "< Back >", "ERROR", "Please sign in before proceeding");
		mainFrame.drawWin();
		mainMenu();
	}
	else
	{
		return;
	}
}

void JamesAI::mainMenu()
{
	mainFrame.addText(2, mainFrame.getWidth() - 2, defaultStatus, COLOR_GREEN, COLOR_RED);

	mainFrame.drawWin();


	NavigationMenu NM((mainFrame.getLength() / 2) - 25, (mainFrame.getWidth() / 2) - 9, 50, 16,
		"MAIN MENU", "Sign In", "Display Logo", "Affirmative Interaction", "Display Dictionary", "ID Information", "Credits", "Stars");

	NM.setMenuOptions("< Select >", "< Exit >", "< Help >");

	switch (NM.getMenuChoice())
	{
	//exit
	case 0:
		farewell();
		break;

	//sign in
	case 1:
		signIn();
		break;

	//Display Logo
	case 2:
		displayLogo();
		break;

	//Affirmative Interaction
	case 3:
		startAI();
		break;

	//Dictionary
	case 4:
		displayAIDictionary();
		break;

	//ID Info
	case 5:
		displayIDInfo();
		break;

	//Credits
	case 6:
		displayCredits();
		break;

	case 7:
		displayStars();
		break;

	default:

		break;
	}

}

////////////////////////////////////////////////////////////////////
/////	END OOPS COMMON FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
/////	START AI SPECIFIC FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////////

//Afirmative Interaction
void JamesAI::startAI()
{
	char cTemp[80];
	int length = 82;
	int width = 27;
	int x = (mainFrame.getLength() / 2) - (length/2);
	int y = (mainFrame.getWidth()/2) - (width/2);

	Frame aFrame(x, y, length, width, "AFFIRMATIVE INTERACTION");
	TextArea TA = aFrame.addTextArea();

	TA.setBackground(COLOR_BLACK);
	TA.enableBorder(false);

	keypad(aFrame.component, true); 
	curs_set(1);
	echo();
	scrollok(TA.component, true);

	move(y, x);

	int i = 1;
	while (true)
	{
		mvwgetstr(TA.component, i, 2, cTemp);
		wscrl(TA.component, 1);
		i++;
	}
	

	getch();
	//getch();
}

//Dictionary
void JamesAI::displayAIDictionary()
{

}