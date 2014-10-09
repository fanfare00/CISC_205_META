#include "../util/JamesCurses.h"
#include "../util/JamesOptionPanes.h"
#include <string>
#include <vector>

class JamesPP
{
public:

	vector<int>     box;
	int gameNumber = 0;

	string userName = "Unknown User";
	const string MY_NAME = "James";
	char* defaultStatus = "You are currently not signed in.";
	WINDOW* mainWindow;

	static JamesPP& getInstance();
	~JamesPP();

	void start();
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