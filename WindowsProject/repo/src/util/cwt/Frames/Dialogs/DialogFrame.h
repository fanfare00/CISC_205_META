#pragma once

#include "../Frame.h"
#include "../../Components/TextArea/TextArea.h"

using namespace std;

class DialogFrame : Frame
{
public:
	static Frame dialogFrame();

	static void showMessageDialog(Component parentComponent, string message);
	static void showMessageDialog(Component parentComponent, string title, string message);

	static string showInputDialog(Component parentComponent, string message);
	static string showInputDialog(Component parentComponent, string title, string message);
	
	static string showConfirmDialog(Component parentComponent, string message);
	static string showConfirmDialog(Component parentComponent, string title, string message);


};