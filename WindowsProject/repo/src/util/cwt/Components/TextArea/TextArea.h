#pragma once

#include "../Component.h"
#include "../../Color/Color.h"
#include <string>


class TextArea : public Component
{


public:
	~TextArea()
	{
		//delwin(internalTextArea);
		//delwin(component);
	}
	TextArea() :Component() {}
	TextArea(int begX, int begY, int len, int wid) :Component(begX, begY, len, wid)
	{
		internalTextArea = newwin(width - 2, length - 2, y + 1, x + 1);
		

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

	}
	inline void addText(std::string textStr);
	inline void addText(int x, int y, std::string textStr);

	WINDOW* internalTextArea;


};

inline void TextArea::addText(std::string textStr)
{
	wattron(component, COLOR_PAIR(cwt::colorPair(COLOR_BLACK, COLOR_WHITE)));
	mvwprintw(component, 1, 1, (char*)textStr.c_str());
	wattroff(component, COLOR_PAIR(cwt::colorPair(COLOR_BLACK, COLOR_WHITE)));

	wrefresh(component);

}

inline void TextArea::addText(int x, int y, std::string textStr)
{
	

	wbkgd(internalTextArea,COLOR_PAIR(cwt::colorPair(COLOR_BLACK, backgroundColor)));
	wattron(internalTextArea, COLOR_PAIR(cwt::colorPair(COLOR_BLACK, COLOR_WHITE)));
	mvwprintw(internalTextArea, y, x, (char*)textStr.c_str());
	wattroff(internalTextArea, COLOR_PAIR(cwt::colorPair(COLOR_BLACK, COLOR_WHITE)));

	wrefresh(internalTextArea);

}