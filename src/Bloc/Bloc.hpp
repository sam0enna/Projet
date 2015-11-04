#ifndef BLOC_H
#define BLOC_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Bloc
{
	private: 
		Sprite* sprite;
		bool cassable;
	
	public:
		Bloc (sf::Texture& texture,int x, int y);
		~Bloc();
		bool estCassable();
		void setCassable(bool);
		virtual Bloc* quandCasse();
		void display(RenderWindow& window);
};

#endif
