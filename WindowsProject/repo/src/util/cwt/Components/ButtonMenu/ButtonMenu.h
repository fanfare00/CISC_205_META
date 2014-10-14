#pragma once

#include "../../Frames/Frame.h"
#include <vector>
#include <string>

#define BUTTON_POSITION_MIDDLE 0
#define BUTTON_POSITION_LEFT 1
#define BUTTON_POSITION_RIGHT 2

#define BUTTON_POSITION_DOUBLE_LEFT 3
#define BUTTON_POSITION_DOUBLE_RIGHT 4

class ButtonMenu : Component
{
public:
	ButtonMenu(int begX, int begY, int len, int wid, std::vector<std::string> buttons) :Component(begX, begY, len, wid)
	{
		
		nButtons = buttons.size();
		setBackground(COLOR_WHITE);


		drawBorder();



		//mvwprintw(this->component, 1, 20, "TEST");

		addButtons(buttons);

	}



	inline void drawBorder();
	inline void addButtons(std::vector<std::string> buttons);
	int getButtonChoice();


	int nButtons;
	int buttonSpace = 0;
	

	struct CButton
	{
		WINDOW* parentWindow;
		std::string name;
		
		int highlightColor;
		void drawButton(WINDOW* c);
		//void highlight();

		int position;
		int choice;
	};

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
		b1.highlightColor = this->backgroundColor;
	}

	if (nButtons == 2)
	{
		b1.name = buttons[0];
		b1.position = BUTTON_POSITION_DOUBLE_LEFT;
		b1.highlightColor = this->backgroundColor;
		

		b2.name = buttons[1];
		b2.position = BUTTON_POSITION_DOUBLE_RIGHT;
		b2.highlightColor = this->backgroundColor;
	}

	if (nButtons == 3)
	{
		b1.name = buttons[0];
		b1.position = BUTTON_POSITION_LEFT;
		b1.highlightColor = COLOR_WHITE;

		b2.name = buttons[1];
		b2.position = BUTTON_POSITION_MIDDLE;
		b2.highlightColor = this->backgroundColor;

		b3.name = buttons[2];
		b3.position = BUTTON_POSITION_RIGHT;
		b3.highlightColor = this->backgroundColor;
	}


	while (true)
	{

		b1.drawButton(this->component);
		b2.drawButton(this->component);
		b3.drawButton(this->component);



		//pause for key input
		int keyPress = wgetch(this->component);

		//test key input
		if (keyPress == 10)
		{
			break;
		}
	}

	/*CButton b;
	b.name = buttonText;
	b.choice = pos;

	if (nButtons == 2)
	{
		pos += 4;
	}

	b.position = pos;
	b.drawButton(this->component);*/


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