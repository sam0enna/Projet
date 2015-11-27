/*!
* \file Monstre.hpp
* \brief Fichier contenant la déclaration de la classe Monstre
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef MONSTRE_H
#define MONSTRE_H

#include <SFML/Graphics.hpp>
#include "../Screen/ScreenState.hpp"
#include "Entite.hpp"
#include "ActionBonus.hpp"
#include "MalusVie.hpp"
#include "VieNeutre.hpp"

using namespace std;
using namespace sf;

/*!
* \class Monstre
* \brief classe qui définit le type Monstre
*/
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
		Texture t_vivant;//!< texture du monstre vivant
		Texture t_mort;//!< texture du monstre mort
		bool vivant;//!< état du monstre

		
};


#endif
