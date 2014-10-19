#include "ButtonMenu.h"

//void CButton::highlight()
//{
//
//}

ButtonMenu::~ButtonMenu()
{
	//touchwin(component);
	//werase(component);
	//wrefresh(component);
	
	//delwin(component);
}

void ButtonMenu::CButton::drawButton(WINDOW* c)
{
	//parentWindow = c;
	std::string buttonText = name;

	if (position == BUTTON_POSITION_MIDDLE)
	{
		//buttonText = "< " + buttonText + " >";
		wattron(c, A_BOLD | COLOR_PAIR(cwt::colorPair(FGHighlightColor, highlightColor)));
		mvwprintw(c, getmaxy(c) - 2, (getmaxx(c) / 2) - (buttonText.length() / 2), (char*)buttonText.c_str());
		wattroff(c, A_BOLD | COLOR_PAIR(cwt::colorPair(FGHighlightColor, highlightColor)));
	}

	if (position == BUTTON_POSITION_LEFT)
	{
		//buttonText = "< " + buttonText + " >";
		wattron(c, A_BOLD | COLOR_PAIR(cwt::colorPair(FGHighlightColor, highlightColor)));
		mvwprintw(c, getmaxy(c) - 2, 5, (char*)buttonText.c_str());
		wattroff(c, A_BOLD | COLOR_PAIR(cwt::colorPair(FGHighlightColor, highlightColor)));
	}

	if (position == BUTTON_POSITION_RIGHT)
	{
		//buttonText = "< " + buttonText + " >";
		wattron(c, A_BOLD | COLOR_PAIR(cwt::colorPair(FGHighlightColor, highlightColor)));
		mvwprintw(c, getmaxy(c) - 2, getmaxx(c) - (buttonText.length()) - 5, (char*)buttonText.c_str());
		wattroff(c, A_BOLD | COLOR_PAIR(cwt::colorPair(FGHighlightColor, highlightColor)));
	}

	if (position == BUTTON_POSITION_DOUBLE_LEFT)
	{

		//buttonText = "< " + buttonText + " >";
		wattron(c, A_BOLD | COLOR_PAIR(cwt::colorPair(FGHighlightColor, highlightColor)));
		mvwprintw(c, getmaxy(c) - 2, (getmaxx(c) / 2) - (buttonText.length())-2, (char*)buttonText.c_str());
		wattroff(c, A_BOLD | COLOR_PAIR(cwt::colorPair(FGHighlightColor, highlightColor)));

	}

	if (position == BUTTON_POSITION_DOUBLE_RIGHT)
	{
		//buttonText = "< " + buttonText + " >";
		wattron(c, A_BOLD | COLOR_PAIR(cwt::colorPair(FGHighlightColor, highlightColor)));
		mvwprintw(c, getmaxy(c)-2, (getmaxx(c) /2) + 5, (char*)buttonText.c_str());
		wattroff(c, A_BOLD | COLOR_PAIR(cwt::colorPair(FGHighlightColor, highlightColor)));
	}

	wrefresh(c);
}
