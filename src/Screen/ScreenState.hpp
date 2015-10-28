#ifndef SCREENSTATE_H
#define SCREENSTATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define MENU 0
#define GAME 1

using namespace std;
using namespace sf;

class ScreenState
{
	public :
		ScreenState();
		~ScreenState();
		int getType();
		virtual void load();
		virtual void unload();
		virtual void draw(RenderWindow &window);
		
	protected:
		int type;
	
};

#endif //SCREENSTATE_H