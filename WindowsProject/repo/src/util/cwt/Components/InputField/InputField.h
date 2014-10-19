#pragma once

#include "../Component.h"
#include <string>

class InputField : public Component
{

public: 
	~InputField()
	{
		touchwin(component);
		delwin(component);
	}
	InputField() :Component() {}
	InputField(int begX, int begY, int len, int wid) :Component(begX, begY, len, wid)
	{
		//CREATE BORDER////////////////
		wattron(component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLACK, COLOR_WHITE)));
		box(component, 0, 0);
		wattroff(component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLACK, COLOR_WHITE)));

		wattron(component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_WHITE, COLOR_WHITE)));
		for (int i = 1; i < (width - 1); i++)
		{
			mvwaddch(component, i, (length - 1), ACS_VLINE);
		}

		for (int i = 1; i < (length - 1); i++)
		{
			mvwaddch(component, width - 1, i, ACS_HLINE);
		}
		mvwaddch(component, width - 1, length - 1, ACS_LRCORNER);
		mvwaddch(component, 0, length - 1, ACS_URCORNER);
		wattroff(component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_WHITE, COLOR_WHITE)));
		/////////////////////////////////

		setBackground(COLOR_WHITE);
		setForeground(COLOR_BLACK);



		curs_set(1);
		echo();

		mvwprintw(component, 1, 1, " ");
		wrefresh(component);
		
		
	}

	inline std::string getInput();

private:
	std::string inputString;

};

inline std::string InputField::getInput()
{
	char inputC[80];

	wgetstr(component, inputC);

	curs_set(0);
	noecho();

	return (std::string)inputC;
}