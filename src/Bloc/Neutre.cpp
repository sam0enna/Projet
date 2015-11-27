/*!
* \file Neutre.cpp
* \brief Fichier contenant l'implémentation de la classe Neutre
* \author Samia Ennaji
* \date 27.11.2015
*/

#include "Neutre.hpp"

//--------------------------------------------------
/*!
* \brief Constructeur
* \param bloc le bloc à décorer
*/
Neutre::Neutre(Bloc* bloc):Decorator(bloc){
	texture.loadFromFile("res/box_neutre.png");
	bloc->getSprite()->setTexture(texture);
	bloc->setVictoire(false);
}

//--------------------------------------------------
/*!
* \brief Méthode qui modifie l'attribut Bloc.cassable
*/
void Neutre::setCassable(){
	bloc->setCassable(false);
}

