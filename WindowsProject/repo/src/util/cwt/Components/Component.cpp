#pragma once

#include "Component.h"
#include "../Color/Color.h"

Component::Component()
{

}


Component::Component(int begX, int begY, int len, int wid) : x(begX), y(begY), length(len), width(wid)
{
	this->component->_begx = x;
	this->component->_begy = y;
	this->component->_maxx = length;
	this->component->_maxy = width;

	drawWin();
}

Component::~Component()
{
	touchwin(component);
	wrefresh(component);
	delwin(component);
}

void Component::setSize(int len, int wid)
{
	this->length = len;
	this->width = wid;
	drawWin();
}

void  Component::setLocation(int begX, int begY)
{

	updateXY(begX, begY);
	drawWin();
}

void Component::setBounds(int begX, int begY, int len, int wid)
{
	this->length = len;
	this->width = wid;
	updateXY(begX, begY);
	drawWin();
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
	this->component->_begx = x;
	this->component->_begy = y;
	this->component->_maxx = length;
	this->component->_maxy = width;
	

	wbkgd(this->component, COLOR_PAIR(cwt::colorPair(foregroundColor, backgroundColor)));

	//werase(stdscr);
	//wrefresh(stdscr);
	wrefresh(this->component);

}

void Component::hideWin()
{
	this->component->_begx = 0;
	this->component->_begy = 0;
	this->component->_maxx = 0;
	this->component->_maxy = 0;

	werase(stdscr);
	wrefresh(stdscr);
	wrefresh(this->component);
}


void Component::updateXY(int begX, int begY)
{
	if ((begY >= 0) && (begY <= LINES - width))
	{
		this->y = begY;
	}

	if ((begX >= 0) && (begX <= COLS - length))
	{
		this->x = begX;
	}
}

void Component::updateLW(int l, int w)
{

}

void Component::enableBorder(bool b)
{
	if (b == true)
	{
		box(this->component, 0, 0);
	}
	else
	{
		wattron(this->component, COLOR_PAIR(cwt::colorPair(backgroundColor, backgroundColor)));
		box(this->component, 0, 0);
		wattron(this->component, COLOR_PAIR(cwt::colorPair(backgroundColor, backgroundColor)));
	}
}

void Component::enableMoveMode(bool b)
{
	int keyPress;
	int XEE = 5;
	int YEE = 5;

	this->moveMode = b;

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
	return this->width;
}

int Component::getLength()
{
	return this->length;
}

int Component::getBegX()
{
	return this->x;
}

int Component::getBegY()
{
	return this->y;
}