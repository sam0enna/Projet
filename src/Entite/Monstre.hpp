#ifndef ENTITE_H
#define ENTITE_H

#include <SFML/Graphics.hpp>
#include "../Screen/ScreenState.hpp"

using namespace std;
using namespace sf;

class Monstre : public Entite
{
			
	public:
		Monstre(string nom);
		~Monstre();
		Sprite getSprite();
	    void draw(RenderWindow& window);
	    void setPosition(int,int);
	    void estMort();
	    
	private:
		Texture vivant;
		Texture mort;

		
};


#endif
