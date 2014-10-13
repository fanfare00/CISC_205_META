#include "ButtonMenu.h"

//void CButton::highlight()
//{
//
//}

void CButton::drawButton(WINDOW* c)
{
	parentWindow = c;
	std::string buttonText = this->name;



	buttonText = "< " + buttonText + " >";
	wattron(c, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_WHITE, COLOR_BLUE)));
	mvwprintw(c, 1, (getmaxx(c) / 2) - (buttonText.length() / 2), (char*)buttonText.c_str());
	wattroff(c, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_WHITE, COLOR_BLUE)));

	wrefresh(c);
}