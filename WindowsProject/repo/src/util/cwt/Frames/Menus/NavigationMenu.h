#pragma once

#include "../Frame.h"
#include <string>
#include <vector>
#include "../../Color/Color.h"

class NavigationMenu : public Frame
{
public:
	template<typename... Arguments>
	NavigationMenu(int begX, int begY, int len, int wid, std::string title, Arguments&... args) :Frame(begX, begY, len, wid, title)
	{
		mItems = new std::vector<std::string>{ args... };

		TextArea TA = addTextArea();

		width += 3;
		bMenu = new ButtonMenu(x, y + width - 4, length, 3, "SELECT", "BACK", "EXIT");
		
		printMenuItems(*mItems, 0);
		
	}
	~NavigationMenu();

	ButtonMenu *bMenu;
	std::vector<std::string> *mItems;

	int loopMenu(ButtonMenu dButtonMenu, std::vector<std::string> menuItems);
	void printMenuItems(std::vector<std::string> menuItems, int highlight);
	int getMenuChoice();

	template<typename... Arguments>
	void setMenuOptions(Arguments&... args)
	{
		bMenu = new ButtonMenu(x, y + width - 4, length, 3, args...);
	}

private:
	std::string frameTitle;
};
