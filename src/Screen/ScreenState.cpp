/*!
* \file ScreenState.cpp
* \brief Fichier contenant l'implémentation de la classe ScreenState
* \author Samia Ennaji
* \date 27.11.2015
*/

#include "ScreenState.hpp"

//--------------------------------------------------
/*!
* \brief Constructeur
*/
ScreenState::ScreenState()
{
}

//--------------------------------------------------
/*!
* \brief Destructeur
*/
ScreenState::~ScreenState()
{	
}

//--------------------------------------------------
/*!
* \brief Méthode qui retourne le type
*/
int ScreenState::getType()
{
	return type;
}

//--------------------------------------------------
/*!
* \brief Méthode qui charge les composants de l'écran
*/
void ScreenState::load(){}

//--------------------------------------------------
/*!
* \brief Méthode qui décharge les composants de l'écran
*/
void ScreenState::unload(){}

//--------------------------------------------------
/*!
* \brief Méthode qui gère les déplacements gauche droite
*/
void ScreenState::move(int x,int y){}

//--------------------------------------------------
/*!
* \brief Méthode qui gère les déplacements haut
*/
void ScreenState::haut(){}

//--------------------------------------------------
/*!
* \brief Méthode qui affiche les composants de l'écran
*/
void ScreenState::draw(RenderWindow &window){}
