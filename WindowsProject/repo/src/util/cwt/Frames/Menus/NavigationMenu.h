#pragma once

#include "../Frame.h"
#include <string>

class NavigationMenu : public Frame
{
public:
	NavigationMenu(int begX, int begY, int len, int wid, std::string title) :Frame(begX, begY, len, wid, title)
	{
		addTextArea();
		width += 3;
		ButtonMenu dButtonMenu(x, y + width - 4, length, 3, "SELECT", "BACK", "EXIT");
		dButtonMenu.getButtonChoice();

	}

	
private:
	std::string frameTitle;
};