/*!
* \file Decorator.cpp
* \brief Fichier contenant l'implémentation de la classe Decorator
* \author Samia Ennaji
* \date 27.11.2015
*/

#include "Decorator.hpp"

//--------------------------------------------------
/*!
* \brief Constructeur
* \param bloc le bloc à décorer
*/
Decorator::Decorator(Bloc* bloc){
	this->bloc = bloc;
}

//--------------------------------------------------
/*!
* \brief Destructeur
*/
Decorator::~Decorator(){}

//--------------------------------------------------
/*!
* \brief Méthode qui modifie l'attribut Bloc.cassable
*/
void Decorator::setCassable(){}
