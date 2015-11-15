#ifndef ETOILE_H
#define ETOILE_H

#include <SFML/Graphics.hpp>
#include "../Screen/ScreenState.hpp"
#include "Entite.hpp"

using namespace std;
using namespace sf;

class Etoile : public Entite{
			
	public:
		Etoile();
		~Etoile();
		void setPosition(int x, int y);
		Sprite getSprite();
		void draw(RenderWindow& window);
	    
	protected:
		Texture star;
		
};


#endif
