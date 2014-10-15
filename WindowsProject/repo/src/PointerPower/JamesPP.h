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

	vector<int>     gBox;
	int gameNumber = 0;

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

	void showGalton(WINDOW* win, bool showHistogram);

};

#endif /* JAMESPP_H */