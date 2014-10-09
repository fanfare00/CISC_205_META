#include "JamesPP.h"
#include <vector>
#include "time.h"
#include <iostream>
#include <fstream>

JamesPP::~JamesPP()
{
	//JamesCurses::endwin();
}

JamesPP& JamesPP::getInstance()
{
	static JamesPP instance;
	return instance;
}

void JamesPP::setup()
{
	mainWindow = JamesCurses::newwin(LINES, COLS, 0, 0);
	JamesCurses::wbkgd(mainWindow, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_YELLOW, COLOR_BLUE)));

	JamesCurses::wattron(mainWindow, A_BOLD | COLOR_PAIR(JamesOptionPanes::jColor(COLOR_GREEN, COLOR_BLUE)));
	JamesCurses::mvwprintw(mainWindow, LINES - 1, 0, "%s %s", defaultStatus, (char*)userName.c_str());
	JamesCurses::wattroff(mainWindow, A_BOLD | COLOR_PAIR(JamesOptionPanes::jColor(COLOR_GREEN, COLOR_BLUE)));

	JamesCurses::wattron(mainWindow, A_BOLD | COLOR_PAIR(JamesOptionPanes::jColor(COLOR_GREEN, COLOR_BLUE)));
	JamesCurses::mvwprintwCentered(mainWindow, COLS / 2, "Use the arrow keys to move up and down.");
	JamesCurses::mvwprintwCentered(mainWindow, COLS / 2, "Press <ENTER> to make a selection");
	JamesCurses::wattroff(mainWindow, A_BOLD | COLOR_PAIR(JamesOptionPanes::jColor(COLOR_GREEN, COLOR_BLUE)));

	ofstream ofs;
	ofs.open("scores.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
}

void JamesPP::start()
{
	setup();
	welcomeScreen();

}

void JamesPP::refreshBackground()
{
	wclear(mainWindow);
	

	JamesCurses::wattron(mainWindow, A_BOLD | COLOR_PAIR(JamesOptionPanes::jColor(COLOR_GREEN, COLOR_BLUE)));
	JamesCurses::mvwprintw(mainWindow, LINES - 1, 0, "%s %s", defaultStatus, (char*)userName.c_str());
	JamesCurses::wattroff(mainWindow, A_BOLD | COLOR_PAIR(JamesOptionPanes::jColor(COLOR_GREEN, COLOR_BLUE)));

	JamesCurses::wattron(mainWindow, A_BOLD | COLOR_PAIR(JamesOptionPanes::jColor(COLOR_YELLOW, COLOR_BLUE)));
	JamesCurses::mvwprintwCentered(mainWindow, LINES-8, "Use the arrow keys to move up and down.");
	JamesCurses::mvwprintwCentered(mainWindow, LINES - 7, "Press <ENTER> to make a selection");
	JamesCurses::wattroff(mainWindow, A_BOLD | COLOR_PAIR(JamesOptionPanes::jColor(COLOR_YELLOW, COLOR_BLUE)));

	wrefresh(mainWindow);
}

void JamesPP::welcomeScreen()
{
	WINDOW *welcomeWin = JamesCurses::newwin(15, 65, 2, 12);
	JamesCurses::wbox(welcomeWin, 0, 0);
	JamesCurses::wbkgd(welcomeWin, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_BLUE, COLOR_GREEN)));

	while (welcomeWin != NULL)
	{
		JamesCurses::wattron(mainWindow, A_BOLD | COLOR_PAIR(JamesOptionPanes::jColor(COLOR_YELLOW, COLOR_BLUE)));
		JamesCurses::mvwprintwCentered(mainWindow, (LINES/2), "Welcome to James' Pointer Power");
		JamesCurses::mvwprintwCentered(mainWindow, (LINES / 2) + 1, "Press <ENTER> To Begin");
		JamesCurses::wattroff(mainWindow, A_BOLD | COLOR_PAIR(JamesOptionPanes::jColor(COLOR_YELLOW, COLOR_BLUE)));


		JamesCurses::wrefresh(mainWindow);

		JamesOptionPanes::hitEnter(mainWindow);
		break;
	}

	JamesCurses::werase(welcomeWin);
	JamesCurses::wrefresh(welcomeWin);
	JamesCurses::delwin(welcomeWin);

	refreshBackground();

	mainMenu();

}

