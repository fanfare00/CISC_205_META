#pragma once

#include "curses.h"
#include <string>
#include "Color/Color.h"

#include "Components\Component.h"
#include "Components\Frames\Frame.h"
#include "Components\InputField\InputField.h"




namespace cwt
{
	static int mvwprintwCentered(WINDOW *win, int y, char *fmt, ...);
}

inline int cwt::mvwprintwCentered(WINDOW *win, int y, char *fmt, ...)
{
	int ret = ERR;
	int x = (getmaxx(win) / 2) - (strlen(fmt) / 2);


	va_list args;
	va_start(args, fmt);
	::wmove(win, y, x);
	ret = ::vwprintw(win, fmt, args);
	va_end(args);

	return ret;

}
