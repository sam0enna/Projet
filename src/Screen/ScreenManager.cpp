/*!
* \file ScreenManager.cpp
* \brief Fichier contenant l'implémentation de la classe ScreenManager
* \author Samia Ennaji
* \date 27.11.2015
*/

#include "ScreenManager.hpp"

//--------------------------------------------------
/*!
* \brief Constructeur
*/
ScreenManager::ScreenManager()
{
}

//--------------------------------------------------
/*!
* \brief Destructeur
*/
ScreenManager::~ScreenManager()
{
	delete currentScreen_;
}

//--------------------------------------------------
/*!
* \brief Méthode qui initialise un ScreenManager
*/
void ScreenManager::init(){
	currentScreen_ = new Menu();
	currentScreen_->load();
}

//--------------------------------------------------
/*!
* \brief Méthode qui modifie l'écran courant
* \param new_screen le nouvel écran
*/
void ScreenManager::setCurrentScreen(ScreenState* new_screen)
{
	if(currentScreen_->getType()==MENU)
	{
		switch(new_screen->getType()){
			case MENU:
				delete new_screen;
			break;
			
			case GAME:
				delete currentScreen_;
				currentScreen_ = new_screen;
				loadScreen();
			break;
			
			default:
			break;
		}
	}
	else if(currentScreen_->getType()==GAME)
	{
		switch(new_screen->getType()){
			case MENU:
				delete currentScreen_;
				currentScreen_ = new_screen;
				loadScreen();
			break;
			
			case GAME:
				delete new_screen;
			break;
			
			case FIN:
				delete currentScreen_;
				currentScreen_ = new_screen;
				loadScreen();
			break;
			
			default:
			break;
		}		
	}
	else{
		delete currentScreen_;
		currentScreen_ = new_screen;
		loadScreen();
	}
}

//--------------------------------------------------
/*!
* \brief Méthode qui retourne l'écran courant
*/
ScreenState* ScreenManager::getCurrentScreen()
{
	return currentScreen_;
}

//--------------------------------------------------
/*!
* \brief Méthode qui charge le contenu de l'écran courant
*/
void ScreenManager::loadScreen()
{
	currentScreen_->load();
}

//--------------------------------------------------
/*!
* \brief méthode qui affiche l'écran courant
*/
void ScreenManager::draw(RenderWindow &window)
{
	currentScreen_->draw(window);
}
