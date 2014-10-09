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

"JamesOptionPanes.cpp" DESCRIPTION



********************************************************************************
********************************************************************************

CUSTOM-DEFINED FUNCTION LIST




********************************************************************************
********************************************************************************

CREDITS




********************************************************************************
********************************************************************************
********************************************************************************/

#include "JamesOptionPanes.h"
#include "JamesCurses.h"
#include <stdio.h>
#include <time.h>
#include "ConsoleWordWrapper.h"

WINDOW* JamesOptionPanes::setUp(int scrHeight, int scrWidth)
{
	WINDOW* mainWindow = JamesCurses::initscr();
	JamesCurses::noecho();
	JamesCurses::cbreak();
	JamesCurses::curs_set(0);
	JamesCurses::resize_term(scrHeight, scrWidth);

	loadColors();

	return mainWindow;
}

void JamesOptionPanes::loadColors()
{
	JamesCurses::start_color();

	for (int foreColor = 0; foreColor < 8; foreColor++)
	{
		for (int backColor = 0; backColor < 8; backColor++)
		{
			init_pair((foreColor * 10) + backColor, foreColor, backColor);
		}
	}

}

int JamesOptionPanes::jColor(int foreColor, int backColor)
{
	return (foreColor*10) + backColor;
}

void JamesOptionPanes::showDateTime(WINDOW* win, int y, int x)
{

	char date[9];
	char time[9];

	_strdate_s(date);
	_strtime_s(time);

	
	JamesCurses::mvwprintw(win, y,  x, "Date: %s", date);
	JamesCurses::mvwprintw(win, y+1, x, "Time: %s", time);
	 
}


string JamesOptionPanes::showInputMessage(WINDOW* parentWindow, string title, string message)
{
	WINDOW* win = JamesOptionPanes::jamesFrame(getWidthFromString(message), getHeightFromString(message)+3);
	char * cMessage = (char*)message.c_str();
	char userInput[80];
	int startingLine = 0;

	ConsoleWordWrapper::formatString(&message, 80);
	
	WINDOW* textArea = JamesCurses::newwin((getmaxy(win) - 6), (getmaxx(win) - 4), (getbegy(win) + 3), (getbegx(win) + 2));
	WINDOW* titleArea = JamesCurses::newwin(1, (getmaxx(win) - 4), (getbegy(win) + 1), (getbegx(win) + 2));

	if (message.length() <= 80)
	{
		startingLine = (getmaxx(textArea) / 2) - (message.length() / 2);
	}


	JamesCurses::curs_set(1);
	JamesCurses::echo();

	JamesCurses::wattron(win, A_BOLD | WA_BLINK);
	JamesCurses::mvwprintw(win, (getmaxy(win) - 3), ((getmaxx(win) / 2) - 4), "CONTINUE");
	JamesCurses::wattroff(win, A_BOLD | WA_BLINK);


	JamesCurses::mvwprintw(titleArea, 0, (getmaxx(titleArea) / 2) - (title.length() / 2), (char*)title.c_str());
	JamesCurses::mvwprintw(textArea, 1, startingLine, (char*)message.c_str());
	

	JamesCurses::wrefresh(win);
	JamesCurses::wrefresh(textArea);
	JamesCurses::wrefresh(titleArea);

	WINDOW *inputBox = JamesCurses::newwin(3, (getmaxx(win) - 8),    (getbegy(win) + getmaxy(win) - 8)                    , (getbegx(win)+4));
	JamesCurses::mvwprintw(inputBox, 1, 1, " ");
	JamesCurses::wbox(inputBox, 0, 0);
	JamesCurses::wrefresh(inputBox);

	wgetstr(inputBox, userInput);
	JamesCurses::werase(win);
	JamesCurses::werase(inputBox);
	JamesCurses::werase(textArea);
	JamesCurses::delwin(win);
	JamesCurses::delwin(inputBox);
	JamesCurses::delwin(textArea);

	JamesCurses::curs_set(0);
	JamesCurses::noecho();

	

	return (string)userInput;
}


