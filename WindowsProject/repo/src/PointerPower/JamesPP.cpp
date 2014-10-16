#include "JamesPP.h"
#include <vector>
#include "time.h"
#include <iostream>
#include <fstream>


using namespace std;
JamesPP::~JamesPP()
{
	//endwin();
}

JamesPP& JamesPP::getInstance()
{
	static JamesPP instance;
	return instance;
}



void JamesPP::start(Frame mFrame)
{
	mainFrame = mFrame;
	mainFrame.setTitle("JAMES' POINTER POWER");
	mainFrame.drawWin();

	ofstream ofs;
	ofs.open("scores.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	welcomeScreen();

}

void JamesPP::welcomeScreen()
{

	mainFrame.addText((mainFrame.getLength() / 2) - 18, (mainFrame.getWidth() / 2), "Welcome to James' Pointer Power!");
	mainFrame.addText((mainFrame.getLength() / 2) - 11, (mainFrame.getWidth() / 2) + 1, "Press <ENTER> to Begin.");

	cwt::hitEnter();
	mainFrame.addText((mainFrame.getLength() / 2) - 18, (mainFrame.getWidth() / 2), "                                     ");
	mainFrame.addText((mainFrame.getLength() / 2) - 11, (mainFrame.getWidth() / 2) + 1, "                       ");

	mainMenu();

}

void JamesPP::mainMenu()
{
	mainFrame.drawWin();


	NavigationMenu NM((mainFrame.getLength() / 2) - 25, (mainFrame.getWidth() / 2) - 9, 50, 16,
		"MAIN MENU", "Sign In", "Display Logo", "Go Galton", "Play Game", "Game History", "ID Information", "Credits");

	NM.setMenuOptions("< Select >", "< Exit >", "< Help >");

	switch (NM.getMenuChoice())
	{
	case 0:
		
		break;

	case 1:
		signIn();
		break;

	case 2:
		displayLogo();
		break;

	case 3:
		goGalton();
		break;

	case 4:
		playGame();
		break;
	case 5:

		break;

	case 6:
		displayIDInfo();
		break;
	default:
		
		break;
	}

}

void JamesPP::signIn()
{

	userName = DialogFrame::showInputDialog(mainFrame, "Continue", "SIGN IN", "Please enter your name:");
	
	mainFrame.drawWin();
	DialogFrame::showMessageDialog(mainFrame, "Continue", "WELCOME", "Welcome to " + MY_NAME + "' Pointer Power, " + userName);
	
	mainFrame.drawWin();
	mainMenu();

}

void JamesPP::displayLogo()
{
	Frame logoFrame(mainFrame.getLength()/2 - 32, mainFrame.getWidth()/2 - 9, 65, 17, "JAMES' LOGO");
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

//	WINDOW *logoWindow = newwin(25, 80, (LINES / 2) - 11, (COLS / 2) - 40);
//	box(logoWindow, 0, 0);
//	wbkgd(logoWindow, A_BOLD | COLOR_PAIR(cwt::colorPair(COLOR_YELLOW, COLOR_BLACK)));
//
//	cwt::mvwprintwCentered(logoWindow, 2, "THANK YOU FOR VIEWING JAMES' LOGO");
//	cwt::mvwprintwCentered(logoWindow, (getmaxy(logoWindow)-3), "Press any key to quit.");
//
//	int c = 0;
//
//	char* logoLines[] = {
//		"     JJJJJJJJJJJJJJJ DDDDDDDDDDDDD    MMMMMM        MMMMMM",
//		"     J.............J D............D   M.....M      M.....M",
//		"     JJJJJJJ...JJJJJ D....DDDDD....D  M......M    M......M",
//		"           J...J      D...D    D....D M.......M  M.......M",
//		"           J...J      D...D    D....D M........MM........M",
//		"           J...J      D...D    D....D M....MM......MM....M",
//		"JJJJJJ     J...J      D...D    D....D M....M MM..MM M....M",
//		"J....J     J...J      D...D    D....D M....M   MM   M....M",
//		"J.....JJJJJ....J     DD...DDDDDD...D  M....M        M....M",
//		" J............J      D............D   M....M        M....M",
//		"  JJJJJJJJJJJJ       DDDDDDDDDDDDD    MMMMMM        MMMMMM"
//	};
//
//	nodelay(logoWindow, TRUE);
//
//	while ((wgetch(logoWindow) == ERR))
//	{
//		c+=10;
//		if (c == 95)
//		{
//			c = 1;
//		}
//
//		//for ever line in the logo
//		for (int i = 0; i < 11; i++)
//		{
//			//for every character in the line
//			for (int j = 0; j < 58; j++)
//			{
//				if ((wgetch(logoWindow) != ERR))
//				{
//					goto endLoops;
//				}
//
//				switch (logoLines[i][j])
//				{
//				case 'J':
//wattron(logoWindow, COLOR_PAIR(cwt::colorPair(COLOR_RED, COLOR_BLUE)));
//mvwprintw(logoWindow, 6 + i, 9 + j, "J");
//wattroff(logoWindow, COLOR_PAIR(cwt::colorPair(COLOR_RED, COLOR_BLUE)));
//
//break;
//
//				case 'D':
//					wattron(logoWindow, COLOR_PAIR(cwt::colorPair(COLOR_RED, COLOR_BLUE)));
//					mvwprintw(logoWindow, 6 + i, 9 + j, "D");
//					wattroff(logoWindow, COLOR_PAIR(cwt::colorPair(COLOR_RED, COLOR_BLUE)));
//					break;
//
//				case 'M':
//					wattron(logoWindow, COLOR_PAIR(cwt::colorPair(COLOR_RED, COLOR_BLUE)));
//					mvwprintw(logoWindow, 6 + i, 9 + j, "M");
//					wattroff(logoWindow, COLOR_PAIR(cwt::colorPair(COLOR_RED, COLOR_BLUE)));
//
//					break;
//
//				case '.':
//					wattron(logoWindow, COLOR_PAIR(c));
//					mvwprintw(logoWindow, 6 + i, 9 + j, "#");
//					wattroff(logoWindow, COLOR_PAIR(c));
//					wrefresh(logoWindow);
//
//					napms(40);
//					break;
//
//				default:
//					break;
//
//				}
//			}
//		}
//	}
//endLoops:
//
//	wrefresh(logoWindow);
//
//	refreshBackground();
//	mainMenu();

}
vector< vector<int>* > JamesPP::getGaltonRows()
{
	vector< vector<int>* > rows;

	srand(time(NULL));

	int counter;
	int leftRight;

	for (int i = 0; i < nRows; i++)
	{
		rows.push_back(new vector<int>);

		//fill the vector with appropriate amount of 0s
		for (int j = 0; j < rows.size(); j++)
		{
			rows[i]->push_back(0);
		}

		for (int b = 0; b < nBalls; b++)
		{
			counter = 0;

			for (int j = 0; j < i; j++)
			{
				leftRight = rand() % 2;
				counter = counter + leftRight;
			}

			rows[i]->at(counter) += 1;
		}
	}

	return rows;
}

void JamesPP::displayFlowFrame(vector< vector<int>* > galtonData)
{
	int nRows = galtonData.size();

	Frame galtonFrame(2, 2, 65, 15, "GALTON FLOW");
	galtonFrame.setBackground(COLOR_BLACK);
	galtonFrame.setForeground(COLOR_WHITE);
	galtonFrame.drawBorder();

	string centerNumbers;
	for (int i = 0; i < nRows; i++)
	{
		centerNumbers = "";
		galtonFrame.addText(2, i + 3, to_string(i) + ":", COLOR_MAGENTA, COLOR_BLACK);
		for (int j = 0; j < galtonData[i]->size(); j++)
		{
			centerNumbers += to_string(galtonData[i]->at(j)) + "   ";
		}

		
		galtonFrame.addText(((galtonFrame.getLength() / 2) - centerNumbers.length() / 2) + 4, i + 3, centerNumbers);
	}

	galtonFrame.drawBorder();
}

void JamesPP::displayVariableFrame()
{


	Frame variableFrame(68, 2, 30, 15, "VARIABLES");
	variableFrame.setBackground(COLOR_BLACK);
	variableFrame.setForeground(COLOR_WHITE);
	variableFrame.drawBorder();

	variableFrame.addText(2, 2, "Balls dropped      :");
	variableFrame.addText(variableFrame.getLength() - 2 - to_string(nBalls).length(), 2, to_string(nBalls));

	variableFrame.addText(2, 4, "Rows               :");
	variableFrame.addText(variableFrame.getLength() - 2 - to_string(nRows).length(), 4, to_string(nRows));

	variableFrame.addText(2, 6, "Chance to go left  :");
	variableFrame.addText(variableFrame.getLength() - 2 - to_string(leftChance).length() - 1, 6, to_string(leftChance) + "%%");

	variableFrame.addText(2, 8, "Chance to go right :");
	variableFrame.addText(variableFrame.getLength() - 2 - to_string(rightChance).length() - 1, 8, to_string(rightChance) + "%%");

	variableFrame.addText(2, 10, "Graph direction    :");
	variableFrame.addText(variableFrame.getLength() - 2 - graphDirection.length(), 10, graphDirection);
}

void JamesPP::displayGraphFrame(vector< vector<int>* > galtonData)
{
	int nRows = galtonData.size();

	Frame graphFrame(2, 18, 65, 20, "HISTOGRAM");
	graphFrame.setBackground(COLOR_BLACK);
	graphFrame.setForeground(COLOR_WHITE);
	graphFrame.drawBorder();

	flash();
	for (int i = 0; i < 51; i++)
	{
		if (i % 5 == 0)
		{
			graphFrame.addCharacter(7 + i, 18, ACS_BTEE);
		}
		else
		{
			graphFrame.addCharacter(7 + i, 18, ACS_HLINE);
		}
	}

	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			graphFrame.addCharacter(7 + (i * 5), 2 + j, ACS_VLINE);
		}

		if (i <= 9)
		{
			//draw slot number
			graphFrame.addText(9 + (i * 5), 17, to_string(i));

			//draw left side ball count meter
			graphFrame.addText(3, 16 - (2 * i), to_string(i * ((nBalls / 50)*2)));

			for (int b = 0; b < galtonData[nRows - 1]->at(i); b++)
			{
				graphFrame.addText(8 + (i * 5), 16 - (b+1) / (nBalls/50), "    ", COLOR_BLACK, COLOR_RED);
			}
		}
	}

	for (int i = 0; i < 51; i++)
	{
		if (i % 5 == 0)
		{
			graphFrame.addCharacter(7 + i, 16, ACS_PLUS);
		}
		else
		{
			graphFrame.addCharacter(7 + i, 16, ACS_HLINE);
		}
	}


	graphFrame.drawBorder();
}

