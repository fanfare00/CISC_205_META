#pragma once

#include "../Component.h"

class Frame : public Component
{
public:

	//Frame() :Component() {}
	Frame(int begX, int begY, int len, int wid) :Component(begX, begY, len, wid)
	{
		setBackground(COLOR_RED);

		//frames need text areas, title areas, border colors, shadow
	}

	//Frame(int begX, int begY, int len, int wid);

};