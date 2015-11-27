/*!
* \file Exit.cpp
* \brief Fichier contenant l'implémentation de la classe Exit
* \author Samia Ennaji
* \date 27.11.2015
*/

#include "Exit.hpp"

//--------------------------------------------------
/*!
* \brief Constructeur
* \param bloc le bloc à décorer
*/
Exit::Exit(Bloc* bloc):Decorator(bloc){
	texture.loadFromFile("res/exit.png");
	bloc->getSprite()->setTexture(texture);
	bloc->setVictoire(true);
}

//--------------------------------------------------
/*!
* \brief Méthode qui modifie l'attribut Bloc.cassable
*/
void Exit::setCassable(){
	bloc->setCassable(false);
}
