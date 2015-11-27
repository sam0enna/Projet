/*!
* \file Champignon.cpp
* \brief Fichier contenant l'implémentation de la classe Champignon
* \author Samia Ennaji
* \date 27.11.2015
*/

#include "Champignon.hpp"

//--------------------------------------------------
/*!
* \brief Constructeur
*/ 
Champignon::Champignon(){
	champ.loadFromFile("res/champignon.png");
	sprite.setTexture(champ);
	sprite.setOrigin(0,128);
	sprite.scale(0.3f,0.3f);
	action = new BonusChamp();
}

//--------------------------------------------------
/*!
* \brief Destructeur
*/
Champignon::~Champignon(){}

//--------------------------------------------------
/*!
* \brief action du champignon
*/
int Champignon::doAction(){
	return action->doAction();
}
