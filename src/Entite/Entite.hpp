#ifndef ENTITE_H
#define ENTITE_H

#include <SFML/Graphics.hpp>
#include "../Screen/ScreenState.hpp"
#include "ActionBonus.hpp"
#include "BonusVie.hpp"

using namespace std;
using namespace sf;

class Entite
{
			
	public:
		Entite();
		~Entite();
		Sprite getSprite();
	    void draw(RenderWindow& window);
	    void setPosition(int,int);
	    virtual int doAction();
	    
	protected:
		Sprite sprite;
		ActionBonus* action;
		
};


#endif