void JamesOptionPanes::showMessage(WINDOW* parentWindow, string title, string message)
{
	int startingLine = 0;



	ConsoleWordWrapper::formatString(&message, 80);

	

	WINDOW* win = JamesOptionPanes::jamesFrame(getWidthFromString(message), getHeightFromString(message));
	WINDOW* textArea = JamesCurses::newwin( (getmaxy(win) - 6), (getmaxx(win) - 4), (getbegy(win) + 3), (getbegx(win) + 2) );
	WINDOW* titleArea = JamesCurses::newwin(1,                  (getmaxx(win) - 4), (getbegy(win) + 1), (getbegx(win) + 2) );

	if (message.length() <= 80)
	{
		startingLine = (getmaxx(textArea) / 2) - (message.length() / 2);
	}

	JamesCurses::wattron(win, A_BOLD | WA_BLINK);
	JamesCurses::mvwprintw(win,(getmaxy(win)-3), ((getmaxx(win)/2) - 4), "CONTINUE");
	JamesCurses::wattroff(win, A_BOLD | WA_BLINK);

	JamesCurses::mvwprintw(titleArea, 0, (getmaxx(titleArea) / 2) - (title.length() / 2), (char*)title.c_str());
	JamesCurses::mvwprintw(textArea, 1, startingLine, (char*)message.c_str());
	
	JamesCurses::wrefresh(win);
	JamesCurses::wrefresh(titleArea);
	JamesCurses::wrefresh(textArea);

	
	JamesOptionPanes::hitEnter(win);
	JamesCurses::werase(win);

}

void JamesOptionPanes::showLargeMessage(WINDOW* parentWindow, string title, string message)
{
	WINDOW* win = largeMessageFrame();
	WINDOW* textArea = derwin(win, 16, 71, 0, 2);
	 
	



	char* cTitle = (char*)title.c_str();
	char* cMessage = (char*)message.c_str();

	JamesCurses::wattron(win, A_BOLD | WA_BLINK);
	JamesCurses::mvwprintwCentered(win, 17, "CONTINUE");
	JamesCurses::wattroff(win, A_BOLD | WA_BLINK);

	JamesCurses::mvwprintwCentered(textArea, 2, cTitle);
	JamesCurses::mvwprintw(textArea, 4, 1, cMessage);

	JamesCurses::wrefresh(textArea);
	JamesCurses::wrefresh(win);

	JamesOptionPanes::hitEnter(win);


}

WINDOW* JamesOptionPanes::titleBox()
{
	WINDOW *win = JamesCurses::newwin(5, 40, 2, (COLS/2) - 20);
	WINDOW *shadowWin = JamesCurses::newwin(5, 40, 3, (COLS / 2) - 19);
	JamesCurses::wbox(win, 0, 183);

	//JamesCurses::wbkgd(win, COLOR_PAIR(jColor(COLOR_BLACK, COLOR_GREEN)));
	JamesCurses::wbkgd(win, COLOR_PAIR(jColor(COLOR_BLACK, COLOR_GREEN)));



	JamesCurses::wrefresh(shadowWin);
	JamesCurses::wrefresh(win);
	

	return win;
}

void JamesOptionPanes::showTitleMessage(string title)
{
	WINDOW* titleBox = JamesOptionPanes::titleBox();
		JamesCurses::mvwprintw(titleBox, 2, getCenterX(titleBox, title), (char*)title.c_str());
		JamesCurses::wrefresh(titleBox);
}

int JamesOptionPanes::getCenterX(WINDOW* win, string text)
{

	return (getmaxx(win) / 2) - (text.length()/2);
}

bool JamesOptionPanes::showConfirmationMessage(WINDOW* parWindow, string title, string message)
{
	string menuItems[] = {

		"Continue",
		"Back"
	};

	int menuItemSelection;

	WINDOW *win = JamesCurses::newwin(10, 50, (getmaxy(parWindow)/2) - 5, (getmaxx(parWindow)/2) - 50/2);

	menuItemSelection = navigationMenu(win, menuItems, 2);
	JamesCurses::wrefresh(win);
	if (menuItemSelection == 1)
	{

		return true;
	}

	return false;

}

int JamesOptionPanes::getWidthFromString(string message)
{
	int messageLength = message.length();
	int width = 0;

	int j = 0;
	int k = 50;
	if (messageLength <= 80)
	{
		if (messageLength - 46 <= 0)
		{
			width = 0;
		}
		else
		{
			width = (messageLength - 46);
		}
	}

	for (size_t i = 0; i < messageLength; i++)
	{


		if (j == 80)
		{
			
			j = 0;
		}


		if ((message[i] == '\n'))
		{
			
			j = 0;
		}
		else
		{
			j++;
		}

		if (j >= k)
		{
			k = j;
		}
	}
	width = k + 4;
	return width;

}

