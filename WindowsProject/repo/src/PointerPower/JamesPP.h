#ifndef JAMESPP_H
#define JAMESPP_H

#include "../util/JamesOptionPanes.h"
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
	const string MY_NAME = "James";
	char* defaultStatus = "You are currently not signed in.";
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
	void farewell();

	vector< vector<int>* > getGaltonRows();
	void displayFlowFrame(vector< vector<int>* > galtonData);
	void displayVariableFrame();
	void displayGraphFrame(vector< vector<int>* > galtonData);
	void displayGameFrame(vector< vector<int>* > galtonData);

	void displayScoreTable(vector< vector<int>* > galtonData);
	void displayGameOptions(vector< vector<int>* > galtonData);
	void drawGameFrames(vector< vector<int>* > galtonData);

	int nRows = 10;
	int nBalls = 1000;
	int leftRight = 0;
	int counter = 0;

	int leftChance = 50;
	int rightChance = 100 - leftChance;

	string graphDirection = "Up";

	int gameNumber = 0;

	string historyString = "";
};

#endif /* JAMESPP_H */