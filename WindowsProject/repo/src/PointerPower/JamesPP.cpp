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
	setUpGaltonData();

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

	mainFrame.addText((mainFrame.getLength() / 2) - 16, (mainFrame.getWidth() / 2), "Welcome to James' Pointer Power!", COLOR_GREEN, COLOR_BLUE);
	mainFrame.addText((mainFrame.getLength() / 2) - 11, (mainFrame.getWidth() / 2) + 1, "Press <ENTER> to Begin.", COLOR_GREEN, COLOR_BLUE);

	cwt::hitEnter();
	mainFrame.addText((mainFrame.getLength() / 2) - 18, (mainFrame.getWidth() / 2), "                                     ");
	mainFrame.addText((mainFrame.getLength() / 2) - 11, (mainFrame.getWidth() / 2) + 1, "                       ");

	mainFrame.drawWin();
	mainMenu();

}

void JamesPP::mainMenu()
{
	mainFrame.addText(2, mainFrame.getWidth() - 2, defaultStatus, COLOR_GREEN, COLOR_BLUE);

	mainFrame.drawWin();


	NavigationMenu NM((mainFrame.getLength() / 2) - 25, (mainFrame.getWidth() / 2) - 9, 50, 16,
		"MAIN MENU", "Sign In", "Display Logo", "Go Galton", "Play Game", "Game History", "ID Information", "Credits", "Stars");

	NM.setMenuOptions("< Select >", "< Exit >", "< Help >");

	switch (NM.getMenuChoice())
	{
	case 0:
		farewell();
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
		displayGameHistory();
		break;

	case 6:
		displayIDInfo();
		break;

	case 7:
		displayCredits();
		break;

	case 8:
		displayStars();
		break;

	default:
		
		break;
	}

}

void JamesPP::signIn()
{
	
	string lastName;
	string middleName;
	string temp;

	userName = DialogFrame::showInputDialog(mainFrame, "Continue", "SIGN IN", "Please enter your full name:");
	

	temp = userName;

	firstName = temp.substr(0, temp.find(" "));

	//temp = temp.substr(temp.find(" ") + 1);
	//middleName = temp.substr(0, temp.find(" "));

	lastName = temp.substr(temp.find(" ") + 1);


	mainFrame.drawWin();

	if (firstName != lastName)
	{
		DialogFrame::showMessageDialog(mainFrame, "Continue", "WELCOME",
			"\nFirst Name: " + firstName + "\n"
			"Last Name: " + lastName + "\n"
			"\nYou have succsessfuly signed in to " + MY_NAME + "' Pointer Power. Welcome " + firstName + ".");
	}
	else
	{

		lastName = "Unknown";
		DialogFrame::showMessageDialog(mainFrame, "Continue", "WELCOME",
			"\nFirst Name: " + firstName + "\n"
			"Last Name: " + lastName + "\n"
			"\nYou have succsessfuly signed in to " + MY_NAME + "' Pointer Power. Welcome " + firstName + ".");
	}
	

	historyString += "User: " + userName + "\n";
	defaultStatus = "You are currently signed in as: " + userName;
	gameNumber = 0;

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


}


void JamesPP::setUpGaltonData()
{

	for (int i = 0; i < nRows; i++)
	{

		galtonData.push_back(new vector<int>);

		//fill the vector with appropriate amount of 0s
		for (int j = 0; j < galtonData.size(); j++)
		{
			galtonData[i]->push_back(0);
		}
	}
}


void JamesPP::generateGaltonData()
{
	srand(time(NULL));

	int counter;
	int leftRight;

	//int chance = 9;


	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < galtonData[i]->size(); j++)
		{
			galtonData[i]->at(j) = 0;
		}
		
	}

	for (int i = 0; i < nRows; i++)
	{
		for (int b = 0; b < nBalls; b++)
		{
			counter = 0;

			for (int j = 0; j < i; j++)
			{
				//leftRight = (rand() % chance) / (chance-1);
				//leftRight = leftRight;
				//counter = counter + leftRight;
				if (rand() % 100 < rightChance)
				{
					counter++;
				}
				
			}

			galtonData[i]->at(counter) += 1;
		}
	}

}


