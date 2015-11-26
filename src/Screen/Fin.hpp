#ifndef FIN_H
#define FIN_H
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "ScreenState.hpp"

class Fin : public ScreenState 
{
	public :
		Fin(bool);
		~Fin();
		void load();
		void unload();
		void move(int x,int y);
		void draw(RenderWindow &window);
		
	private :
		bool victoire_;
		sf::Font font;
		sf::Text play;

};
#endif //FIN_H
