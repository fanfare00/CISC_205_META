#include "JamesAI.h"
#include <fstream>
#include <algorithm>

using namespace std;

////////////////////////////////////////////////////////////////////////
////	START OOPS COMMON FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////////////

JamesAI::~JamesAI()
{
	//endwin();
}

JamesAI& JamesAI::getInstance()
{
	static JamesAI instance;
	return instance;
}

void JamesAI::start(Frame mFrame)
{
	mainFrame = mFrame;
	mainFrame.setTitle("JAMES' AFFIRMATIVE INTERACTION");
	mainFrame.setBackground(COLOR_RED);
	mainFrame.drawWin();

	vDictionary.push_back("Yes");

	ofstream ofs;
	ofs.open("scores.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	welcomeScreen();

}

void JamesAI::welcomeScreen()
{

	mainFrame.addTextHorCentered((mainFrame.getWidth() / 2), "Welcome to James' Affirmative Interaction!", COLOR_GREEN, COLOR_RED);
	mainFrame.addTextHorCentered((mainFrame.getWidth() / 2) + 1, "Press <ENTER> to Begin.", COLOR_GREEN, COLOR_RED);

	cwt::hitEnter();
	mainFrame.addText((mainFrame.getLength() / 2) - 18, (mainFrame.getWidth() / 2), "                                     ");
	mainFrame.addText((mainFrame.getLength() / 2) - 11, (mainFrame.getWidth() / 2) + 1, "                       ");

	mainFrame.drawWin();
	mainMenu();

}

void JamesAI::signIn()
{
	userName = DialogFrame::showInputDialog(mainFrame, "Continue", "SIGN IN", "Please enter your full name:");
	defaultStatus = "You are currently signed in as: " + userName;
	
	mainFrame.drawWin();
	mainMenu();

}

void JamesAI::displayLogo()
{
	Frame logoFrame(mainFrame.getLength() / 2 - 32, mainFrame.getWidth() / 2 - 9, 65, 17, "JAMES' LOGO");
	logoFrame.setBackground(COLOR_WHITE);
	logoFrame.setForeground(COLOR_BLACK);

	TextArea TA = logoFrame.addTextArea();
	TA.setBackground(COLOR_WHITE);

	TA.addText(0, 0,
		"     JJJJJJJJJJJJJJJ DDDDDDDDDDDDD    MMMMMM        MMMMMM\n"
		"     J.............J D............D   M.....M      M.....M\n"
		"     JJJJJJJ...JJJJJ D....DDDDD....D  M......M    M......M\n"
		"           J...J      D...D    D....D M.......M  M.......M\n"
		"           J...J      D...D    D....D M........MM........M\n");

	TA.addText(0, 5,
		"           J...J      D...D    D....D M....MM......MM....M\n"
		"JJJJJJ     J...J      D...D    D....D M....M MM..MM M....M\n"
		"J....J     J...J      D...D    D....D M....M   MM   M....M\n"
		"J.....JJJJJ....J     DD...DDDDDD...D  M....M        M....M\n"
		" J............J      D............D   M....M        M....M\n"
		"  JJJJJJJJJJJJ       DDDDDDDDDDDDD    MMMMMM        MMMMMM\n");


	logoFrame.addButtonMenu("< Continue >");
	cwt::hitEnter();
	mainFrame.drawWin();

	mainMenu();


}

void JamesAI::displayIDInfo()
{
	requireLogin();

	DialogFrame::showMessageDialog(
		mainFrame,
		"Continue", "ID INFORMATION",
		"      Programmer         : James McCarthy   \n"
		"      Assignment #       : TA #1.2CA        \n"
		"      Assignment Name    : Cellular Automata\n"
		"      Course # and Title : CISC 205 - OOPS  \n"
		"      Class Meeting Time : TTh 9:35 - 12:40 \n"
		"      Instructor         : Professor Forman \n"
		"      Hours              : 15               \n"
		"      Difficulty         : 5                \n"
		"      Completion Date    : 9/11/2014        \n"
		"      Project Name       : JamesCA          ");

	mainFrame.drawWin();
	mainMenu();
}

void JamesAI::displayCredits()
{
	requireLogin();

	DialogFrame::showMessageDialog(
		mainFrame,
		"< CONTINUE >", "CREDITS",
		"This program was created by James McCarthy for Larry Forman's CISC 205 Object Oriented C++ class\n"
		"\nThank you to Nils for providing support with debugging and for giving me many   ideas and of course, introducing me to PDCurses.\n"
		"\nThank you to the creators of ncurses/PDCurses for providing a wonderful library to create this program's UI.\n\n"
		"PDCurses website   : www.pdcurses.sourceforge.net/doc/PDCurses.txt\n"
		"ncurses tutorials  : www.tldp.org/HOWTO/NCURSES-Programming-HOWTO/\n"
		"My Github          : www.github.com/fanfare00");

	mainFrame.drawWin();
	mainMenu();
}


void JamesAI::displayStars()
{
	requireLogin();

	

	DialogFrame::showMessageDialog(
		mainFrame,
		"< CONTINUE >", "STARS",
		"1: Add the replies to 'Hmm, like uhuh, si, certainly – to the dictionary\n"
		"2: In the above STAR, do not add duplicates. For example:\n"
		"3: Expand previous STAR to respond 'I told you I don’t know what 'uhuh' means\n"
		"4: Allow for case-insensitivity for all entries\n"
		"5: Read a line, not just one word replies\n"
		"6: Add extra pizzazz and briefly explain what you did: Scrolling frame\n"
		"CONTINUE\n"
		);

	DialogFrame::showMessageDialog(
		mainFrame,
		"< CONTINUE >", "STARS",
	"7: Classes vectors templates\n"
		"8: Search for a specific synonym in the dictionary \n"
		"9: Remove a specific synonym from the dictionary\n"
		"10: Sort the dictionary alphabetically\n"
		"11: Reverse the order of the items in the dictionary\n"
		"\nTOTAL STARS: 11");

	mainFrame.drawWin();
	mainMenu();
}

void JamesAI::farewell()
{
	DialogFrame::showMessageDialog(mainFrame, "< EXIT >", "GOODBYE", "Farewell, " + userName + ". Thank you for using " + MY_NAME + "' Pointer Power");
	exit(1);


}

void JamesAI::requireLogin()
{
	if (userName == "Unknown User")
	{
		DialogFrame::showMessageDialog(mainFrame, "< Back >", "ERROR", "Please sign in before proceeding");
		mainFrame.drawWin();
		mainMenu();
	}
	else
	{
		return;
	}
}

void JamesAI::mainMenu()
{
	mainFrame.addText(2, mainFrame.getWidth() - 2, defaultStatus, COLOR_GREEN, COLOR_RED);

	mainFrame.drawWin();


	NavigationMenu NM((mainFrame.getLength() / 2) - 25, (mainFrame.getWidth() / 2) - 9, 50, 16,
		"MAIN MENU", "Sign In", "Display Logo", "Affirmative Interaction", "Display Dictionary", "ID Information", "Credits", "Stars");

	NM.setMenuOptions("< Select >", "< Exit >", "< Help >");

	switch (NM.getMenuChoice())
	{
	//exit
	case 0:
		farewell();
		break;

	//sign in
	case 1:
		signIn();
		break;

	//Display Logo
	case 2:
		displayLogo();
		break;

	//Affirmative Interaction
	case 3:
		startAI();
		break;

	//Dictionary
	case 4:
		displayAIDictionary();
		break;

	//ID Info
	case 5:
		displayIDInfo();
		break;

	//Credits
	case 6:
		displayCredits();
		break;

	case 7:
		displayStars();
		break;

	default:

		break;
	}

}

////////////////////////////////////////////////////////////////////
/////	END OOPS COMMON FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
/////	START AI SPECIFIC FUNCTION DEFINITIONS
////////////////////////////////////////////////////////////////////

//Afirmative Interaction
void JamesAI::startAI()
{

	char cTemp[80];
	int length = 82;
	int width = 27;
	int x = (mainFrame.getLength() / 2) - (length/2);
	int y = (mainFrame.getWidth()/2) - (width/2);

	//Frame aFrame(x, y-1, length, width, "AFFIRMATIVE INTERACTION");

	Frame bFrame(x, y - 3, length, width-1);
	
	wattron(bFrame.component, COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));
	bFrame.addCharacter(bFrame.getLength() - 2, 1, ACS_URCORNER);
	bFrame.addCharacter(1, 1, ACS_ULCORNER);
	bFrame.addCharacter(1, width -6, ACS_LLCORNER);
	bFrame.addCharacter(bFrame.getLength() - 2, width - 6, ACS_LRCORNER);
	
	wattroff(bFrame.component, COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));

	for (int i = 0; i < bFrame.getLength()-4; i++)
	{
		wattron(bFrame.component, COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));
		bFrame.addCharacter(i+2, width-6, ACS_HLINE);
		bFrame.addCharacter(i + 2, 1, ACS_HLINE);
		bFrame.addText(3, width - 6, "Enter your response:");
		wattroff(bFrame.component, COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));
	}

	for (int i = 0; i < bFrame.getWidth() - 7; i++)
	{
		wattron(bFrame.component, COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));
		bFrame.addCharacter(1, i+2, ACS_VLINE);
		bFrame.addCharacter(bFrame.getLength() - 2 , i + 2, ACS_VLINE);
		wattroff(bFrame.component,COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));
	}

	wattron(bFrame.component, COLOR_PAIR(cwt::colorPair(COLOR_WHITE, COLOR_BLACK)));

	wattroff(bFrame.component, COLOR_PAIR(cwt::colorPair(COLOR_WHITE, COLOR_BLACK)));

	bFrame.setTitle("Affirmative Interaction (Yes Dictionary)");
	ButtonMenu bMenu = bFrame.addButtonMenu("< Submit >", "< Back >", "< Options >");
	
	InputField bInputField(x+1, y+width-8,  length-2, 3);
	bInputField.setForeground(COLOR_GREEN);
	bInputField.setBackground(COLOR_BLACK);
