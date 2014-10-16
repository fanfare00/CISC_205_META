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

"JamesOptionPanes.h" DESCRIPTION



********************************************************************************
********************************************************************************

CUSTOM-DEFINED FUNCTION LIST




********************************************************************************
********************************************************************************

CREDITS




********************************************************************************
********************************************************************************
********************************************************************************/
#pragma once

#include <string>
#include "curses.h"
using namespace std;

class JamesOptionPanes
{
public: 

	static WINDOW* setUp(int scrHeight, int scrWidth);
	//static void loadColors();
	static void colorOn();
	static void colorOff();

	static void showDateTime(WINDOW* win, int y, int x);


	static bool popUpConfirm(char* choice);

	/*static void inputPopUpWindow(char* prompt);*/
	static WINDOW* titleBox();
	static WINDOW* jamesFrame(int width, int height);
	static WINDOW* largeMessageFrame();
	

	static int getWidthFromString(string message);
	static int getHeightFromString(string message);

	//NAME:
	//DESCRIPTION:
	static void hitEnter(WINDOW* win);

	//NAME:
	//DESCRIPTION:
	static int navigationMenu(WINDOW *win, string menuItems[], int numMenuItems);

	//NAME:
	//DESCRIPTION:
	static void printMenuItems(WINDOW *win, string menuItems[], int numMenuItems, int highlight);

	//NAME:
	//DESCRIPTION:
	static string showInputMessage(WINDOW* parentWindow, string title, string message);

	//NAME:
	//DESCRIPTION:
	static bool showConfirmationMessage(WINDOW* parentWindow, string title, string message);

	//NAME:
	//DESCRIPTION:
	static void showMessage(WINDOW* parentWindow, string title, string message);

	//NAME:hi
	//DESCRIPTION: 
	static void showLargeMessage(WINDOW* parentWindow, string title, string message);

	//NAME:
	//DESCRIPTION:
	static void JamesOptionPanes::showTitleMessage(string title);

	static int getCenterX(WINDOW* win, string text);

	//static int JamesColor::colorPair(int foreColor, int backColor);

	template<typename... Arguments>
	static int showNavMenu(WINDOW* parentWindow, string title, Arguments&... args)
	{
		int choice;
		char* cTitle = (char*)title.c_str();

		string menuItems[] = { args... };
		int nMenuItems = sizeof...(Arguments);

		WINDOW *menuFrame = newwin(7+nMenuItems, 40, 14, (COLS / 2) - 20);
		WINDOW *shadowWin = newwin(7 + nMenuItems, 40, 15, (COLS / 2) - 19);
		wbkgd(menuFrame, COLOR_PAIR(cwt::colorPair(COLOR_BLACK, COLOR_YELLOW)));
		mvwprintw(menuFrame, 2, (getmaxx(menuFrame)/2) - (title.length())/2, cTitle);
		wrefresh(shadowWin);
		wrefresh(menuFrame);

		choice = JamesOptionPanes::navigationMenu(menuFrame, menuItems, nMenuItems);


		return choice;

	}


	enum class Color
	{
		None = 0,
		Red_Black = 1,
		Green_Black = 2,
		Magenta_Black = 3,
		Cyan_Black = 4,
		Yellow_Black = 5,
		White_Black = 6,
		White_Green = 7,
		White_Yellow = 8,
		White_Red = 9,
		Black_Black = 10,
		Yellow_Red = 11,
		Blue_Cyan = 12,
		Yellow_Cyan = 13,
		Blue_Green = 14,
		Green_Yellow = 15,
		Blue_Yellow = 16,
		Green_Cyan = 17,
		Black_Green = 18

	};
};

