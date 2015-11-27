/*!
* \file Monstre.cpp
* \brief Fichier contenant l'implémentation de la classe Monstre
* \author Samia Ennaji
* \date 27.11.2015
*/

#include "Monstre.hpp"

//--------------------------------------------------
/*!
* \brief Constructeur
* \param nom le nomdu monstre
*/
Monstre::Monstre(string nom){
	t_vivant.loadFromFile("res/Ennemis/"+nom+".png");
	t_mort.loadFromFile("res/Ennemis/"+nom+"_dead.png");	
	sprite.setTexture(t_vivant); 
	sprite.setOrigin(0,128);
	sprite.scale(0.35f,0.35f);	
	vivant = true;
	action = new MalusVie();
}

//--------------------------------------------------
/*!
* \brief Destructeur
*/
Monstre::~Monstre(){}

//--------------------------------------------------
/*!
* \brief Méthode qui modifie l'état du monstre
*/
void Monstre::setMort(){
	sprite.setTexture(t_mort);
	vivant = false;
	delete action;
	action = new VieNeutre();
}

//--------------------------------------------------
/*!
* \brief Méthode qui retourne la valeur de l'attribut vivant
*/
bool Monstre::estVivant(){
	return vivant;
}

//--------------------------------------------------
/*!
* \brief action de l'étoile
*/
int Monstre::doAction(){
	return action->doAction();
}
