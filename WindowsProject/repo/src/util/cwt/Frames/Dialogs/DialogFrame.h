#pragma once

#include "../Frame.h"

#include "../../Components/InputField/InputField.h"
#include "../../Components/TextArea/TextArea.h"

using namespace std;

class DialogFrame : public Frame
{
public:
	static Frame dialogFrame();

	//static void showMessageDialog(Component parentComponent, string message);
	static void showMessageDialog(Component parentComponent, string option, string title, string message);

	//static string showInputDialog(Component parentComponent, string message);
	static string showInputDialog(Component parentComponent, string option, string title, string message);
	
	//static string showConfirmDialog(Component parentComponent, string message);
	static string showConfirmDialog(Component parentComponent, string option1, string option2, string title, string message);

	static int getLengthFromString(string message);
	static int getWidthFromString(string message);

};