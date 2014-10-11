#ifndef COLOR_H
#define COLOR_H

#include "curses.h"
#include <string>


namespace cwt
{
	inline void loadColor();
	inline int colorPair(int foreColor, int backColor);
	

	
}

inline void cwt::loadColor()
{
	start_color();

	for (int foreColor = 0; foreColor < 8; foreColor++)
	{
		for (int backColor = 0; backColor < 8; backColor++)
		{
			init_pair((foreColor * 10) + backColor, foreColor, backColor);
		}
	}

}

inline int cwt::colorPair(int foreColor, int backColor)
{
	return (foreColor * 10) + backColor;
}



#endif /* COLOR_H */