//	wclear(bInputField.component);
	

	WINDOW* echoArea = newpad(500, 80);
	//mvwaddch(echoArea, 5, 5, ACS_DARROW);
	prefresh(echoArea, 0, 0, 6, 11, getmaxy(stdscr) - 16, getmaxx(stdscr) - 12);

	keypad(echoArea, true);
	curs_set(1);
	echo();
	scrollok(echoArea, true);
	
	string input;
	string aResponse;
	string dictionaryEcho;

	int keypress;

	int xPos = 2;
	int yPos = 8;
	int padPos = 0;
	int scrollLines = 0;

	int scrollBarPos = 20;
	int scrollBarLength = 19;

	double scrollFactor = 1;
	int scrollAmount;

	keypad(bInputField.component, true);

	dictionaryEcho = "Words that mean YES: ";
	for (int i = 0; i < vDictionary.size(); i++)
	{
		dictionaryEcho += vDictionary[i] + " ";
	}

	wattron(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_CYAN, COLOR_BLACK)));
	cwt::mvwprintwCentered(echoArea, 2, dictionaryEcho);
	cwt::mvwprintwCentered(echoArea, 3, "Words that mean NO: No");
	wattroff(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_CYAN, COLOR_BLACK)));

	wattron(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));
	cwt::mvwprintwCentered(echoArea, 1, "Let me tell you what's already in my dictionary:");
	mvwprintw(echoArea, 6, getmaxx(echoArea) - 45, "Can you teach me a word that means 'Yes'?");
	wattroff(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));

	prefresh(echoArea, 0, 0, 6, 11, getmaxy(stdscr) - 16, getmaxx(stdscr) - 12);

	int buttonSelection = 0;



	vector<string>inputBuffer;

	int gettingSynonym = false;

	while (true)
	{


		keypress = mvwgetch(bInputField.component, 1,xPos);
		
		switch (keypress)
		{
		case KEY_UP:
			if (padPos > 0)
			{
				padPos--;
				prefresh(echoArea, padPos, 0, 6, 11, getmaxy(stdscr) - 16, getmaxx(stdscr) - 12);
				scrollLines += 1;

				if (scrollFactor / 20 <= 1)
				{
					scrollBarPos--;
				}
				else if (scrollBarPos >= 4)
				{
					scrollAmount -= (1 / (scrollFactor / 19)) * 1000;

					if (scrollAmount <= 0)
					{
						scrollBarPos--;
						scrollAmount += 1000;
					}
				}
			}
			break;

		case KEY_DOWN:
			if (scrollLines > 0)
			{
				padPos++;
				prefresh(echoArea, padPos, 0, 6, 11, getmaxy(stdscr) - 16, getmaxx(stdscr) - 12);
				scrollLines -= 1;

				if (scrollFactor / 20 < 1)
				{
					scrollBarPos++;
				}
				else
				{
					scrollAmount += (1 / (scrollFactor / 19)) * 1000;

					if (scrollAmount >= 1000)
					{
						scrollBarPos++;
						scrollAmount -= 1000;
					}
				}
			}

			break;

		case KEY_LEFT:

			bMenu.highlightLeft();
			buttonSelection = bMenu.getHighlight();
			break;

		case KEY_RIGHT:
			bMenu.highlightRight();
			buttonSelection = bMenu.getHighlight();
			break;

			//BACKSPACE
		case 8:
			if (input.length() > 0)
			{
				input.pop_back();
			}

			if (xPos > 2)
			{
				xPos--;
			}
			mvwaddch(bInputField.component, 1, xPos, ' ');
			mvwaddch(bInputField.component, 1, bInputField.getLength(), ACS_VLINE);

			break;

			//ENTER
		case 10:
			if (buttonSelection == 1)
			{
				curs_set(0);
				noecho();
				delwin(bFrame.component);
				delwin(echoArea);
				delwin(bInputField.component);
				delwin(bMenu.component);
				mainFrame.drawWin();
				mainMenu();
				break;
			}

			if (buttonSelection == 2)
			{
				curs_set(0);
				noecho();

				NavigationMenu optionMenu(bFrame.getBegX() + bFrame.getLength() - 35, bFrame.getBegY(), 35, bFrame.getWidth()-3 , "YES DICTIONARY OPTIONS",
					"View Dictionary",
					"Switch Dictionary",
					"Search Dictionary",
					"Remove from Dictionary",
					"Clear Dictionary",
					"Sort Dictionary",
					"Reverse Dictionary Order"
					);

				optionMenu.addText(optionMenu.getLength() / 2 - 11, optionMenu.getWidth()-1,"Current Dictionary: Yes", COLOR_GREEN, COLOR_WHITE);

				optionMenu.setMenuOptions("< Select >", "< Back >");

				optionMenu.setTextXY(4, 4);
				
				
				string searchStr;
				int nMatches;
				switch (optionMenu.getMenuChoice())
				{
				case 1:
					for (int i = 0; i < vDictionary.size(); i++)
					{
						searchStr += vDictionary[i] + "\n";
					}
					DialogFrame::showMessageDialog(mainFrame, "Back", "Dictionary Contents", searchStr);
					break;

				case 2:

					break;
				case 3:
					searchStr = DialogFrame::showInputDialog(mainFrame, "Search", "Dictionary Find", "Search the dictionary for a synonym:");

					for(auto & c : searchStr) c = toupper(c);
					for (int i = 0; i < vDictionary.size(); i++)
					{
						for (auto & v : vDictionary[i]) v = toupper(v);
						if (vDictionary[i] == searchStr)
						{
							nMatches++;

						}
					}

					DialogFrame::showMessageDialog(mainFrame, "Back", "Search Results", "(" + to_string(nMatches) + ") occurence(s) of \"" + searchStr + "\" were found in the dictionary.");
					break;
				case 4:
					searchStr = DialogFrame::showInputDialog(mainFrame, "Search", "Find and Remove", "Search the dictionary for a synonym and remove:");

					for (auto & c : searchStr) c = toupper(c);
					for (int i = 0; i < vDictionary.size(); i++)
					{
						for (auto & v : vDictionary[i]) v = toupper(v);
						if (vDictionary[i] == searchStr)
						{
							nMatches++;
							vDictionary.erase(vDictionary.begin() + i);

						}
					}
					DialogFrame::showMessageDialog(mainFrame, "Back", "Find and Remove", "(" + to_string(nMatches) + ") occurence(s) of \"" + searchStr + "\" were found and removed from the dictionary.");
					//vec.erase(vec.begin() + index);
					break;

				case 5:
					vDictionary.clear();
					vDictionary.push_back("Yes");
					DialogFrame::showMessageDialog(mainFrame, "Back", "Dictonary Cleared", "The dictionary has been successfully cleared.");
					break;

				case 6:
					sort(vDictionary.begin(), vDictionary.end());
					DialogFrame::showMessageDialog(mainFrame, "Back", "Dictonary Sorted", "The dictionary has been sorted alphabetically.");
					break;
				case 7:
					reverse(vDictionary.begin(), vDictionary.end());
					DialogFrame::showMessageDialog(mainFrame, "Back", "Dictonary Reversed", "The order of the dictionary has been reversed.");
					break;

				}

				delwin(bFrame.component);
				delwin(echoArea);
				delwin(bInputField.component);
				delwin(bMenu.component);
				mainFrame.drawWin();
				startAI();
			}

			wattron(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));
			mvwprintw(echoArea, yPos, 2, (char*)input.c_str());
			wattroff(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));

			//check if yes or no
			if (analyzeUserInput(input) == 1)
			{
				//check if in syn mode
				if (gettingSynonym == false)
				{

					aResponse = "Good - please enter a word that mean \"YES\":";

					wattron(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));
					mvwprintw(echoArea, yPos + 2, getmaxx(echoArea) - aResponse.length() - 3, (char*)aResponse.c_str());
					wattroff(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));

					gettingSynonym = true;
				}
				else
				{
					/////////////////////////////////////////
						/////////////////////////////////////////
					if (inputBuffer.size() > 0)
					{
						string listEcho;

						for (int i = 0; i < inputBuffer.size(); i++)
						{
							if (i != inputBuffer.size() - 1)
							{
								listEcho += inputBuffer[i] + ", ";
							}
							else
							{
								listEcho += inputBuffer[i];
							}
						
							addToDictionary(inputBuffer[i]);
						}
					
					
						aResponse = "Thanks, I will add \"" + listEcho + "\" to my dictionary.";
						wattron(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));
						mvwprintw(echoArea, yPos + 2, getmaxx(echoArea) - aResponse.length() - 3, (char*)aResponse.c_str());
						wattroff(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));
					
						inputBuffer.clear();
					}
					else
					{
						aResponse = "Thanks, but \"" + input + "\" is already in my dictionary.";
						wattron(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));
						mvwprintw(echoArea, yPos + 2, getmaxx(echoArea) - aResponse.length() - 3, (char*)aResponse.c_str());
						wattroff(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));
					}
					
					aResponse = "Can you please teach me another word that means \"Yes\"";
					wattron(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));
					mvwprintw(echoArea, yPos + 4, getmaxx(echoArea) - aResponse.length() - 3, (char*)aResponse.c_str());
					wattroff(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));
					yPos += 2;

					gettingSynonym = false;
				}
			}
			else if (analyzeUserInput(input)==0)
			{

				
					wattron(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));
					mvwprintw(echoArea, yPos + 2, getbegx(echoArea) + 3, "Well, thank you for your positive, never-say-no attitude! Glad you believe");
					mvwprintw(echoArea, yPos + 3, getbegx(echoArea) + 3, "in affirmative interaction! In this session, I learned the following words:");
					wattroff(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));

					dictionaryEcho = "";

					for (int i = 1; i < vDictionary.size(); i++)
					{
						dictionaryEcho += vDictionary[i] + " ";
					}

					wattron(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_CYAN, COLOR_BLACK)));
					cwt::mvwprintwCentered(echoArea, yPos + 5, "New words for YES: " + dictionaryEcho);
					cwt::mvwprintwCentered(echoArea, yPos + 6, "New words for NO:  'no'  'NO' ");
					wattroff(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_CYAN, COLOR_BLACK)));

					yPos += 4;

					gettingSynonym = false;
			


			}
			else
			{
				aResponse = "Hmm I don't know \""+input+"\". Does it mean \"Yes\"?";

				wattron(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));
				mvwprintw(echoArea, yPos + 2, getmaxx(echoArea) - aResponse.length() - 3, (char*)aResponse.c_str());
				wattroff(echoArea, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));

				inputBuffer.push_back(input);


			}
		


				
				
				prefresh(echoArea, 0, 0, 6, 11, getmaxy(stdscr) - 16, getmaxx(stdscr) - 12);
				
				input = "";
				
				wmove(bInputField.component, 1, 1);
				wclrtoeol(bInputField.component);


				yPos+=4;
				xPos = 2;


				if (yPos > 20)
				{
					scrollBarPos = 20;
					scrollFactor += 4;

					if (scrollBarLength > 4)
					{
						scrollBarLength -= 4;
					}
					else
					{
						scrollBarLength = 2;
					}

					padPos = yPos - 20;
					scrollLines = 0;
					prefresh(echoArea, padPos, 0, 6, 11, getmaxy(stdscr) - 16, getmaxx(stdscr) - 12);
				}



				break;

			default:
				input += keypress;
				xPos++;
			break;


		}



		//////DRAW SCROLL BAR/////
		if (yPos > 20)
		{
			for (int i = 0; i < 20; i++)
			{
				wattron(bFrame.component, COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));
				mvwaddch(bFrame.component, 1 + i, bFrame.getLength() - 2, ACS_VLINE);
				wattroff(bFrame.component, COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));
			}

			for (int i = 0; i < scrollBarLength; i++)
			{
				wattron(bFrame.component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));
				mvwaddch(bFrame.component, scrollBarPos - i, bFrame.getLength() - 2, ACS_BLOCK);
				wattroff(bFrame.component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));
			}

			wattron(bFrame.component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));
			mvwaddch(bFrame.component, 1, bFrame.getLength() - 2, ACS_UARROW);
			mvwaddch(bFrame.component, bFrame.getWidth() - 8, bFrame.getLength() - 2, ACS_DARROW);

			wattroff(bFrame.component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));

			wrefresh(bFrame.component);
		}

		wattron(bInputField.component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));
		mvwaddch(bInputField.component, 1, bInputField.getLength() - 1, ACS_VLINE);
		wattroff(bInputField.component, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));

	}
	getch();

}

//Dictionary
void JamesAI::displayAIDictionary()
{

}

int JamesAI::analyzeUserInput(string input)
{

	for (auto & c : input) c = toupper(c);

	for (int i = 0; i < vDictionary.size(); i++)
	{
		
		for (auto & v : vDictionary[i]) v = toupper(v);

		if (input == vDictionary[i])
		{
			return 1;
		}
	}

	if (input == "NO")
	{
		return 0;
	}
	


	return -1;
}
string JamesAI::getAIResponse(string input)
{
	string response;

	return response;
}

void JamesAI::addToDictionary(string input)
{
	vDictionary.push_back(input);
}