void JamesPP::displayGameFrame(vector< vector<int>* > galtonData)
{
	Frame gameFrame(2, 18, 65, 20, "GAME SCORE");
	gameFrame.setBackground(COLOR_BLACK);
	gameFrame.setForeground(COLOR_WHITE);
	gameFrame.drawBorder();

	double score = 0;
	string scoreString;
	string lineString;
	double values[]{ 126, 14, 3.5, 1.5, 1, 1, 1.5, 3.5, 14, 126 };

	gameFrame.addText(2, 2, "WEIGHT:  126  14   3.5  1.5   1    1   1.5  3.5   14  126", COLOR_MAGENTA, COLOR_BLACK);
	gameFrame.addText(2, 4, "SCORE:", COLOR_GREEN, COLOR_BLACK);

	for (int i = 0; i < nRows; i++)
	{
		//format double to string
		scoreString = to_string(galtonData[nRows - 1]->at(i)  * values[i]);
		scoreString.erase(scoreString.find_last_not_of('0') + 1, std::string::npos);
		if (scoreString.back() == '.')
		{
			scoreString.pop_back();
		}

		score += (galtonData[nRows-1]->at(i) * values[i]);

		//print scores vertically
		for (int j = 0; j < scoreString.length(); j++) 
		{
			gameFrame.addCharacter(12+(i*5), 4+j, scoreString[j], COLOR_GREEN, COLOR_BLACK); 
		}

		//print plus sign between scores
		if (i < nRows - 1)
		{
			gameFrame.addText(15 + (i * 5), 4, "+", COLOR_RED, COLOR_BLACK);
		}
	}

	string totalScoreString = to_string(score);
	totalScoreString.erase(totalScoreString.find_last_not_of('0') + 1, std::string::npos);

	string congrats = "Congratulations, " + userName + "!";
	gameFrame.addText((gameFrame.getLength()/2) - (congrats.length()/2), 13, congrats);
	gameFrame.addText((gameFrame.getLength() / 2) - (totalScoreString.length()/2) - 12, 14, "Your score in Game #"+to_string(gameNumber)+" is " + totalScoreString, COLOR_YELLOW, COLOR_BLACK);

	if (totalScoreString.back() == '.')
	{
		totalScoreString.back() = ' ';
	}
	historyString += ("Game #" + to_string(gameNumber) + ":        " + totalScoreString + "\n");
}

