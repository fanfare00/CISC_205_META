#ifndef TESTINGGROUND_H
#define TESTINGGROUND_H


#include "../util/cwt/CursesWindowToolkit.h"
#include "curses.h"


class TestingGround
{
public:
	

	static TestingGround& getInstance();
	~TestingGround();

	void start();



};

#endif /* TESTINGGROUND_H */

