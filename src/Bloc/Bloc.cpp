/*!
* \file Bloc.cpp
* \brief Fichier contenant l'implémentation de la classe Bloc
* \author Samia Ennaji
* \date 27.11.2015
*/

#include "Bloc.hpp"

//--------------------------------------------------
/*!
* \brief Constructeur
* \param x la coordonnée x du bloc
* \param y la coordonnée y du bloc
*/
Bloc::Bloc(int x, int y){
	sprite = new Sprite();
	sprite->scale(0.32f,0.32f);
	sprite->setOrigin(0,128);
	sprite->setPosition( x, y);
}

//--------------------------------------------------
/*!
* \brief Destructeur
*/
Bloc::~Bloc(){
	delete sprite;
}

//--------------------------------------------------
/*!
* \brief Méthode qui retourne le booléen cassable
*/
bool Bloc::estCassable(){
	return cassable;
}

//--------------------------------------------------
/*!
* \brief Méthode qui modifie la valeur de cassable
* \param casse la nouvelle valeur
*/
void Bloc::setCassable(bool casse){
	cassable = casse;
}
 
//--------------------------------------------------
/*!
* \brief Méthode qui affiche le bloc
* \param window la fenêtre
*/
void Bloc::display(RenderWindow& window){ //pour afficher un bloc 
	if(sprite != nullptr)
		window.draw(*sprite);
}

//--------------------------------------------------
/*!
* \brief Méthode qui retourne le sprite
*/
Sprite* Bloc::getSprite()
{
	return sprite;
}

//--------------------------------------------------
/*!
* \brief Méthode qui retourne la position du sprite
*/
Vector2f Bloc::getPosition(){
	return sprite->getPosition();
}

//--------------------------------------------------
/*!
* \brief Méthode qui modifie la valeur de victoire
*/
void Bloc::setVictoire(bool v){
	victoire = v;
}

//--------------------------------------------------
/*!
* \brief Méthode qui retourne la valeur de victoire
*/
bool Bloc::estVictorieux(){
	return victoire;
}
