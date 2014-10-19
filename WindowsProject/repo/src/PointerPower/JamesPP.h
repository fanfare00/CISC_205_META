#ifndef JAMESPP_H
#define JAMESPP_H

#include "../util/cwt/CursesWindowToolkit.h"
#include "curses.h"
#include <string>
#include <vector>


using namespace std;
class JamesPP
{
public:
	Frame mainFrame;

	string userName = "Unknown User";
	string firstName = "Unknown";
	const string MY_NAME = "James";
	string defaultStatus = "You are not currently signed in.";
	//WINDOW* mainWindow;

	static JamesPP& getInstance();
	~JamesPP();

	void start(Frame mFrame);
	void setup();
	void refreshBackground();
	void welcomeScreen();
	void mainMenu();

	void signIn();
	void displayLogo();
	void goGalton();
	void playGame();
	void displayGameHistory();
	void displayIDInfo();
	void displayStars();
	void displayCredits();
	void farewell();
	
	void loopGraphMenu(NavigationMenu graphMenu, Frame graphFrame, Frame galtonFrame, Frame variableFrame);

	Frame setUpGraphFrame();
	void updateGraphData(Frame graphFrame);
	void clearGraphData();
	
	void displayFlowFrame();
	void updateFlowData(Frame galtonFrame);


	Frame setUpVariableFrame();
	void updateVariableData(Frame variableFrame);
	
	void updateGameData(Frame gameFrame);

	void displayScoreTable();
	void loopGameMenu(NavigationMenu gameMenu, Frame flowFrame, Frame gameFrame, Frame variableFrame);
	void drawGameFrames();

	void requireLogin();

	
	int nRows = 10;
	int nBalls = 1000;
	int leftRight = 0;
	int counter = 0;

	int leftChance = 50;
	int rightChance = 100 - leftChance;

	string graphDirectionString = "Up";
	int graphDirection = 0;

	int gameNumber = 0;

	string historyString = "";
	

	vector< vector<int>* > galtonData;
	void generateGaltonData();
	void setUpGaltonData();

};

#endif /* JAMESPP_H */