/*!
* \file Entite.hpp
* \brief Fichier contenant la déclaration de la classe Entite
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef ENTITE_H
#define ENTITE_H

#include <SFML/Graphics.hpp>
#include "../Screen/ScreenState.hpp"
#include "ActionBonus.hpp"
#include "BonusVie.hpp"
#include "BonusChamp.hpp"

using namespace std;
using namespace sf;

/*!
* \class Entite
* \brief classe qui définit le type Entite
*/
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
		Sprite sprite;//!< le sprite de l'entité
		ActionBonus* action;//!< l'action bonus
		
};


#endif
