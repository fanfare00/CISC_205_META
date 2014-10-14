#include "ButtonMenu.h"

//void CButton::highlight()
//{
//
//}

int ButtonMenu::getButtonChoice()
{
	while (wgetch(this->component) != 10)
	{


	}

	return 0;
}

void ButtonMenu::CButton::drawButton(WINDOW* c)
{
	parentWindow = c;
	std::string buttonText = this->name;


	if (position == 0)
	{
		buttonText = "< " + buttonText + " >";
		wattron(c, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLACK, highlightColor)));
		mvwprintw(c, 1, (getmaxx(c) / 2) - (buttonText.length() / 2), (char*)buttonText.c_str());
		wattroff(c, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLACK, highlightColor)));
	}

	if (position == 1)
	{
		buttonText = "< " + buttonText + " >";
		wattron(c, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLACK, highlightColor)));
		mvwprintw(c, 1, 5, (char*)buttonText.c_str());
		wattroff(c, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLACK, highlightColor)));
	}

	if (position == 2)
	{
		buttonText = "< " + buttonText + " >";
		wattron(c, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLACK, highlightColor)));
		mvwprintw(c, 1, getmaxx(c) - (buttonText.length()) - 5, (char*)buttonText.c_str());
		wattroff(c, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLACK, highlightColor)));
	}

	if (position == 3)
	{
		buttonText = "< " + buttonText + " >";
		wattron(c, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLACK, highlightColor)));
		mvwprintw(c, 1, (getmaxx(c) / 2) - (buttonText.length()) - 5, (char*)buttonText.c_str());
		wattroff(c, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLACK, highlightColor)));
	}

	if (position == 4)
	{
		buttonText = "< " + buttonText + " >";
		wattron(c, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLACK, highlightColor)));
		mvwprintw(c, 1, (getmaxx(c) /2) + 5, (char*)buttonText.c_str());
		wattroff(c, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLACK, highlightColor)));
	}



	wrefresh(c);
}