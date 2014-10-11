/*******************************************************************************
********************************************************************************
********************************************************************************

ID INFORMATION

Programmer		   :  James McCarthy
Assignment #	   :  TA #1.3CA
Assignment Name	   :  Cellular Automata
Course # and Title :  CISC 205 - OOPS
Class Meeting Time :  TTh 9:35 - 12:40
Instructor		   :  Professor Forman
Hours			   :  17
Difficulty		   :  5
Completion Date	   :  9/11/2014
Project Name	   :  JamesCA

********************************************************************************
********************************************************************************

"JamesCA.cpp" DESCRIPTION



********************************************************************************
********************************************************************************

CUSTOM-DEFINED FUNCTION LIST




********************************************************************************
********************************************************************************

CREDITS




********************************************************************************
********************************************************************************
********************************************************************************/

using namespace std;

#include "jamesCA.h"
#include <string>
#include <bitset>

#include "../util/cwt/CursesWindowToolkit.h"

JamesCA::~JamesCA()
{
	//endwin();
}

JamesCA& JamesCA::getInstance()
{
	static JamesCA instance;
	return instance;
}

void JamesCA::setUp()
{
	
}


void JamesCA::refreshBackground()
{
	resize_term(40, 100);
	delwin(mainWindow);
	
	mainWindow = newwin(LINES, COLS, 0, 0);
	wbkgd(mainWindow, COLOR_PAIR(cwt::colorPair(COLOR_YELLOW, COLOR_CYAN)));

	wattron(mainWindow, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_CYAN)));
	mvwprintw(mainWindow, LINES - 1, 0, "%s %s", defaultStatus, (char*)userName.c_str());
	wattroff(mainWindow, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_CYAN)));

	

	wrefresh(mainWindow);
}

void JamesCA::start()
{
	setUp();
	refreshBackground();
	welcomeScreen();
}




void JamesCA::welcomeScreen()
{
	WINDOW *win = newwin(15, 65, 2, 12);
	box(win, 0, 0);
	wbkgd(win, COLOR_PAIR(cwt::colorPair(COLOR_BLUE, COLOR_GREEN)));

	while (win != NULL)
	{




		mvwprintw(win, 1, 16, "  _____     _ _       _			");
		mvwprintw(win, 2, 16, " / ____|   | | |     | |		");
		mvwprintw(win, 3, 16, "| |     ___| | |_   _| | __ _ _ __");
		mvwprintw(win, 4, 16, "| |    / _ \\ | | | | | |/ _` | '__|");
		mvwprintw(win, 5, 16, "| |___|  __/ | | |_| | | (_| | |	");
		mvwprintw(win, 6, 16, " \\_____\\___|_|_|\\__,_|_|\\__,_|_|");
		mvwprintw(win, 7, 4, "         _    _ _______ ____  __  __       _______	");
		mvwprintw(win, 8, 4, "    /\\  | |  | |__   __/ __ \\|  \\/  |   /\\|__   __|/\\ ");
		mvwprintw(win, 9, 4, "   /  \\ | |  | |  | | | |  | | \\  / |  /  \\  | |  /  \\ ");
		mvwprintw(win, 10, 4, "  / /\\ \\| |  | |  | | | |  | | |\\/| | / /\\ \\ | | / /\\ \\ ");
		mvwprintw(win, 11, 4, " / ____ \\ |__| |  | | | |__| | |  | |/ ____ \\| |/ ____ \\ ");
		mvwprintw(win, 12, 4, "/_/    \\_\\____/   |_|  \\____/|_|  |_/_/    \\_\\_/_/    \\_\\ ");
		wattroff(win, COLOR_PAIR(cwt::colorPair(COLOR_BLUE, COLOR_GREEN)));

		wrefresh(win);


		wattron(mainWindow, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_YELLOW, COLOR_CYAN)));
		mvwprintw(mainWindow, 1, 13, "Welcome to James'");
		mvwprintw(mainWindow, 17, 16, "--An experimental program examining digital life-forms--");
		cwt::mvwprintwCentered(mainWindow, LINES / 2 + 5, "Press <ENTER> To Begin");
		wattroff(mainWindow, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_YELLOW, COLOR_CYAN)));


		wrefresh(mainWindow);

		//pause for key input
		int keyPress = wgetch(win);

		//test key input
		if (keyPress == 10)
		{
			werase(win);
			wrefresh(win);
			delwin(win);

			refreshBackground();
			mainMenu();
			break;
		}
		if (keyPress == 27)
		{
			touchwin(mainWindow);
			wrefresh(mainWindow);
			delwin(mainWindow);

			touchwin(stdscr);
			wrefresh(stdscr);
			break;
		}


	}
	

	
}