void JamesPP::mainMenu()
{
	int choice = 0;

	JamesOptionPanes::showTitleMessage("James' Pointer Power");
	choice = JamesOptionPanes::showNavMenu(mainWindow, "-MAIN MENU-", "SIGN IN", "DISPLAY LOGO", "GO GALTON", "PLAY GAME", "GAME HISTIORY", "ID INFORMATION", "CREDITS", "STARS", "EXIT");

	switch (choice)
	{
	case 1:
		signIn();
		break;

	case 2:
		displayLogo();
		break;

	case 3:
		goGalton();
		break;

	case 4:
		playGame();
		break;

	case 5:
		displayGameHistory();
		break;

	case 6:
		displayIDInfo();
		break;

	case 7:
		displayCredits();
		break;

	case 8:
		displayStars();
		break;

	case 9:
		farewell();
		break;

	}
}

void JamesPP::signIn()
{

	userName = JamesOptionPanes::showInputMessage(mainWindow, "SIGN IN", "Please enter your name:");
	defaultStatus = ("You are currently signed in as:");
	refreshBackground();

	JamesOptionPanes::showMessage(mainWindow, "WELCOME", "Thank you for joining us " + userName);

	refreshBackground();
	mainMenu();
}

void JamesPP::displayLogo()
{
	WINDOW *logoWindow = JamesCurses::newwin(25, 80, (LINES / 2) - 11, (COLS / 2) - 40);
	JamesCurses::wbox(logoWindow, 0, 0);
	JamesCurses::wbkgd(logoWindow, A_BOLD | COLOR_PAIR(JamesOptionPanes::jColor(COLOR_YELLOW, COLOR_BLACK)));

	JamesCurses::mvwprintwCentered(logoWindow, 2, "THANK YOU FOR VIEWING JAMES' LOGO");
	JamesCurses::mvwprintwCentered(logoWindow, (getmaxy(logoWindow)-3), "Press any key to quit.");

	int c = 0;

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

	while ((JamesCurses::wgetch(logoWindow) == ERR))
	{
		c+=10;
		if (c == 95)
		{
			c = 1;
		}

		//for ever line in the logo
		for (int i = 0; i < 11; i++)
		{
			//for every character in the line
			for (int j = 0; j < 58; j++)
			{
				if ((JamesCurses::wgetch(logoWindow) != ERR))
				{
					goto endLoops;
				}

				switch (logoLines[i][j])
				{
				case 'J':
JamesCurses::wattron(logoWindow, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_RED, COLOR_BLUE)));
JamesCurses::mvwprintw(logoWindow, 6 + i, 9 + j, "J");
JamesCurses::wattroff(logoWindow, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_RED, COLOR_BLUE)));

break;

				case 'D':
					JamesCurses::wattron(logoWindow, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_RED, COLOR_BLUE)));
					JamesCurses::mvwprintw(logoWindow, 6 + i, 9 + j, "D");
					JamesCurses::wattroff(logoWindow, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_RED, COLOR_BLUE)));
					break;

				case 'M':
					JamesCurses::wattron(logoWindow, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_RED, COLOR_BLUE)));
					JamesCurses::mvwprintw(logoWindow, 6 + i, 9 + j, "M");
					JamesCurses::wattroff(logoWindow, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_RED, COLOR_BLUE)));

					break;

				case '.':
					JamesCurses::wattron(logoWindow, COLOR_PAIR(c));
					JamesCurses::mvwprintw(logoWindow, 6 + i, 9 + j, "#");
					JamesCurses::wattroff(logoWindow, COLOR_PAIR(c));
					JamesCurses::wrefresh(logoWindow);

					napms(40);
					break;

				default:
					break;

				}
			}
		}
	}
endLoops:

	JamesCurses::wrefresh(logoWindow);

	refreshBackground();
	mainMenu();

}

