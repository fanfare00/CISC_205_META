#pragma once

#include "../Component.h"
#include <string>

class InputField : public Component
{

public: 
	InputField() :Component() {}
	InputField(int begX, int begY, int len, int wid) :Component(begX, begY, len, wid)
	{
		//CREATE BORDER////////////////
		wattron(this->component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLACK, COLOR_WHITE)));
		box(this->component, 0, 0);
		wattroff(this->component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLACK, COLOR_WHITE)));

		wattron(this->component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_WHITE, COLOR_WHITE)));
		for (int i = 1; i < (width - 1); i++)
		{
			mvwaddch(this->component, i, (length - 1), ACS_VLINE);
		}

		for (int i = 1; i < (length - 1); i++)
		{
			mvwaddch(this->component, width - 1, i, ACS_HLINE);
		}
		mvwaddch(this->component, width - 1, length - 1, ACS_LRCORNER);
		mvwaddch(this->component, 0, length - 1, ACS_URCORNER);
		wattroff(this->component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_WHITE, COLOR_WHITE)));
		/////////////////////////////////

		setBackground(COLOR_WHITE);
		setForeground(COLOR_BLACK);



		curs_set(1);
		echo();

		mvwprintw(this->component, 1, 1, " ");
		wrefresh(this->component);
		
		
	}

	inline std::string getInput();

private:
	std::string inputString;

};

inline std::string InputField::getInput()
{
	char inputC[80];

	wgetstr(this->component, inputC);

	curs_set(0);
	noecho();

	return (std::string)inputC;
}