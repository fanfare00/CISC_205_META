#include "DialogFrame.h"

void DialogFrame::showMessageDialog(Component parentComponent, string title, string message)
{
	int centerX = parentComponent.getLength() / 2;
	int centerY = parentComponent.getWidth() / 2;

	Frame dFrame(centerX - 25, centerY - 5, 50, 10, title);

	dFrame.setBackground(COLOR_WHITE);


	TextArea dTextArea = dFrame.addTextArea();

		dTextArea.addText((dTextArea.getLength() / 2) - 9, (dTextArea.getWidth() / 2), "The quick brown fox");


		dFrame.addButtonMenu("Continue", "Back");

	//ButtonMenu dButtonMenu = dFrame.addButtonMenu(1, "Continue");
		//int choice = buttonMenu.getChoice();


		// I need to figure out a way to make this all fit together so that if there's no button menu, then the frames text area extends to the bottom
		//if there is a button menu, then the text area extends down to the button menu
		//and if there's no text area, then the button menu stays at the bottom nicely
		//and I also need to be able to add text directly to the frame without a text area
}