void JamesPP::showGalton(WINDOW* win, bool showHistogram)
{
	int ballCount = 1000;
	int boxCount;
	string coolString = "";

	
	box.resize(ballCount);

	int     left_or_right = 0;
	int     counter;
	int     i, j;

	srand(time(NULL));

	for (int k = 0; k < 11; k++)
	{
		coolString = "";
		boxCount = k;



		for (i = 0; i < ballCount; i++)
		{
			box[i] = 0;
		}


		for (i = 0; i < ballCount; i++)
		{
			counter = 0;
			for (j = 0; j < boxCount - 1; j++)
			{

				left_or_right = rand() % 2;
				counter = counter + left_or_right;


			}
			box[counter] = box[counter]++;
		}

		for (i = 0; i <= boxCount; i++)
		{
			wattron(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_WHITE, COLOR_BLACK)));
			JamesCurses::mvwprintwCentered(win, 2 + k, (char*)coolString.c_str());
			wattroff(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_WHITE, COLOR_BLACK)));

			wattron(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_MAGENTA, COLOR_BLACK)));
			JamesCurses::mvwprintw(win, 3 + k, 2, "%i:", k);
			wattroff(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_MAGENTA, COLOR_BLACK)));


			if (box[i] < 100)
			{
				coolString += " ";
			}
			coolString += "   " + to_string(box[i]);

			if (k == 10 && i < 10 && showHistogram == true)
			{

				for (int q = 0; q < 13; q++)
				{
					mvwprintw(win, 28 - q, 11 + i * 6, "|     |");
				}



				for (j = 0; j < box[i]; j++)
				{
					wattron(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_RED, COLOR_RED)));
					mvwprintw(win, 29 - ((j + 5) / 20), 13 + i * 6, "   ");
					wattroff(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_RED, COLOR_RED)));
				}
				wattron(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_MAGENTA, COLOR_BLACK)));
				mvwprintw(win, 30, 11 + i * 6, "|  %i  |", i);
				
				wattroff(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_MAGENTA, COLOR_BLACK)));
			}
		}
	}

		JamesCurses::mvwprintw(win, 13, 2, "   ");
}

void JamesPP::goGalton()
{

	WINDOW* win = JamesOptionPanes::jamesFrame(80, 36);


	JamesPP::showGalton(win, true);

	wattron(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_GREEN, COLOR_BLACK)));
	JamesCurses::mvwprintwCentered(win, 14, "HISTOGRAM");
	JamesCurses::mvwprintwCentered(win, 1, "  GALTON BOARD FLOW");
	JamesCurses::mvwprintwCentered(win, 32, "Press <ESC> to return to main menu");
	JamesCurses::mvwprintwCentered(win, 33, "Press <ENTER> to drop again");
	wattroff(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_GREEN, COLOR_BLACK)));

	for (int t = 0; t < getmaxx(win)-2; t++)
	{
		mvwaddch(win, 13, 1 + t, ACS_HLINE);
		mvwaddch(win, 15, 1+t, ACS_HLINE);
		mvwaddch(win, 31, 1 + t, ACS_HLINE);

		if (t < 61)
		{
			mvwaddch(win, 29, 11 + t, ACS_HLINE);
		}

	}

	for (int i = 0; i < 14; i++)
	{
		wattron(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_MAGENTA, COLOR_BLACK)));
		mvwprintw(win, 29 - i, 8, "%i", i * 20);
		wattroff(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_MAGENTA, COLOR_BLACK)));
	}

	for (int r = 0; r < 61; r+=6)
	{
		mvwaddch(win, 29, 11+r, ACS_PLUS);
		mvwaddch(win, 30, 11 + r, ACS_VLINE);
		mvwaddch(win, 31, 11 + r, ACS_BTEE);

	}

	
	wrefresh(win);

	int keyPress = JamesCurses::wgetch(win);

	//test key input
	if (keyPress == 10)
	{
		touchwin(win);
		wclear(win);
		delwin(win);
		refreshBackground();
		JamesPP::goGalton();
	}

	if (keyPress = 27)
	{
		touchwin(win);
		wclear(win);
		delwin(win);
		refreshBackground();
		mainMenu();
	}
}

