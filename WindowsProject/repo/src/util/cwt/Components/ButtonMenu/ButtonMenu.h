#pragma once

#include "../../Frames/Frame.h"
#include <vector>
#include <string>

#define BUTTON_POSITION_MIDDLE 0
#define BUTTON_POSITION_LEFT 1
#define BUTTON_POSITION_RIGHT 2

#define BUTTON_POSITION_DOUBLE_LEFT 3
#define BUTTON_POSITION_DOUBLE_RIGHT 4

class ButtonMenu : public Component
{
public:
	ButtonMenu();

	template<typename... Arguments>
	ButtonMenu(int begX, int begY, int len, int wid, Arguments&... args) :Component(begX, begY, len, wid)
	{
		std::vector<std::string> buttons = { args... };

		nButtons = buttons.size();
		setBackground(COLOR_WHITE);

		drawBorder();

		addButtons(buttons);
		//int pp = getButtonChoice();

	}

	//ButtonMenu(int begX, int begY, int len, int wid, std::vector<std::string> buttons) :Component(begX, begY, len, wid)
	//{
	//	nButtons = buttons.size();
	//	setBackground(COLOR_WHITE);

	//	drawBorder();

	//	addButtons(buttons);
	//	//int pp = getButtonChoice();

	//}

	~ButtonMenu();
	
	inline void drawBorder();
	inline void addButtons(std::vector<std::string> buttons);

	int nButtons;
	int buttonSpace = 0;
	

	struct CButton
	{
		WINDOW* parentWindow;
		std::string name;
		
		int highlightColor;
		int FGHighlightColor = COLOR_BLACK;

		void drawButton(WINDOW* c);
		//void highlight();

		int position;
		int choice;
	};

	std::vector<CButton> CButtons;
	inline int getButtonChoice();

};




inline void ButtonMenu::addButtons(std::vector<std::string> buttons)
{
	CButton b1;
	CButton b2;
	CButton b3;



	if (nButtons == 1)
	{
		b1.name = buttons[0];
		b1.position = BUTTON_POSITION_MIDDLE;
		b1.highlightColor = COLOR_BLUE;
		b1.FGHighlightColor = COLOR_WHITE;
	}

	if (nButtons == 2)
	{
		b1.name = buttons[0];
		b1.position = BUTTON_POSITION_DOUBLE_LEFT;
		b1.highlightColor = COLOR_BLUE;
		b1.FGHighlightColor = COLOR_WHITE;


		b2.name = buttons[1];
		b2.position = BUTTON_POSITION_DOUBLE_RIGHT;
		b2.highlightColor = this->backgroundColor;
	}

	if (nButtons == 3)
	{
		b1.name = buttons[0];
		b1.position = BUTTON_POSITION_LEFT;
		b1.highlightColor = COLOR_BLUE;
		b1.FGHighlightColor = COLOR_WHITE;

		b2.name = buttons[1];
		b2.position = BUTTON_POSITION_MIDDLE;
		b2.highlightColor = this->backgroundColor;

		b3.name = buttons[2];
		b3.position = BUTTON_POSITION_RIGHT;
		b3.highlightColor = this->backgroundColor;
	}

	b1.drawButton(this->component);
	b2.drawButton(this->component);
	b3.drawButton(this->component);

	 CButtons = { b1, b2, b3 };

	 wrefresh(this->component);

}

inline int ButtonMenu::getButtonChoice()
{

	int highlight = 0;
	int choice;

	while (true)
	{
		switch (wgetch(stdscr))
		{
		case  KEY_LEFT:

			if (highlight == 0)
			{
				highlight = nButtons-1;
			}
			else
			{
				--highlight;
			}

			//CButtons[0].highlightColor = COLOR_BLUE;
			//CButtons[1].highlightColor = this->backgroundColor;
			break;

		case KEY_RIGHT:

			if (highlight == nButtons-1)
			{
				highlight = 0;
			}
			else
			{
				++highlight;
			}

			/*CButtons[0].highlightColor = this->backgroundColor;
			CButtons[1].highlightColor = COLOR_BLUE;*/
			break;

		case  10:
			choice = highlight+1;
			break;
		}

		CButtons[0].highlightColor = this->backgroundColor;
		CButtons[1].highlightColor = this->backgroundColor;
		CButtons[2].highlightColor = this->backgroundColor;

		CButtons[0].FGHighlightColor = COLOR_BLACK;
		CButtons[1].FGHighlightColor = COLOR_BLACK;
		CButtons[2].FGHighlightColor = COLOR_BLACK;


		CButtons[highlight].highlightColor = COLOR_BLUE;
		CButtons[highlight].FGHighlightColor = COLOR_WHITE;

		CButtons[0].drawButton(this->component);
		CButtons[1].drawButton(this->component);
		CButtons[2].drawButton(this->component);

		if (choice != 0)
		{
			break;
		}

	}
	return choice;

}



inline void ButtonMenu::drawBorder()
{
	//CREATE BORDER////////////////
	wattron(this->component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_WHITE, COLOR_WHITE)));
	box(this->component, 0, 0);
	mvwaddch(this->component, 0, 0, ACS_LTEE);
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
	mvwaddch(this->component, 0, length - 1, ACS_RTEE);
	wattroff(this->component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_BLACK, COLOR_WHITE)));
	/////////////////////////////////



}

//template<typename... Arguments>