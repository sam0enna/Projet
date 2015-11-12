#ifndef ENTITE_H
#define ENTITE_H

#include <SFML/Graphics.hpp>
#include "../Screen/ScreenState.hpp"

using namespace std;
using namespace sf;

class Entite
{
			
	public:
		Entite();
		~Entite();
		Sprite getSprite();
	    void display(RenderWindow& window);
	    
	protected:
		Sprite sprite;
		
};


#endif
