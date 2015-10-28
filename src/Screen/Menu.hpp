#ifndef MENU_H
#define MENU_H
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "ScreenState.hpp"

class Menu : public ScreenState 
{
	public :
		Menu();
		~Menu();
		void load();
		void unload();
		void draw(RenderWindow &window);
		
	private :
		sf::Font font;
		sf::Text play;

};
#endif //MENU_H