//DESCRIPTION: 

void JamesCA::mainMenu()
{
	int choice = 0;

	//refreshBackground();

	JamesOptionPanes::showTitleMessage("James' Cellular Automata");
	
		choice = JamesOptionPanes::showNavMenu(mainWindow, "-MAIN MENU-", "SIGN IN", "DISPLAY LOGO",  "CELLULAR AUTOMATA", "ID INFORMATION", "CREDITS",  "STARS",  "EXIT");

		//JamesOptionPanes::showConfirmationMessage(mainWindow, "Ltttt?", "LL");
			switch (choice)
			{

			case 1:
				signIn();
				break;

			case 2:
				displayLogo();
				break;

			case 3:
				patternMenu();
				break;

			case 4:
				idInfo();
				break;

			case 5:
				credits();
				break;

			case 6:
				displayStars();
				break;

			case 7:
				farewell();
				break;
			}
		}
		//else
		//{
		//	refreshBackground();
		//	mainMenu();
		//}
//}

void JamesCA::patternMenu()
{
	string nLines;
	string patternCode;

	nLines = JamesOptionPanes::showInputMessage(mainWindow, "Enter Lines", "Please enter number of lines: ");
	patternCode = JamesOptionPanes::showInputMessage(mainWindow, "Enter Pattern Code", "Please enter pattern number (0-255)");


	string binary = std::bitset<8>(stoi(patternCode)).to_string();
	char *ruleSet = (char*)binary.c_str();


	displayPattern(stoi(nLines), ruleSet, (char*)patternCode.c_str());
}

