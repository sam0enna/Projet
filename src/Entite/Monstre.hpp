#ifndef MONSTRE_H
#define MONSTRE_H

#include <SFML/Graphics.hpp>
#include "../Screen/ScreenState.hpp"
#include "Entite.hpp"
#include "ActionBonus.hpp"
#include "MalusVie.hpp"

using namespace std;
using namespace sf;

class Monstre : public Entite
{
			
	public:
		Monstre(string nom);
		~Monstre();
		Sprite getSprite();
	    void setPosition(int,int);
	    void setMort();
	    bool estVivant();
	    int doAction();
	    
	    
	private:
		Texture t_vivant;
		Texture t_mort;
		bool vivant;

		
};


#endif
