#include "ScreenManager.hpp"

ScreenManager::ScreenManager()
{
}

ScreenManager::~ScreenManager()
{
	delete currentScreen_;
}

void ScreenManager::init(){
	currentScreen_ = new Menu();
	currentScreen_->load();
}

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
		cout<<"chargement fin"<<endl;
		delete currentScreen_;
		currentScreen_ = new_screen;
		loadScreen();
	}
}

ScreenState* ScreenManager::getCurrentScreen()
{
	return currentScreen_;
}

void ScreenManager::loadScreen()
{
	currentScreen_->load();
}

void ScreenManager::draw(RenderWindow &window)
{
	currentScreen_->draw(window);
}
