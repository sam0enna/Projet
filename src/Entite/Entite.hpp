class Joueur;
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
	    virtual void draw(RenderWindow& window);
	    void setPosition(int,int);
	    void doAction(Joueur* j);
	    
	protected:
		Sprite sprite;
		ActionBonus* action;
		
};


#endif