void JamesPP::updateFlowData(Frame galtonFrame)
{
	int nRows = galtonData.size();
	string buttonSpace = "   ";
	int adjustment = 4;

	if (nBalls >= 10000)
	{
		buttonSpace = "  ";
		adjustment -= 1;
	}


	string centerNumbers;
	for (int i = 0; i < nRows; i++)
	{
		centerNumbers = "";
		galtonFrame.addText(2, i + 3, to_string(i) + ":", COLOR_MAGENTA, COLOR_BLACK);
		for (int j = 0; j < galtonData[i]->size(); j++)
		{

			centerNumbers += to_string(galtonData[i]->at(j)) + buttonSpace;
		}

		galtonFrame.addText(4, i + 3, "                                                ");
		galtonFrame.addText(((galtonFrame.getLength() / 2) - centerNumbers.length() / 2) + adjustment, i + 3, centerNumbers);
	}

	galtonFrame.drawBorder();

}

void JamesPP::updateVariableData(Frame variableFrame)
{
	variableFrame.addText(variableFrame.getLength() - 6, 2,  "     ");
	variableFrame.addText(variableFrame.getLength() - 6, 4,  "     ");
	variableFrame.addText(variableFrame.getLength() - 6, 6,  "     ");
	variableFrame.addText(variableFrame.getLength() - 6, 8,  "     ");
	variableFrame.addText(variableFrame.getLength() - 6, 10, "     ");

	variableFrame.addText(variableFrame.getLength() - 2 - to_string(nBalls).length(), 2, to_string(nBalls));
	variableFrame.addText(variableFrame.getLength() - 2 - to_string(nRows).length(), 4, to_string(nRows));
	variableFrame.addText(variableFrame.getLength() - 2 - to_string(leftChance).length() - 1, 6, to_string(leftChance) + "%%");
	variableFrame.addText(variableFrame.getLength() - 2 - to_string(rightChance).length() - 1, 8, to_string(rightChance) + "%%");
	variableFrame.addText(variableFrame.getLength() - 2 - graphDirectionString.length(), 10, graphDirectionString);
}

Frame JamesPP::setUpVariableFrame()
{
	Frame variableFrame(68, 2, 30, 15, "VARIABLES");
	variableFrame.setBackground(COLOR_BLACK);
	variableFrame.setForeground(COLOR_WHITE);
	variableFrame.drawBorder();

	variableFrame.addText(2, 2, "Number of balls    :");
	variableFrame.addText(2, 4, "Rows               :");
	variableFrame.addText(2, 6, "Chance to go left  :");
	variableFrame.addText(2, 8, "Chance to go right :");
	variableFrame.addText(2, 10, "Graph direction    :");

	return variableFrame;

}


Frame JamesPP::setUpGraphFrame()
{
	int nRows = galtonData.size();

	Frame graphFrame(2, 18, 65, 20, "HISTOGRAM");
	graphFrame.setBackground(COLOR_BLACK);
	graphFrame.setForeground(COLOR_WHITE);
	graphFrame.drawBorder();


	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			graphFrame.addCharacter(7 + (i * 5), 2 + j, ACS_VLINE);
		}

		//draw slot number
		graphFrame.addText(9 + (i * 5), 17, to_string(i));
	}

	graphFrame.addText(9 + (50), 17, "  ");

	for (int i = 0; i < 51; i++)
	{
		if (i % 5 == 0)
		{
			graphFrame.addCharacter(7 + i, 18, ACS_BTEE);
			graphFrame.addCharacter(7 + i, 16, ACS_PLUS);
		}
		else
		{
			graphFrame.addCharacter(7 + i, 18, ACS_HLINE);
			graphFrame.addCharacter(7 + i, 16, ACS_HLINE);
		}
	}

	return graphFrame;
}