int JamesOptionPanes::getHeightFromString(string message)
{
	int messageLength = message.length();
	int height = 10;

	int j = 0;
	int k = 50;

	for (size_t i = 0; i < messageLength; i++)
	{


		if (j == 80)
		{
			height += 1;
			j = 0;
		}


		if ((message[i] == '\n'))
		{
			height += 1;
			j = 0;
		}
		else
		{
			j++;
		}

		if (j >= k)
		{
			k = j;
		}
	}

	
	return height;

}

WINDOW* JamesOptionPanes::jamesFrame(int width, int height)
{

	WINDOW *win = JamesCurses::newwin(height, width, ((getmaxy(stdscr) / 2) - (height) / 2), (getmaxx(stdscr) / 2) - (( width) / 2));
		JamesCurses::wbox(win, 0, 0);
		JamesCurses::wbkgd(win, A_BOLD | COLOR_PAIR(jColor(COLOR_YELLOW, COLOR_BLACK)));

		mvwaddch(win, 2, 0, ACS_LTEE);
		mvwaddch(win, 2, width-1, ACS_RTEE);

		for (int i = 1; i <= (width-2); i++)
		{
			mvwaddch(win, 2, i, ACS_HLINE);
		}

	return win;
}


WINDOW* JamesOptionPanes::largeMessageFrame()
{
	WINDOW *win = JamesCurses::newwin(25, 80, (LINES/2) - 12, (COLS/2) - 40);
		JamesCurses::wbox(win, 0, 0);
		JamesCurses::wbkgd(win, A_BOLD | COLOR_PAIR(jColor(COLOR_YELLOW, COLOR_BLACK)));

	return win;
}



int JamesOptionPanes::navigationMenu(WINDOW *win, string menuItems[], int numMenuItems)
{
	int highlight = 1;
	int choice = 0;
	int keyPress;

	int n_menuChoices = numMenuItems;

	keypad(win, TRUE);


	printMenuItems(win, menuItems, numMenuItems, highlight);

	//infinite loop
	while (true)
	{
		//pause for key input
		keyPress = wgetch(win);

		//test key input
		switch (keyPress)
		{

			//if key up 
		case KEY_UP:
			//if 
			if (highlight == 1)
			{
				highlight = n_menuChoices;
			}
			else
			{
				--highlight;
			}
			break;

			//if key down
		case KEY_DOWN:
			if (highlight == n_menuChoices)
			{
				highlight = 1;
			}
			else
			{
				++highlight;
			}
			break;

			//if ENTER key
		case 10:
			//set user choice to highlighted choice
			choice = highlight;
			break;

		default:
			//mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", keyPress, keyPress);
			refresh();
			break;
		}

		printMenuItems(win, menuItems, numMenuItems, highlight);
		if (choice != 0)	// User did a choice come out of the infinite loop 
		{
			break;
		}

	}

	return choice;

}

void JamesOptionPanes::printMenuItems(WINDOW *win, string menuItems[], int numMenuItems, int highlight)
{
	int n_menuChoices = numMenuItems;

	int x, y, i;

	x = 7;
	y = 5;

	JamesCurses::wbox(win, 0, 0);


	for (i = 0; i < n_menuChoices; ++i)
	{
		if (highlight == i + 1) /* High light the present choice */
		{
			
			JamesCurses::wattron(win,  COLOR_PAIR(jColor(COLOR_WHITE, COLOR_YELLOW)));
			JamesCurses::mvwprintw(win, y, x, (char*)menuItems[i].c_str());
			JamesCurses::wattroff(win,   COLOR_PAIR(jColor(COLOR_WHITE, COLOR_YELLOW)));
		}
		else
			
			JamesCurses::mvwprintw(win, y, x, (char*)menuItems[i].c_str());
			
		y++;
	}

	JamesCurses::wrefresh(win);
}

void JamesOptionPanes::hitEnter(WINDOW *win)
{
	int keyPress;
	

	while (true)
	{
		//pause for key input
		keyPress = JamesCurses::wgetch(win);

		//test key input
		if (keyPress == 10)
		{
			break;
		}

	}

}