void JamesCA::displayPattern(int nSteps, char* ruleSet, char* patternCode)
{
	int i; //iterate for
	int j;
	int nCells = 90;

	char *x = new char[nCells + 2];;
	char *x_old = new char[nCells + 2];;

	bool rules[7]; //array of possible neighbor configurations



	//resize the console window based on number of lines user asked to see
	resize_term(nSteps + 15, nCells + 6);

	//title box that displays the code# and ruleset of the current pattern
	WINDOW* patternTitle = JamesOptionPanes::titleBox();
	mvwprintw(patternTitle, 1, 16, "%s", ruleSet);
	cwt::mvwprintwCentered(patternTitle, 3, "PATTERN # %s", patternCode);
	
	
	wrefresh(patternTitle);

	//window the pattern is displayed inside
	WINDOW* patternWindow = newwin(LINES - 12, COLS - 4, 8, (COLS / 2) - ((COLS - 4) / 2));
	wbkgd(patternWindow, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_YELLOW, COLOR_BLACK)));
	box(patternWindow, 0, 0);
	wrefresh(patternWindow);

	//dont pause for input
	nodelay(patternWindow, TRUE);

	//allow window to scroll down and replace lines at the top
	scrollok(patternWindow, TRUE);

	//fill array with "dead" cells
	for (i = 0; i <= nCells + 1; i++)
	{
		x[i] = ' ';
	}

	//seed cell in the middle in "alive" state
	x[nCells / 2] = '#';

	//print "generation 1"
	for (i = 1; i <= nCells; i++)
	{
		mvwprintw(patternWindow, 1, i, "%c", x[i]);
	}

	//repeat for each row user asked for
	for (j = 1; j <= nSteps; j++)
	{
		//put generation 1 into a seperate array for checking
		for (i = 0; i < nCells + 2; i++)
		{
			x_old[i] = x[i];
		}

		for (i = 1; i <= nCells; i++)
		{
			//define each possible rule in the neighborhood
			rules[7] = (x_old[i - 1] == ' ' && x_old[i] == ' ' && x_old[i + 1] == ' ');
			rules[6] = (x_old[i - 1] == ' ' && x_old[i] == ' ' && x_old[i + 1] == '#');
			rules[5] = (x_old[i - 1] == ' ' && x_old[i] == '#' && x_old[i + 1] == ' ');
			rules[4] = (x_old[i - 1] == ' ' && x_old[i] == '#' && x_old[i + 1] == '#');
			rules[3] = (x_old[i - 1] == '#' && x_old[i] == ' ' && x_old[i + 1] == ' ');
			rules[2] = (x_old[i - 1] == '#' && x_old[i] == ' ' && x_old[i + 1] == '#');
			rules[1] = (x_old[i - 1] == '#' && x_old[i] == '#' && x_old[i + 1] == ' ');
			rules[0] = (x_old[i - 1] == '#' && x_old[i] == '#' && x_old[i + 1] == '#');

			//loop through each binary digit int he user defined ruleset
			for (int a = 0; a < 8; a++)
			{
				//if binary digit is a 0, dont use rule
				if (ruleSet[a] == '0')
				{
					rules[a] = false;
				}

			}

			//check if character in old generate satisfies rule and set character in new array to "alive"
			if (rules[0] || rules[1] || rules[2] || rules[3] || rules[4] || rules[5] || rules[6] || rules[7])
			{
				x[i] = '#';
			}
			//otherwise, if rules are not satisfied, set new character to "dead"
			else
			{
				x[i] = ' ';
			}

		}
		x[0] = x[nCells];
		x[nCells + 1] = x[1];

		for (i = 1; i <= nCells; i++)
		{
			mvwprintw(patternWindow, j + 1, i, "%c", x[i]);

		}

		//if key is pressed, end pattern loop
		if ((wgetch(patternWindow) != ERR))
		{
			break;
		}

		//refresh after printing line
		wrefresh(patternWindow);

		//pause thread for .25 seconds before printing next line
		napms(250);
	}

	//free memory
	delete[] x;
	delete[] x_old;

	attron(A_BOLD | WA_BLINK | COLOR_PAIR(cwt::colorPair(COLOR_YELLOW, COLOR_BLACK)));
	mvprintw(LINES - 3, (COLS / 2) - 2, "BACK");
	attroff(A_BOLD | WA_BLINK | COLOR_PAIR(cwt::colorPair(COLOR_YELLOW, COLOR_BLACK)));
	refresh();

	JamesOptionPanes::hitEnter(patternWindow);
	refreshBackground();
	mainMenu();

}

void JamesCA::displayStars()
{

	JamesOptionPanes::showLargeMessage(
		mainWindow,
		"ID INFORMATION",
		"1 - Display cellular outpu fully across 25 rows and 80 columns \n"
		"2 - Display the rows and columns with a space for 0s and character for 1s\n"
		"3 - Use color for the character representing the 1s\n"
		"4 - Prompt user for number of rows to be displayed\n"
		"5/6 - Create a simple way to let the user chose any possible pattern\n"
		"7 - Create a new, enhanced, 'pizzazzy' logo\n"
		"8 - Use 4+ colors througout\n"
		"9 - Use custom header files\n"
		"10 - Add extra pizzaz: creating a library that can be re-used\n"
		"11 - Demo before due-date\n");



	refreshBackground();
	mainMenu();
}


void JamesCA::signIn()
{

	userName = JamesOptionPanes::showInputMessage(mainWindow, "SIGN IN", "Please enter your name:");
	
	defaultStatus = ("You are currently signed in as:");

	refreshBackground();
	
	JamesOptionPanes::showMessage(mainWindow, "Welcome", "Thank you for joining us " + userName);
	


	refreshBackground();
	mainMenu();

}



