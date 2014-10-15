#pragma once

#include "../Component.h"
#include "../../Color/Color.h"
#include <string>


class TextArea : public Component
{


public:
	TextArea() :Component() {}
	TextArea(int begX, int begY, int len, int wid) :Component(begX, begY, len, wid)
	{
		internalTextArea = newwin(this->width - 2, this->length - 2, this->y + 1, this->x + 1);
		

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

	}
	inline void addText(std::string textStr);
	inline void addText(int x, int y, std::string textStr);

	WINDOW* internalTextArea;


};

inline void TextArea::addText(std::string textStr)
{
	wattron(this->component, COLOR_PAIR(cwt::colorPair(COLOR_BLACK, COLOR_WHITE)));
	mvwprintw(this->component, 1, 1, (char*)textStr.c_str());
	wattroff(this->component, COLOR_PAIR(cwt::colorPair(COLOR_BLACK, COLOR_WHITE)));

	wrefresh(this->component);

}

inline void TextArea::addText(int x, int y, std::string textStr)
{
	

	wbkgd(internalTextArea,COLOR_PAIR(cwt::colorPair(COLOR_BLACK, this->backgroundColor)));
	wattron(internalTextArea, COLOR_PAIR(cwt::colorPair(COLOR_BLACK, COLOR_WHITE)));
	mvwprintw(internalTextArea, y, x, (char*)textStr.c_str());
	wattroff(internalTextArea, COLOR_PAIR(cwt::colorPair(COLOR_BLACK, COLOR_WHITE)));

	wrefresh(internalTextArea);

}