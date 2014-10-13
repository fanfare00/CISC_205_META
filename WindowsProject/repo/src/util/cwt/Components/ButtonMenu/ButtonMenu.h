#pragma once

#include "../../Frames/Frame.h"
#include <vector>
#include <string>

class ButtonMenu : Component
{
public:
	ButtonMenu(int begX, int begY, int len, int wid, std::vector<std::string> buttons) :Component(begX, begY, len, wid)
	{
		
		nButtons = buttons.size();
		setBackground(COLOR_WHITE);


		drawBorder();



		mvwprintw(this->component, 1, 20, "TEST");

		addButtons(buttons[0]);

	}



	inline void drawBorder();
	inline void addButtons(std::string buttons);

	int nButtons;
	int buttonSpace = 0;



};

struct CButton
{
	WINDOW* parentWindow;
	std::string name;
	bool highlighted;

	void drawButton(WINDOW* c);
	void highlight();

};


inline void ButtonMenu::addButtons(std::string buttonText)
{
	



	CButton b;
	b.name = buttonText;
	b.drawButton(this->component);

	
	
	buttonSpace += buttonText.length() + 5;


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