/*!
* \file Entite.cpp
* \brief Fichier contenant l'implémentation de la classe Entite
* \author Samia Ennaji
* \date 27.11.2015
*/

#include "Entite.hpp"

//--------------------------------------------------
/*!
* \brief Constructeur
*/
Entite::Entite(){}

//--------------------------------------------------
/*!
* \brief Destructeur
*/
Entite::~Entite(){}

//--------------------------------------------------
/*!
* \brief Methode qui retourne le sprite
*/
Sprite Entite::getSprite()
{
	return sprite;
}

//--------------------------------------------------
/*!
* \brief Méthode qui affiche l'entité
*/
void Entite::draw(RenderWindow& window){
	window.draw(sprite);	
}

//--------------------------------------------------
/*!
* \brief Méthode qui modifie la position de l'entité
*/
void Entite::setPosition(int x,int y){
	sprite.setPosition(x,y);	
}

//--------------------------------------------------
/*!
* \brief l'action de l'entité
*/
int Entite::doAction(){}