void JamesPP::displayScoreTable(vector< vector<int>* > galtonData)
{
	Frame scoreTableFrame(68, 2, 30, 34, userName + "'s Game History");
	TextArea TA = scoreTableFrame.addTextArea();
	TA.addText(0,0,historyString);

	ButtonMenu bMenu(68, 35, 30, 3, "< Write >", "< Back >");

	ofstream myfile("scores.txt", ios_base::app);
	switch (bMenu.getButtonChoice())
	{
	case 1:
		
		if (myfile.is_open())
		{
			myfile << historyString;
			myfile.close();
		}
		else
		{
			DialogFrame::showMessageDialog(mainFrame, "Continue", "ERROR", "Unable to open file 'scores.txt'.");
		}
		break;

	case 2:
		mainFrame.drawWin();
		drawGameFrames(galtonData);
		break;
	}

	getch();
}

void JamesPP::drawGameFrames(vector< vector<int>* > galtonData)
{
	displayFlowFrame(galtonData);

	displayVariableFrame();

	displayGameFrame(galtonData);

	displayGameOptions(galtonData);
}

void JamesPP::goGalton()
{

	mainFrame.drawWin();

	vector< vector<int>* > rows = getGaltonRows();
	
	displayFlowFrame(rows);

	displayVariableFrame();

	displayGraphFrame(rows);


	NavigationMenu optionFrame(68, 18, 30, 18, "OPTIONS", "DROP BALLS", "Edit number of balls", "Edit number of rows", "Edit left chance", "Edit right chance", "Change graph direction");
	optionFrame.setMenuOptions("< Select >", "< Back >");
	optionFrame.setTextXY(4, 6);

	switch (optionFrame.getMenuChoice())
	{
		case 0:
			mainMenu();
			break;

		case 1:
			goGalton();
			break;

		case 2:
			nBalls = atoi(DialogFrame::showInputDialog(mainFrame, "< Submit >", "Edit number of balls", "Please enter the number of balls to drop:").c_str());
			goGalton();
			break;

		default:
			exit(1);
			break;
	}
	



	getch();

}