void JamesPP::updateGraphData(Frame graphFrame)
{
	int scale = 50;
	int lowBallCountAdjustment = 0;

	if ( (rightChance >= 75) | (leftChance >= 75) )
	{
		scale = 40;
	}

	if ((rightChance >= 85) | (leftChance >= 85))
	{
		scale = 33;
	}

	if ((rightChance >= 95) | (leftChance >= 95))
	{
		scale = 20;
	}

	if (nBalls < 500)
	{
		scale = 33;
	}

	if ( (nBalls < 500) && ((leftChance >= 80) | (rightChance >= 80)) )
	{
		scale = 20;
	}

	if (nBalls < 33)
	{
		lowBallCountAdjustment = 1;
	}

	int dynamicBallNumber = ((lowBallCountAdjustment + (nBalls / scale)));

	if (graphDirection == 0)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				graphFrame.addText(8 + (i * 5), 1 + j, "    ");
			}
			//draw left side ball count meter
			graphFrame.addText(3, 16 - (2 * i), to_string(i * dynamicBallNumber * 2));

			for (int b = 0; b < galtonData[nRows - 1]->at(i); b++)
			{
				graphFrame.addText(8 + (i * 5), 16 - (b + 1) / dynamicBallNumber, "    ", COLOR_BLACK, COLOR_RED);
				graphFrame.addText(8 + (i * 5), 16, "----");
			}
		}
		graphFrame.addText(3, 0, "-----", COLOR_WHITE, COLOR_WHITE);
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				graphFrame.addText(8 + (i * 5), 3 + j, "    ");
			}
			//draw left side ball count meter
			graphFrame.addText(3, 2 + (2 * i), "   ");
			graphFrame.addText(3, 2 + (2 * i), to_string(i * dynamicBallNumber));

			for (int b = 0; b < galtonData[nRows - 1]->at(i); b++)
			{
				graphFrame.addText(8 + (i * 5), 2 + (b + 1) / dynamicBallNumber, "    ", COLOR_BLACK, COLOR_RED);
				graphFrame.addText(8 + (i * 5), 2, "----");

			}
		}
		graphFrame.addText(3, 18, "   ");
	}

	
}


void JamesPP::updateGameData(Frame gameFrame)
{
	gameFrame.addText((gameFrame.getLength() / 2) - 17, gameFrame.getWidth() / 2, "                                   ");

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

void JamesPP::displayScoreTable()
{

	Frame scoreTableFrame(68, 2, 30, 34, firstName + "'s Game History");
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
		DialogFrame::showMessageDialog(mainFrame, "Continue", "WRITE SUCCESSFUL", "The following data has been saved to disk:\n" + historyString);
		mainFrame.drawWin();
		playGame();
		break;

	case 2:
		mainFrame.drawWin();
		playGame();
		break;
	}

	getch();
}

void JamesPP::goGalton()
{
	requireLogin();

	mainFrame.drawWin();

	Frame galtonFrame(2, 2, 65, 15, "GALTON FLOW");
	galtonFrame.setBackground(COLOR_BLACK);
	galtonFrame.setForeground(COLOR_WHITE);
	galtonFrame.drawBorder();

	Frame variableFrame = setUpVariableFrame();
	updateVariableData(variableFrame);

	Frame graphFrame = setUpGraphFrame();

	NavigationMenu graphMenu(68, 18, 30, 18, "OPTIONS", "DROP BALLS", "Edit number of balls", "Edit number of rows", "Increase left chance", "Increase right chance", "Change graph direction");
	graphMenu.setMenuOptions("< Select >", "< Back >");
	graphMenu.setTextXY(4, 6);

	loopGraphMenu(graphMenu, graphFrame, galtonFrame, variableFrame);

	getch();
}

