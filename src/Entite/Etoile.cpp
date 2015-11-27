/*!
* \file Etoile.cpp
* \brief Fichier contenant l'implémentation de la classe Etoile
* \author Samia Ennaji
* \date 27.11.2015
*/

#include "Etoile.hpp"

//--------------------------------------------------
/*!
* \brief Constructeur
*/
Etoile::Etoile(){
	star.loadFromFile("res/star.png");
	sprite.setTexture(star);
	sprite.setOrigin(0,128);
	sprite.scale(0.25f,0.25f);
	action = new BonusVie();
}

//--------------------------------------------------
/*!
* \brief Destructeur
*/
Etoile::~Etoile(){}

//--------------------------------------------------
/*!
* \brief action de l'étoile
*/
int Etoile::doAction(){
	return action->doAction();
}