void JamesPP::playGame()
{
	WINDOW* win = JamesOptionPanes::jamesFrame(80, 36);
	JamesPP::showGalton(win, false);
	string aString = "";
	double score = 0;
	string scoreString = "";
	



	double values[]{ 126, 14, 3.5, 1.5, 1, 1, 1.5, 3.5, 14, 126 };

	gameNumber += 1;

	wattron(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_MAGENTA, COLOR_BLACK)));
	mvwprintw(win, 14, 2, "WEIGHT:    126    14   3.5   1.5    1     1    1.5   3.5    14   126");
	wattroff(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_MAGENTA, COLOR_BLACK)));
	mvwprintw(win, 16, 2, "SCORE:");

	wattron(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_CYAN, COLOR_BLACK)));
	for (int i = 0; i < 10; i++)
	{



		aString = to_string(box[i] * values[i]);
		aString.erase(aString.find_last_not_of('0') + 1, std::string::npos);
		if (aString.back() == '.')
		{
			aString.pop_back();
		}
		
		
		score += (box[i] * values[i]);
		mvwprintw(win, 16, 13+i*6, (char*)aString.c_str());

	}
	wattroff(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_CYAN, COLOR_BLACK)));

	for (int t = 0; t < getmaxx(win) - 2; t++)
	{
		mvwaddch(win, 13, 1 + t, ACS_HLINE);
		mvwaddch(win, 15, 1 + t, ACS_HLINE);
		mvwaddch(win, 17, 1 + t, ACS_HLINE);
		mvwaddch(win, 30, 1 + t, ACS_HLINE);

	}

	

	scoreString = to_string(score);
	scoreString.erase(scoreString.find_last_not_of('0') + 1, std::string::npos);

	string congrats = "Congratulations, " + userName + "! Your score in game #" + to_string(gameNumber) + " is " + scoreString ;

	ofstream myfile("scores.txt", ios_base::app);
	if (myfile.is_open())
	{
		myfile << scoreString + "\n";
		myfile.close();
	}
	else
	{
		JamesOptionPanes::showMessage(mainWindow, "ERROR", "Unable to open file 'scores.txt'.");
	}

	wattron(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_WHITE, COLOR_BLACK)));
	JamesCurses::mvwprintwCentered(win, 24, (char*)congrats.c_str());
	wattroff(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_WHITE, COLOR_BLACK)));

	wattron(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_GREEN, COLOR_BLACK)));
	JamesCurses::mvwprintwCentered(win, 1, "   PLAY GAME");
	JamesCurses::mvwprintwCentered(win, 32, "Press <ESC> to return to main menu");
	JamesCurses::mvwprintwCentered(win, 33, "Press <ENTER> to drop again");
	wattroff(win, COLOR_PAIR(JamesOptionPanes::jColor(COLOR_GREEN, COLOR_BLACK)));

	wrefresh(win);

	int keyPress = JamesCurses::wgetch(win);

	//test key input
	if (keyPress == 10)
	{
		touchwin(win);
		wclear(win);
		delwin(win);
		
		JamesPP::playGame();
	}

	if (keyPress = 27)
	{
		touchwin(win);
		wclear(win);
		delwin(win);
		refreshBackground();
		mainMenu();
	}

	
}

void JamesPP::displayGameHistory()
{
	WINDOW* win = JamesOptionPanes::jamesFrame(80, 12 + gameNumber);
	string summary = "So far, " + userName + ", you have played " + to_string(gameNumber) + " game(s) with the following scores:";
	string game;
	
	string line;
	vector<string> myLines;
	myLines.clear();

	ifstream myFile("scores.txt", ios_base::in);
	while (getline(myFile, line, '\n'))
	{
		myLines.push_back(line);
	}


	JamesCurses::mvwprintwCentered(win, 4, (char*)summary.c_str());
	JamesCurses::mvwprintwCentered(win, 1, "GAME HISTORY");

	
	for (int i = 1; i <= gameNumber; i++)
	{
		
		if (myLines[i - 1].back() == '.')
		{
			myLines[i - 1].pop_back();
		}

		game = "Game #" + to_string(i) + ": " + myLines[i - 1];


		JamesCurses::mvwprintw(win, 6 + i, 10, (char*)game.c_str());
	}

	JamesCurses::wattron(win, A_BOLD | WA_BLINK);
	JamesCurses::mvwprintw(win, (getmaxy(win) - 3), ((getmaxx(win) / 2) - 4), "CONTINUE");
	JamesCurses::wattroff(win, A_BOLD | WA_BLINK);
	wrefresh(win);

	JamesOptionPanes::hitEnter(win);
	
	touchwin(win);
	wclear(win);
	delwin(win);
	refreshBackground();
	mainMenu();

		//"GAME HISTORY", "So far, " + userName + ", you have played " + to_string(gameNumber) + " games with the following scores: \n\n");
	
	
}

void JamesPP::displayIDInfo()
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

void JamesPP::displayCredits()
{
	JamesOptionPanes::showMessage(
		mainWindow,
		"CREDITS",
		"Put credits here");


	refreshBackground();
	mainMenu();
}

void JamesPP::displayStars()
{
	JamesOptionPanes::showMessage(
		mainWindow,
		"STARS",
		"Put stars here");


	refreshBackground();
	mainMenu();
}

void JamesPP::farewell()
{
	JamesOptionPanes::showMessage(mainWindow, "Farewell", "Farewell, " + userName + ". Thank you for visiting " + MY_NAME + "' Pointer Power!");

	//touchwin(mainWindow);
	//wrefresh(mainWindow);
	//delwin(mainWindow);

	//touchwin(stdscr);
	//wrefresh(stdscr);

	exit(1);

	
}