void JamesPP::loopGraphMenu(NavigationMenu graphMenu, Frame graphFrame, Frame galtonFrame, Frame variableFrame)
{
	switch (graphMenu.getMenuChoice())
	{
	case 0:
		mainMenu();
		break;

	case 1:
		generateGaltonData();
		updateGraphData(graphFrame);
		updateFlowData(galtonFrame);
		loopGraphMenu(graphMenu, graphFrame, galtonFrame, variableFrame);
		break;

	case 2:
		nBalls = atoi(DialogFrame::showInputDialog(mainFrame, "< Submit >", "Edit number of balls", "Please enter the number of balls to drop:").c_str());
		goGalton();
		break;

	case 4:
		if (leftChance < 100)
		{
			leftChance += 5;
			rightChance -= 5;
		}
		updateVariableData(variableFrame);
		loopGraphMenu(graphMenu, graphFrame, galtonFrame, variableFrame);
		break;

	case 5:
		if (rightChance < 100)
		{
			rightChance += 5;
			leftChance -= 5;
		}
		updateVariableData(variableFrame);
		loopGraphMenu(graphMenu, graphFrame, galtonFrame, variableFrame);
		break;

	case 6:
		if (graphDirection == 1)
		{
			graphDirectionString = "  Up";
			graphDirection = 0;
		}
		else
		{
			graphDirectionString = "Down";
			graphDirection = 1;
		}
		updateVariableData(variableFrame);
		updateGraphData(graphFrame);
		loopGraphMenu(graphMenu, graphFrame, galtonFrame, variableFrame);
		break;

	default:
		exit(1);
		break;
	}

}



void JamesPP::playGame()
{
	requireLogin();
	mainFrame.drawWin();

	Frame flowFrame(2, 2, 65, 15, "GALTON FLOW");
	flowFrame.setBackground(COLOR_BLACK);
	flowFrame.setForeground(COLOR_WHITE);
	flowFrame.drawBorder();

	Frame variableFrame = setUpVariableFrame();
	updateVariableData(variableFrame);
	variableFrame.addText(2, 10, "                           ");


	Frame gameFrame(2, 18, 65, 20, "GAME SCORE");
	gameFrame.setBackground(COLOR_BLACK);
	gameFrame.setForeground(COLOR_WHITE);
	gameFrame.drawBorder();
	gameFrame.addText((gameFrame.getLength() / 2) - 17, gameFrame.getWidth() / 2, "Select DROP BALLS to start playing.");
	
	NavigationMenu gameMenu(68, 18, 30, 18, "OPTIONS", "DROP BALLS", "Edit number of balls", "Edit number of rows", "Edit left chance", "Edit right chance", "Score Table ");
	gameMenu.setMenuOptions("< Select >", "< Back >");
	gameMenu.setTextXY(4, 6);

	loopGameMenu(gameMenu, flowFrame, gameFrame, variableFrame);

	//generateGaltonData();
}


void JamesPP::loopGameMenu(NavigationMenu gameMenu, Frame flowFrame, Frame gameFrame, Frame variableFrame)
{
	//variableFrame.addText(2, 10, "                           ");

	switch (gameMenu.getMenuChoice())
	{
	case 0:
		mainMenu();
		break;

	case 1:
		gameNumber++;
		generateGaltonData();
		updateFlowData(flowFrame);
		updateGameData(gameFrame);
		loopGameMenu(gameMenu, flowFrame, gameFrame, variableFrame);
		break;

	case 2:
		nBalls = atoi(DialogFrame::showInputDialog(mainFrame, "< Submit >", "Edit number of balls", "Please enter the number of balls to drop:").c_str());
		playGame();
		break;

	case 6:
		displayScoreTable();
		break;

	default:
		exit(1);
		break;
	}

}


void JamesPP::displayGameHistory()
{
	requireLogin();

	DialogFrame::showMessageDialog(mainFrame, "< Continue >","GAME HISTORY" , historyString);
	mainFrame.drawWin();
	mainMenu();

}

void JamesPP::displayIDInfo()
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

void JamesPP::displayCredits()
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


void JamesPP::displayStars()
{
	requireLogin();

	DialogFrame::showMessageDialog(
		mainFrame,
		"< CONTINUE >", "STARS",
		"Insert stars here");

	mainFrame.drawWin();
	mainMenu();
}

void JamesPP::farewell()
{
	DialogFrame::showMessageDialog(mainFrame, "< EXIT >", "GOODBYE", "Farewell, " + userName + ". Thank you for using " + MY_NAME + "' Pointer Power");
	exit(1);

	
}

void JamesPP::requireLogin()
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