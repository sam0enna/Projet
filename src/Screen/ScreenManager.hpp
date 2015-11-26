/*!
* \file 
* \brief 
* \author 
* \author 
* \date 
*/

#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "ScreenState.hpp"
#include "Menu.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

/*!
* \class 
* \brief 
*/
class ScreenManager
{
	public :
		ScreenManager();
		~ScreenManager();
		void init();
		void setCurrentScreen(ScreenState*);
		ScreenState* getCurrentScreen();
		void loadScreen();
		void draw(RenderWindow &window);
	
	private :		
		ScreenState* currentScreen_;//!<
};

#endif //SCREENMANAGER_H
