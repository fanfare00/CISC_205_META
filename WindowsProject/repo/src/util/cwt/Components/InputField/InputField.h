#pragma once

#include "../Component.h"
#include <string>

class InputField : Component
{

public: 
	InputField() :Component() {}
	InputField(int begX, int begY, int len, int wid) :Component(begX, begY, len, wid)
	{
		box(this->component, 0, 0);


		curs_set(1);
		echo();

		mvwprintw(this->component, 1, 1, " ");
		drawWin();
		
	}

	inline std::string getInput();

private:
	std::string inputString;

};

inline std::string InputField::getInput()
{
	char inputC[80];

	wgetstr(this->component, inputC);

	curs_set(0);
	noecho();

	return (std::string)inputC;
}