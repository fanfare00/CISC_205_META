#include "DialogFrame.h"
#include "../../../ConsoleWordWrapper.h"

void DialogFrame::showMessageDialog(Component parentComponent, string option, string title, string message)
{
	//parentComponent.drawWin();
	ConsoleWordWrapper::formatString(&message, 80);

	int dLength = getLengthFromString(message);
	int dWidth = getWidthFromString(message);
	int centerX = (parentComponent.getLength() / 2) - (dLength/2);
	int centerY = (parentComponent.getWidth() / 2) - (dWidth/2)-2;

	int startLine;


	Frame dFrame(centerX, centerY, dLength, dWidth, title);
		dFrame.setBackground(COLOR_WHITE);

	TextArea dTextArea = dFrame.addTextArea();

	if (message.length() <= 80)
	{
		startLine = (dTextArea.getLength() / 2) - (message.length() / 2);
	}
	
	//startLine = 0;

	dTextArea.addText(startLine, 0, message);

	//Need to return the button menu itself from frame.h, but cant for some reason
     //dFrame.addButtonMenu("< Continue >");

	//dFrame.setSize(dFrame.getLength(), dFrame.getWidth() + 4);

	dFrame.setSize(dFrame.getLength(), dFrame.getWidth() + 3);
	ButtonMenu dButtonMenu(dFrame.getBegX(), dFrame.getBegY() + dFrame.getWidth() - 4, dFrame.getLength(), 3, option);
	dButtonMenu.getButtonChoice();

	werase(dFrame.component);
	

	
	 
}

string DialogFrame::showInputDialog(Component parentComponent, string option, string title, string message)
{
	//parentComponent.drawWin();
	string input;

	ConsoleWordWrapper::formatString(&message, 78);

	int dLength = getLengthFromString(message);
	int dWidth = getWidthFromString(message);
	int centerX = (parentComponent.getLength() / 2) - (dLength / 2);
	int centerY = (parentComponent.getWidth() / 2) - (dWidth / 2)-2;

	int startLine;


	Frame dFrame(centerX, centerY, dLength, dWidth+4, title);
	dFrame.setBackground(COLOR_WHITE);

	TextArea dTextArea = dFrame.addTextArea();

	if (message.length() <= 80)
	{
		startLine = (dTextArea.getLength() / 2) - (message.length() / 2);
	}

	dTextArea.addText(startLine, 0, message);

	InputField dInputField(centerX + 5, dFrame.getBegY() + dFrame.getWidth()-6, dLength - 10, 3);
	
	//std::vector<std::string> bNames{ "Continue" };

	dFrame.setSize(dFrame.getLength(), dFrame.getWidth() + 3);
	ButtonMenu dButtonMenu(dFrame.getBegX(), dFrame.getBegY() + dFrame.getWidth() - 4, dFrame.getLength(), 3, option);
	input = dInputField.getInput();

	werase(dFrame.component);
	


	return input;
}



int DialogFrame::getLengthFromString(string message)
{
	int messageLength = message.length();
	int len = 0;

	int j = 0;
	int k = 50;
	if (messageLength <= 80)
	{
		if (messageLength - 46 <= 0)
		{
			len = 0;
		}
		else
		{
			len = (messageLength - 46);
		}
	}

	for (size_t i = 0; i < messageLength; i++)
	{


		if (j == 80)
		{

			j = 0;
		}


		if ((message[i] == '\n'))
		{

			j = 0;
		}
		else
		{
			j++;
		}

		if (j >= k)
		{
			k = j;
		}
	}
	len = k + 7;
	return len;

}

int DialogFrame::getWidthFromString(string message)
{
	int messageLength = message.length();
	int height = 7;

	int j = 0;
	int k = 50;

	for (size_t i = 0; i < messageLength; i++)
	{


		if (j == 80)
		{
			height += 1;
			j = 0;
		}


		if ((message[i] == '\n'))
		{
			height += 1;
			j = 0;
		}
		else
		{
			j++;
		}

		if (j >= k)
		{
			k = j;
		}
	}


	return height;

}