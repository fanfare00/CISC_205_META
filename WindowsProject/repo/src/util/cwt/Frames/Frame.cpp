#include "Frame.h"

//ButtonMenu Frame::addButtonMenu()
//{
//
//}

TextArea Frame::addTextArea()
{
	TextArea TA(x + 2, y + 2, length - 4, width - 3);

	return TA;
}

void Frame::addTextArea(std::string testStr)
{
	TextArea TA(x + 2, y + 2, length - 4, width - 3);

	TA.addText(testStr);
}

void Frame::addTextArea(int startX, int startY, int aLength, int aWidth, std::string testStr)
{
	TextArea TA(startX + 2, startY + 2, aLength - 4, aWidth - 4);

	TA.addText(testStr);
}

void Frame::drawBorder()
{
	//CREATE BORDER////////////////
	wattron(this->component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_WHITE, COLOR_WHITE)));
	box(this->component, 0, 0);
	wattroff(this->component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_WHITE, COLOR_WHITE)));


	wattron(this->component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLACK, COLOR_WHITE)));
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
	wattroff(this->component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLACK, COLOR_WHITE)));
	/////////////////////////////////

	//ADD TITLE//////////////////////
	wattron(this->component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLUE, COLOR_WHITE)));
	mvwprintw(this->component, 0, ((length / 2) - (frameTitle.length() / 2)), (char*)frameTitle.c_str());
	wattroff(this->component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLUE, COLOR_WHITE)));
	////////////////////////////////
}

//void Frame::addButtonMenu(std::string b1Text)
//{
//	width += 3;
//	ButtonMenu bMenu(x, y + width - 4, length, 3, b1Text);
//
//	//return bMenu;
//}
//
//void Frame::addButtonMenu(std::string b1Text, std::string b2Text)
//{
//	width += 3;
//	ButtonMenu bMenu(x, y + width - 4, length, 3, b1Text, b2Text);
//
//	//return bMenu;
//}
//
//void Frame::addButtonMenu(std::string b1Text, std::string b2Text, std::string b3Text)
//{
//	width += 3;
//	ButtonMenu bMenu(x, y + width - 4, length, 3, b1Text, b2Text, b3Text);
//
//	//return bMenu;
//}