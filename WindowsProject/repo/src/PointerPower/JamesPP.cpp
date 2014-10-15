#include "JamesPP.h"
#include <vector>
#include "time.h"
#include <iostream>
#include <fstream>


using namespace std;
JamesPP::~JamesPP()
{
	//endwin();
}

JamesPP& JamesPP::getInstance()
{
	static JamesPP instance;
	return instance;
}



void JamesPP::start(Frame mFrame)
{
	mainFrame = mFrame;
	mainFrame.drawWin();

	ofstream ofs;
	ofs.open("scores.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	welcomeScreen();

}

void JamesPP::welcomeScreen()
{

	mainFrame.addText((mainFrame.getLength() / 2) - 12, (mainFrame.getWidth() / 2), "Welcome to James' Pointer Power!");
	mainFrame.addText((mainFrame.getLength() / 2) - 10, (mainFrame.getWidth() / 2) + 1, "Press <ENTER> to Begin.");

	cwt::hitEnter();

	mainMenu();

}

void JamesPP::mainMenu()
{
	mainFrame.addText(1, mainFrame.getWidth() - 2, defaultStatus);

	NavigationMenu NM((mainFrame.getLength() / 2) - 25, (mainFrame.getWidth() / 2) - 9, 50, 16,
		"MAIN MENU", "Sign In", "Display Logo", "Go Galton", "Play Game", "Game History", "ID Information", "Credits");

	NM.setMenuOptions("< Select >", "< Exit >", "< Help >");

	switch (NM.getMenuChoice())
	{
	case 0:
		
		break;

	case 1:
		signIn();
		break;

	case 2:
		displayLogo();
		break;

	case 3:
		
		break;

	case 4:
		
		break;
	case 5:

		break;

	case 6:
		displayIDInfo();
		break;
	default:
		
		break;
	}

}

void JamesPP::signIn()
{

	userName = DialogFrame::showInputDialog(mainFrame, "Continue", "SIGN IN", "Please enter your name:");
	

	DialogFrame::showMessageDialog(mainFrame, "Continue", "WELCOME", "Welcome to " + MY_NAME + "' Pointer Power, " + userName);
	
	mainFrame.drawWin();
	mainMenu();

}

void JamesPP::displayLogo()
{
	Frame logoFrame(mainFrame.getLength()/2 - 32, mainFrame.getWidth()/2 - 9, 65, 17, "JAMES' LOGO");
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

//	WINDOW *logoWindow = newwin(25, 80, (LINES / 2) - 11, (COLS / 2) - 40);
//	box(logoWindow, 0, 0);
//	wbkgd(logoWindow, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_YELLOW, COLOR_BLACK)));
//
//	cwt::mvwprintwCentered(logoWindow, 2, "THANK YOU FOR VIEWING JAMES' LOGO");
//	cwt::mvwprintwCentered(logoWindow, (getmaxy(logoWindow)-3), "Press any key to quit.");
//
//	int c = 0;
//
//	char* logoLines[] = {
//		"     JJJJJJJJJJJJJJJ DDDDDDDDDDDDD    MMMMMM        MMMMMM",
//		"     J.............J D............D   M.....M      M.....M",
//		"     JJJJJJJ...JJJJJ D....DDDDD....D  M......M    M......M",
//		"           J...J      D...D    D....D M.......M  M.......M",
//		"           J...J      D...D    D....D M........MM........M",
//		"           J...J      D...D    D....D M....MM......MM....M",
//		"JJJJJJ     J...J      D...D    D....D M....M MM..MM M....M",
//		"J....J     J...J      D...D    D....D M....M   MM   M....M",
//		"J.....JJJJJ....J     DD...DDDDDD...D  M....M        M....M",
//		" J............J      D............D   M....M        M....M",
//		"  JJJJJJJJJJJJ       DDDDDDDDDDDDD    MMMMMM        MMMMMM"
//	};
//
//	nodelay(logoWindow, TRUE);
//
//	while ((wgetch(logoWindow) == ERR))
//	{
//		c+=10;
//		if (c == 95)
//		{
//			c = 1;
//		}
//
//		//for ever line in the logo
//		for (int i = 0; i < 11; i++)
//		{
//			//for every character in the line
//			for (int j = 0; j < 58; j++)
//			{
//				if ((wgetch(logoWindow) != ERR))
//				{
//					goto endLoops;
//				}
//
//				switch (logoLines[i][j])
//				{
//				case 'J':
//wattron(logoWindow, COLOR_PAIR(cwt::colorPair(COLOR_RED, COLOR_BLUE)));
//mvwprintw(logoWindow, 6 + i, 9 + j, "J");
//wattroff(logoWindow, COLOR_PAIR(cwt::colorPair(COLOR_RED, COLOR_BLUE)));
//
//break;
//
//				case 'D':
//					wattron(logoWindow, COLOR_PAIR(cwt::colorPair(COLOR_RED, COLOR_BLUE)));
//					mvwprintw(logoWindow, 6 + i, 9 + j, "D");
//					wattroff(logoWindow, COLOR_PAIR(cwt::colorPair(COLOR_RED, COLOR_BLUE)));
//					break;
//
//				case 'M':
//					wattron(logoWindow, COLOR_PAIR(cwt::colorPair(COLOR_RED, COLOR_BLUE)));
//					mvwprintw(logoWindow, 6 + i, 9 + j, "M");
//					wattroff(logoWindow, COLOR_PAIR(cwt::colorPair(COLOR_RED, COLOR_BLUE)));
//
//					break;
//
//				case '.':
//					wattron(logoWindow, COLOR_PAIR(c));
//					mvwprintw(logoWindow, 6 + i, 9 + j, "#");
//					wattroff(logoWindow, COLOR_PAIR(c));
//					wrefresh(logoWindow);
//
//					napms(40);
//					break;
//
//				default:
//					break;
//
//				}
//			}
//		}
//	}
//endLoops:
//
//	wrefresh(logoWindow);
//
//	refreshBackground();
//	mainMenu();

}

void JamesPP::showGalton(WINDOW* win, bool showHistogram)
{
	//int ballCount = 1000;
	//int boxCount;
	//string coolString = "";

	//
	//gBox.resize(ballCount);

	//int     left_or_right = 0;
	//int     counter;
	//int     i, j;

	//srand(time(NULL));

	//for (int k = 0; k < 11; k++)
	//{
	//	coolString = "";
	//	boxCount = k;



	//	for (i = 0; i < ballCount; i++)
	//	{
	//		gBox[i] = 0;
	//	}


	//	for (i = 0; i < ballCount; i++)
	//	{
	//		counter = 0;
	//		for (j = 0; j < boxCount - 1; j++)
	//		{

	//			left_or_right = rand() % 2;
	//			counter = counter + left_or_right;


	//		}
	//		gBox[counter] = gBox[counter]++;
	//	}

	//	for (i = 0; i <= boxCount; i++)
	//	{
	//		wattron(win, COLOR_PAIR(cwt::colorPair(COLOR_WHITE, COLOR_BLACK)));
	//		cwt::mvwprintwCentered(win, 2 + k, (char*)coolString.c_str());
	//		wattroff(win, COLOR_PAIR(cwt::colorPair(COLOR_WHITE, COLOR_BLACK)));

	//		wattron(win, COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));
	//		mvwprintw(win, 3 + k, 2, "%i:", k);
	//		wattroff(win, COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));


	//		if (gBox[i] < 100)
	//		{
	//			coolString += " ";
	//		}
	//		coolString += "   " + to_string(gBox[i]);

	//		if (k == 10 && i < 10 && showHistogram == true)
	//		{

	//			for (int q = 0; q < 13; q++)
	//			{
	//				mvwprintw(win, 28 - q, 11 + i * 6, "|     |");
	//			}



	//			for (j = 0; j < gBox[i]; j++)
	//			{
	//				wattron(win, COLOR_PAIR(cwt::colorPair(COLOR_RED, COLOR_BLACK)));
	//				mvwprintw(win, 29 - ((j + 5) / 20), 14 + i * 6, "*");
	//				wattroff(win, COLOR_PAIR(cwt::colorPair(COLOR_RED, COLOR_BLACK)));
	//			}
	//			wattron(win, COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));
	//			mvwprintw(win, 30, 11 + i * 6, "|  %i  |", i);
	//			wattroff(win, COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));
	//		}
	//	}
	//}

	//	mvwprintw(win, 13, 2, "   ");
}

void JamesPP::goGalton()
{

	//WINDOW* win = JamesOptionPanes::jamesFrame(80, 36);


	//JamesPP::showGalton(win, true);

	//wattron(win, COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));
	//cwt::mvwprintwCentered(win, 14, "HISTOGRAM  :  ( 1 * = ~ 20 balls )");
	//cwt::mvwprintwCentered(win, 1, "  GALTON BOARD FLOW");
	//cwt::mvwprintwCentered(win, 32, "Press <ESC> to return to main menu");
	//cwt::mvwprintwCentered(win, 33, "Press <ENTER> to drop again");
	//wattroff(win, COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));

	//for (int t = 0; t < getmaxx(win)-2; t++)
	//{
	//	mvwaddch(win, 13, 1 + t, ACS_HLINE);
	//	mvwaddch(win, 15, 1+t, ACS_HLINE);
	//	mvwaddch(win, 31, 1 + t, ACS_HLINE);

	//	if (t < 61)
	//	{
	//		mvwaddch(win, 29, 11 + t, ACS_HLINE);
	//	}

	//}

	//for (int r = 0; r < 61; r+=6)
	//{
	//	mvwaddch(win, 29, 11+r, ACS_PLUS);
	//	mvwaddch(win, 30, 11 + r, ACS_VLINE);
	//	mvwaddch(win, 31, 11 + r, ACS_BTEE);

	//}

	//
	//wrefresh(win);

	//int keyPress = wgetch(win);

	////test key input
	//if (keyPress == 10)
	//{
	//	touchwin(win);
	//	wclear(win);
	//	delwin(win);
	//	refreshBackground();
	//	JamesPP::goGalton();
	//}

	//if (keyPress = 27)
	//{
	//	touchwin(win);
	//	wclear(win);
	//	delwin(win);
	//	refreshBackground();
	//	mainMenu();
	//}
}

void JamesPP::playGame()
{
	//WINDOW* win = JamesOptionPanes::jamesFrame(80, 36);
	//JamesPP::showGalton(win, false);
	//string aString = "";
	//double score = 0;
	//string scoreString = "";
	//



	//double values[]{ 126, 14, 3.5, 1.5, 1, 1, 1.5, 3.5, 14, 126 };

	//gameNumber += 1;

	//wattron(win, COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));
	//mvwprintw(win, 14, 2, "WEIGHT:    126    14   3.5   1.5    1     1    1.5   3.5    14   126");
	//wattroff(win, COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));
	//mvwprintw(win, 16, 2, "SCORE:");

	//wattron(win, COLOR_PAIR(cwt::colorPair(COLOR_CYAN, COLOR_BLACK)));
	//for (int i = 0; i < 10; i++)
	//{



	//	aString = to_string(gBox[i] * values[i]);
	//	aString.erase(aString.find_last_not_of('0') + 1, std::string::npos);
	//	if (aString.back() == '.')
	//	{
	//		aString.pop_back();
	//	}
	//	
	//	
	//	score += (gBox[i] * values[i]);
	//	mvwprintw(win, 16, 13+i*6, (char*)aString.c_str());

	//}
	//wattroff(win, COLOR_PAIR(cwt::colorPair(COLOR_CYAN, COLOR_BLACK)));

	//for (int t = 0; t < getmaxx(win) - 2; t++)
	//{
	//	mvwaddch(win, 13, 1 + t, ACS_HLINE);
	//	mvwaddch(win, 15, 1 + t, ACS_HLINE);
	//	mvwaddch(win, 17, 1 + t, ACS_HLINE);
	//	mvwaddch(win, 30, 1 + t, ACS_HLINE);

	//}

	//

	//scoreString = to_string(score);
	//scoreString.erase(scoreString.find_last_not_of('0') + 1, std::string::npos);

	//string congrats = "Congratulations, " + userName + "! Your score in game #" + to_string(gameNumber) + " is " + scoreString ;

	//ofstream myfile("scores.txt", ios_base::app);
	//if (myfile.is_open())
	//{
	//	myfile << scoreString + "\n";
	//	myfile.close();
	//}
	//else
	//{
	//	JamesOptionPanes::showMessage(mainWindow, "ERROR", "Unable to open file 'scores.txt'.");
	//}

	//wattron(win, COLOR_PAIR(cwt::colorPair(COLOR_WHITE, COLOR_BLACK)));
	//cwt::mvwprintwCentered(win, 24, (char*)congrats.c_str());
	//wattroff(win, COLOR_PAIR(cwt::colorPair(COLOR_WHITE, COLOR_BLACK)));

	//wattron(win, COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));
	//cwt::mvwprintwCentered(win, 1, "   PLAY GAME");
	//cwt::mvwprintwCentered(win, 32, "Press <ESC> to return to main menu");
	//cwt::mvwprintwCentered(win, 33, "Press <ENTER> to drop again");
	//wattroff(win, COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));

	//wrefresh(win);

	//int keyPress = wgetch(win);

	////test key input
	//if (keyPress == 10)
	//{
	//	touchwin(win);
	//	wclear(win);
	//	delwin(win);
	//	
	//	JamesPP::playGame();
	//}

	//if (keyPress = 27)
	//{
	//	touchwin(win);
	//	wclear(win);
	//	delwin(win);
	//	refreshBackground();
	//	mainMenu();
	//}

	//
}

void JamesPP::displayGameHistory()
{
	//WINDOW* win = JamesOptionPanes::jamesFrame(80, 12 + gameNumber);
	//string summary = "So far, " + userName + ", you have played " + to_string(gameNumber) + " game(s) with the following scores:";
	//string game;
	//
	//string line;
	//vector<string> myLines;
	//myLines.clear();

	//ifstream myFile("scores.txt", ios_base::in);
	//while (getline(myFile, line, '\n'))
	//{
	//	myLines.push_back(line);
	//}


	//cwt::mvwprintwCentered(win, 4, (char*)summary.c_str());
	//cwt::mvwprintwCentered(win, 1, "GAME HISTORY");

	//
	//for (int i = 1; i <= gameNumber; i++)
	//{
	//	
	//	if (myLines[i - 1].back() == '.')
	//	{
	//		myLines[i - 1].pop_back();
	//	}

	//	game = "Game #" + to_string(i) + ": " + myLines[i - 1];


	//	mvwprintw(win, 6 + i, 10, (char*)game.c_str());
	//}

	//wattron(win, A_BOLD | WA_BLINK);
	//mvwprintw(win, (getmaxy(win) - 3), ((getmaxx(win) / 2) - 4), "CONTINUE");
	//wattroff(win, A_BOLD | WA_BLINK);
	//wrefresh(win);

	//JamesOptionPanes::hitEnter(win);
	//
	//touchwin(win);
	//wclear(win);
	//delwin(win);
	//refreshBackground();
	//mainMenu();

	//	//"GAME HISTORY", "So far, " + userName + ", you have played " + to_string(gameNumber) + " games with the following scores: \n\n");
	//
	//
}

void JamesPP::displayIDInfo()
{
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
	//refreshBackground();
	//mainMenu();
}

void JamesPP::displayStars()
{
	/*JamesOptionPanes::showMessage(
		mainWindow,
		"ID INFORMATION",
		"      Programmer         : James McCarthy   \n"
		"      Assignment #       : TA #1.2CA        \n"
		"      Assignment Name    : Cellular Automata\n"
		"      Course # and Title : CISC 205 - OOPS  \n"
		"      Class Meeting Time : TTh 9:35 - 12:40 \n"
		"      Instructor         : Professor Forman \n"
		"      Hours              : 15               \n"
		"      Difficulty         : 5                \n"
		"      Completion Date    : 9/11/2014        \n"
		"      Project Name       : JamesCA          \n");


	refreshBackground();
	mainMenu();*/
}

void JamesPP::farewell()
{
	//JamesOptionPanes::showMessage(mainWindow, "Farewell", "Farewell, " + userName + ". Thank you for visiting " + MY_NAME + "' Pointer Power!");

	////touchwin(mainWindow);
	////wrefresh(mainWindow);
	////delwin(mainWindow);

	////touchwin(stdscr);
	////wrefresh(stdscr);

	//exit(1);

	
}