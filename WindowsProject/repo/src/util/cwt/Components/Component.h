#pragma once


#include "curses.h"

class Component
{
public: 
	
	WINDOW* component = newwin(0, 0, 0, 0);

	Component();
	Component(int begX, int begY, int len, int wid);
	~Component();

	void setSize(int len, int wid);
	void setLocation(int begX, int begY);
	void setBounds(int begX, int begY, int len, int wid);
	void setVisible(bool b);

	void enableBorder(bool b);

	void enableMoveMode(bool b);
	void enableSizeMode(bool b);
	
	void setBackground(int bkgColor);
	void setForeground(int foreColor);

	int getWidth();
	int getLength();
	int getBegX();
	int getBegY();

	void drawWin();
	void hideWin();

	int getKeyboardInput();

protected:
	
	int length;
	int width;
	int x;
	int y;

	bool moveMode = false;
	bool sizeMode = false;



	int backgroundColor = COLOR_BLACK;
	int foregroundColor = COLOR_WHITE;


	void updateXY(int begX, int begY);
	void updateLW(int l, int w);
};

