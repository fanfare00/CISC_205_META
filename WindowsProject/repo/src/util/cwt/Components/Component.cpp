#pragma once

#include "Component.h"
#include "../Color/Color.h"

Component::Component()
{

}


Component::Component(int begX, int begY, int len, int wid) : x(begX), y(begY), length(len), width(wid)
{
	//component->_begx = x;
	//component->_begy = y;
	updateXY(x, y);
	updateLW(length, width);



	drawWin();
}

Component::~Component()
{
	//touchwin(component);
	//wrefresh(component);
   // delwin(component);
}

void Component::setSize(int len, int wid)
{
	length = len;
	width = wid;
}

void  Component::setLocation(int begX, int begY)
{

	x = begX;
	y = begY;
	drawWin();

}

void Component::setBounds(int begX, int begY, int len, int wid)
{
	length = len;
	width = wid;

	updateXY(begX, begY);
}

void Component::setVisible(bool b)
{
	if (b == true)
	{
		Component::drawWin();
	}
	else
	{
		Component::hideWin();
	}
}

void Component::setBackground(int bkgColor)
{
	backgroundColor = bkgColor;
	drawWin();
}

void Component::setForeground(int foreColor)
{
	foregroundColor = foreColor;
	drawWin();
}

void Component::drawWin()
{
	component->_begx = x;
	component->_begy = y;
	component->_maxx = length;
	component->_maxy = width;
	


	wbkgd(component,COLOR_PAIR(cwt::colorPair(foregroundColor, backgroundColor)));

	if (bordered == true)
	{
		box(component, 0, 0);
	}

	//wcolor_set(component, COLOR_PAIR(cwt::colorPair(foregroundColor, backgroundColor)), NULL );
	//werase(stdscr);
	//wrefresh(stdscr);
	wrefresh(component);

}

void Component::hideWin()
{
	component->_begx = 0;
	component->_begy = 0;
	component->_maxx = 0;
	component->_maxy = 0;

	werase(stdscr);
	wrefresh(stdscr);
	wrefresh(component);
}


void Component::updateXY(int begX, int begY)
{
	if ((begY >= 0) && (begY <= LINES - width))
	{
		y = begY;
	}



	if ((begX >= 0) && (begX <= COLS - length))
	{
		x = begX;
	}
}

void Component::updateLW(int l, int w)
{

	if ((l >= 0) && (l <= COLS - x))
	{
		length = l;
	}
	else
	{
		length = COLS - x-2;
	}
	
	if ((w >= 0) && (w <= LINES - y))
	{
		width = w;
	}
	else
	{
		width = LINES - x-2;
	}

}

void Component::enableBorder(bool b)
{
	bordered = b;
	drawWin();
}

void Component::enableMoveMode(bool b)
{
	int keyPress;
	int XEE = 5;
	int YEE = 5;

	moveMode = b;

	keypad(stdscr, true);

	while (moveMode == true)
	{
		keyPress = wgetch(stdscr);

		switch (keyPress)
		{

		case KEY_UP:
			YEE--;
			break;

		case KEY_DOWN:
			YEE++;
			break;

		case KEY_LEFT:
			XEE--;
			break;

		case KEY_RIGHT:
			XEE++;
			break;

		case 27:
			hideWin();
			return;

		default:
			break;
		}

		if (YEE < 0)
		{
			YEE = 0;
		}

		if (YEE > LINES - width)
		{
			YEE = LINES - width;
		}

		if (XEE < 0)
		{
			XEE = 0;
		}

		if (XEE > COLS - length)
		{
			XEE = COLS - length;
		}

		werase(stdscr);
		wrefresh(stdscr);
		setLocation(XEE, YEE);
	}
	keypad(stdscr, false);
}

void Component::enableSizeMode(bool b)
{

}

int Component::getWidth()
{
	return width;
}

int Component::getLength()
{
	return length;
}

int Component::getBegX()
{
	return x;
}

int Component::getBegY()
{
	return y;
}

int Component::getKeyboardInput()
{
	return 0;
}

void Component::addText(int x, int y, std::string text)
{

	mvwprintw(component, y, x, (char*)text.c_str());
	wrefresh(component);
}

void Component::addText(int x, int y, std::string text, int foreColor, int backColor)
{
	wattron(component, A_BOLD | COLOR_PAIR(cwt::colorPair(foreColor, backColor)));
	mvwprintw(component, y, x, (char*)text.c_str());
	wattroff(component, A_BOLD | COLOR_PAIR(cwt::colorPair(foreColor, backColor)));

	wrefresh(component);
}

void Component::addCharacter(int x, int y, unsigned long cCharacter)
{
	mvwaddch(component, y, x, cCharacter);
	wrefresh(component);
}

void Component::addCharacter(int x, int y, unsigned long cCharacter, int foreColor, int backColor)
{
	wattron(component, A_BOLD | COLOR_PAIR(cwt::colorPair(foreColor, backColor)));
	mvwaddch(component, y, x, cCharacter);
	wattroff(component, A_BOLD | COLOR_PAIR(cwt::colorPair(foreColor, backColor)));
	wrefresh(component);
}