void JamesPP::displayGameOptions(vector< vector<int>* > galtonData)
{
	NavigationMenu optionFrame(68, 18, 30, 18, "OPTIONS", "DROP BALLS", "Edit number of balls", "Edit number of rows", "Edit left chance", "Edit right chance", "Score Table ");
	optionFrame.setMenuOptions("< Select >", "< Back >");
	optionFrame.setTextXY(4, 6);

	switch (optionFrame.getMenuChoice())
	{
	case 0:
		mainMenu();
		break;

	case 1:
		playGame();
		break;

	case 2:
		nBalls = atoi(DialogFrame::showInputDialog(mainFrame, "< Submit >", "Edit number of balls", "Please enter the number of balls to drop:").c_str());
		playGame();
		break;

	case 6:
		
		displayScoreTable(galtonData);
		break;

	default:
		exit(1);
		break;
	}

}

void JamesPP::playGame()
{
	gameNumber += 1;

	mainFrame.drawWin();

	vector< vector<int>* > rows = getGaltonRows();

	drawGameFrames(rows);



	//WINDOW* win = JamesOptionPanes::jamesFrame(80, 36);
	//JamesPP::showGalton(win, false);
	//string aString = "";
	//double score = 0;
	//string scoreString = "";
	//



	//double values[]{ 126, 14, 3.5, 1.5, 1, 1, 1.5, 3.5, 14, 126 };

	//gameNumber += 1;

	//wattron(win, COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));
	//mvwprintw(win, 14, 2, "WEIGHT:    126    14   3.5   1.5    1     1    1.5   3.5    14   126");
	//wattroff(win, COLOR_PAIR(cwt::colorPair(COLOR_MAGENTA, COLOR_BLACK)));
	//mvwprintw(win, 16, 2, "SCORE:");

	//wattron(win, COLOR_PAIR(cwt::colorPair(COLOR_CYAN, COLOR_BLACK)));
	//for (int i = 0; i < 10; i++)
	//{



	//	aString = to_string(gBox[i] * values[i]);
	//	aString.erase(aString.find_last_not_of('0') + 1, std::string::npos);
	//	if (aString.back() == '.')
	//	{
	//		aString.pop_back();
	//	}
	//	
	//	
	//	score += (gBox[i] * values[i]);
	//	mvwprintw(win, 16, 13+i*6, (char*)aString.c_str());

	//}
	//wattroff(win, COLOR_PAIR(cwt::colorPair(COLOR_CYAN, COLOR_BLACK)));

	//for (int t = 0; t < getmaxx(win) - 2; t++)
	//{
	//	mvwaddch(win, 13, 1 + t, ACS_HLINE);
	//	mvwaddch(win, 15, 1 + t, ACS_HLINE);
	//	mvwaddch(win, 17, 1 + t, ACS_HLINE);
	//	mvwaddch(win, 30, 1 + t, ACS_HLINE);

	//}

	//

	//scoreString = to_string(score);
	//scoreString.erase(scoreString.find_last_not_of('0') + 1, std::string::npos);

	//string congrats = "Congratulations, " + userName + "! Your score in game #" + to_string(gameNumber) + " is " + scoreString ;

	//ofstream myfile("scores.txt", ios_base::app);
	//if (myfile.is_open())
	//{
	//	myfile << scoreString + "\n";
	//	myfile.close();
	//}
	//else
	//{
	//	JamesOptionPanes::showMessage(mainWindow, "ERROR", "Unable to open file 'scores.txt'.");
	//}

	//wattron(win, COLOR_PAIR(cwt::colorPair(COLOR_WHITE, COLOR_BLACK)));
	//cwt::mvwprintwCentered(win, 24, (char*)congrats.c_str());
	//wattroff(win, COLOR_PAIR(cwt::colorPair(COLOR_WHITE, COLOR_BLACK)));

	//wattron(win, COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));
	//cwt::mvwprintwCentered(win, 1, "   PLAY GAME");
	//cwt::mvwprintwCentered(win, 32, "Press <ESC> to return to main menu");
	//cwt::mvwprintwCentered(win, 33, "Press <ENTER> to drop again");
	//wattroff(win, COLOR_PAIR(cwt::colorPair(COLOR_GREEN, COLOR_BLACK)));

	//wrefresh(win);

	//int keyPress = wgetch(win);

	////test key input
	//if (keyPress == 10)
	//{
	//	touchwin(win);
	//	wclear(win);
	//	delwin(win);
	//	
	//	JamesPP::playGame();
	//}

	//if (keyPress = 27)
	//{
	//	touchwin(win);
	//	wclear(win);
	//	delwin(win);
	//	refreshBackground();
	//	mainMenu();
	//}

	//
}

