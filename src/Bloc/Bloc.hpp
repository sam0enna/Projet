#ifndef BLOC_H
#define BLOC_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Bloc
{
	private: 
		Sprite* sprite;
		bool cassable;
		bool victoire;
	
	public:
		Bloc (int x, int y);
		~Bloc();
		bool estCassable();
		void setCassable(bool);
		Bloc* quandCasse();
		void display(RenderWindow& window);
		Sprite* getSprite();
		Vector2f getPosition();
		void setVictoire(bool);
		bool estVictorieux();
		
};

#endif
