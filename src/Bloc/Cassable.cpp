/*!
* \file Cassable.cpp
* \brief Fichier contenant l'implémentation de la classe Cassable
* \author Samia Ennaji
* \date 27.11.2015
*/

#include "Cassable.hpp"

//--------------------------------------------------
/*!
* \brief Constructeur
* \param bloc le bloc à décorer
*/
Cassable::Cassable(Bloc* bloc):Decorator(bloc){
	texture.loadFromFile("res/box_cassable.png");
	bloc->getSprite()->setTexture(texture);
	bloc->setVictoire(false);
}

//--------------------------------------------------
/*!
* \brief Méthode qui modifie l'attribut Bloc.cassable
*/
void Cassable::setCassable(){
	bloc->setCassable(true);
}
