#pragma once

#include "../Components/TextArea/TextArea.h"
#include "../Components/ButtonMenu/ButtonMenu.h"
#include "../Components/Component.h"
#include "../Color/Color.h"
#include <string>
#include <vector>


class Frame : public Component
{


public:
	Frame() :Component() {}

	Frame(int begX, int begY, int len, int wid) :Component(begX, begY, len, wid)
	{
		frameTitle = "";
		drawBorder();
		setBackground(COLOR_BLACK);
	}

	Frame(int begX, int begY, int len, int wid, std::string title) :Component(begX, begY, len, wid)
	{
		frameTitle = " " + title + " ";
		drawBorder();
		setBackground(COLOR_WHITE);
	}

	Frame(int begX, int begY, int len, int wid, std::string title, int foreColor, int bkgColor) :Component(begX, begY, len, wid)
	{
		frameTitle = " " + title + " ";
		drawBorder();

		
		setBackground(bkgColor);
		setForeground(foreColor);
	}

	~Frame();

	void drawBorder();
	
	

	TextArea addTextArea();
	void addTextArea(std::string msgStr);
	void addTextArea(int startX, int startY, int aLength, int aWidth, std::string testStr);

	void addButtonMenu(std::string test);

	void setTitle(std::string title);
	
	//void addButtonMenu(std::string b1Text);
	//void addButtonMenu(std::string b1Text, std::string b2Text);
	//void addButtonMenu(std::string b1Text, std::string b2Text, std::string b3Text);
	
private:
	std::string frameTitle;
};




