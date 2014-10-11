#pragma once

#include "../Component.h"
#include <string>


class Frame : public Component
{


public:
	Frame() :Component() {}
	Frame(int begX, int begY, int len, int wid, std::string title) :Component(begX, begY, len, wid)
	{
		box(this->component, 0, 0);
		mvwprintw(this->component, 0, ((length / 2) - (title.length()/2)), (char*)title.c_str());
		//enableBorder(true);
		
	}


};