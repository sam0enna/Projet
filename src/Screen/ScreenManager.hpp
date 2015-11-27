/*!
* \file ScreenManager.hpp
* \brief Fichier contenant la déclaration de la classe ScreenManager
* \author Samia Ennaji
* \date 27.11.2015
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
* \class ScreenManager
* \brief classe qui gère les écrans suivant le pattern state
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
		ScreenState* currentScreen_;//!< l'écran courant
};

#endif //SCREENMANAGER_H