void JamesPP::displayGameHistory()
{
	//WINDOW* win = JamesOptionPanes::jamesFrame(80, 12 + gameNumber);
	//string summary = "So far, " + userName + ", you have played " + to_string(gameNumber) + " game(s) with the following scores:";
	//string game;
	//
	//string line;
	//vector<string> myLines;
	//myLines.clear();

	//ifstream myFile("scores.txt", ios_base::in);
	//while (getline(myFile, line, '\n'))
	//{
	//	myLines.push_back(line);
	//}


	//cwt::mvwprintwCentered(win, 4, (char*)summary.c_str());
	//cwt::mvwprintwCentered(win, 1, "GAME HISTORY");

	//
	//for (int i = 1; i <= gameNumber; i++)
	//{
	//	
	//	if (myLines[i - 1].back() == '.')
	//	{
	//		myLines[i - 1].pop_back();
	//	}

	//	game = "Game #" + to_string(i) + ": " + myLines[i - 1];


	//	mvwprintw(win, 6 + i, 10, (char*)game.c_str());
	//}

	//wattron(win, A_BOLD | WA_BLINK);
	//mvwprintw(win, (getmaxy(win) - 3), ((getmaxx(win) / 2) - 4), "CONTINUE");
	//wattroff(win, A_BOLD | WA_BLINK);
	//wrefresh(win);

	//JamesOptionPanes::hitEnter(win);
	//
	//touchwin(win);
	//wclear(win);
	//delwin(win);
	//refreshBackground();
	//mainMenu();

	//	//"GAME HISTORY", "So far, " + userName + ", you have played " + to_string(gameNumber) + " games with the following scores: \n\n");
	//
	//
}

void JamesPP::displayIDInfo()
{
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
	//refreshBackground();
	//mainMenu();
}

void JamesPP::displayStars()
{
	/*JamesOptionPanes::showMessage(
		mainWindow,
		"ID INFORMATION",
		"      Programmer         : James McCarthy   \n"
		"      Assignment #       : TA #1.2CA        \n"
		"      Assignment Name    : Cellular Automata\n"
		"      Course # and Title : CISC 205 - OOPS  \n"
		"      Class Meeting Time : TTh 9:35 - 12:40 \n"
		"      Instructor         : Professor Forman \n"
		"      Hours              : 15               \n"
		"      Difficulty         : 5                \n"
		"      Completion Date    : 9/11/2014        \n"
		"      Project Name       : JamesCA          \n");


	refreshBackground();
	mainMenu();*/
}

void JamesPP::farewell()
{
	//JamesOptionPanes::showMessage(mainWindow, "Farewell", "Farewell, " + userName + ". Thank you for visiting " + MY_NAME + "' Pointer Power!");

	////touchwin(mainWindow);
	////wrefresh(mainWindow);
	////delwin(mainWindow);

	////touchwin(stdscr);
	////wrefresh(stdscr);

	//exit(1);

	
}