void JamesCA::displayLogo()
{
		WINDOW* logoWindow = JamesOptionPanes::largeMessageFrame();
			cwt::mvwprintwCentered(logoWindow, 2, "THANK YOU FOR VIEWING JAMES' LOGO");
			
		int c = 1;

		char* logoLines[] = {
			 "     JJJJJJJJJJJJJJJ DDDDDDDDDDDDD    MMMMMM        MMMMMM",
			 "     J.............J D............D   M.....M      M.....M",
			 "     JJJJJJJ...JJJJJ D....DDDDD....D  M......M    M......M",
			 "           J...J      D...D    D....D M.......M  M.......M",
			 "           J...J      D...D    D....D M........MM........M",
			 "           J...J      D...D    D....D M....MM......MM....M",
			 "JJJJJJ     J...J      D...D    D....D M....M MM..MM M....M",
			 "J....J     J...J      D...D    D....D M....M   MM   M....M",
			 "J.....JJJJJ....J     DD...DDDDDD...D  M....M        M....M",
			 " J............J      D............D   M....M        M....M",
			 "  JJJJJJJJJJJJ       DDDDDDDDDDDDD    MMMMMM        MMMMMM"
		};

		nodelay(logoWindow, TRUE);
		
		while ((wgetch(logoWindow) == ERR))
		{
			c++;
			if (c == 18)
			{
				c = 1;
			}
			
			//for ever line in the logo
			for (int i = 0; i < 11; i++)
			{
				//for every character in the line
				for (int j = 0; j < 58; j++)
				{
					if ((wgetch(logoWindow) != ERR))
					{
						goto endLoops;
					}

					switch (logoLines[i][j])
					{	
						case 'J':
							wattron(logoWindow, COLOR_PAIR(1));
							mvwprintw(logoWindow, 5 + i, 7 + j, "J");
							wattroff(logoWindow, COLOR_PAIR(1));
						
							break;

						case 'D':
							wattron(logoWindow, COLOR_PAIR(1));
							mvwprintw(logoWindow, 5 + i, 7 + j, "D");
							wattroff(logoWindow, COLOR_PAIR(1));
							break;

						case 'M':
							wattron(logoWindow, COLOR_PAIR(1));
							mvwprintw(logoWindow, 5 + i, 7 + j, "M");
							wattroff(logoWindow, COLOR_PAIR(1));

							break;

						case '.':
							wattron(logoWindow, COLOR_PAIR(c));
							mvwprintw(logoWindow, 5 + i, 7 + j, "#");
							wattroff(logoWindow, COLOR_PAIR(c));
							wrefresh(logoWindow);
							
							napms(40);
							break;

					default:
						break;

					}
				}
			}
		}
		endLoops:

		wrefresh(logoWindow);

		refreshBackground();
		mainMenu();
}


void JamesCA::idInfo()
{
	JamesOptionPanes::showMessage(
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
	mainMenu();

}

void JamesCA::credits()
{
	JamesOptionPanes::showMessage(
		mainWindow, 
		"Credits", 		
		"James' Cellular Automata Program was created by James McCarthy for "
		"Larry Forman's Fall 2014 CISC 205 Object Oriented C++ class at San "
		"Diego City College. Thank you to Nils Olsson for introducing me to "
		"PDJCurses and helping me set it up in Visual Studio. Thank you to the "
		"creators of PDJCurses and nJCurses for providing documentation that "
		"helped me learn my way around. \n\n\n"
		"My Github Profile :   www.github.com/fanfare00 \n"
		"My Blog :             www.jdonaldmccarthy.wordpress.com");

	refreshBackground();
	
	JamesOptionPanes::showMessage(
		mainWindow,
		"RESOURCES",
		"\n\nPDJCurses Website  :   www.pdJCurses.sourceforge.net\n");

	//JamesOptionPanes::showMessage(
	//	mainWindow,
	//	"RESOURCES",
	//	" PDJCurses Website  :   www.pdJCurses.sourceforge.net\n"
	//	" add more links");
																		


	refreshBackground();
	mainMenu();
}


void JamesCA::farewell()
{
	JamesOptionPanes::showMessage(mainWindow, "Farewell", "The quick brown fox jumps over the lazy dog. The quick brown fox elephant crying sadness pain the lazy dog. The quick brown fox jumps over the lazy dog.");
	
	touchwin(mainWindow);
	wrefresh(mainWindow);
	delwin(mainWindow);

	touchwin(stdscr);
	wrefresh(stdscr);

}


