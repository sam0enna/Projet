/*!
* \file Fin.cpp
* \brief Fichier contenant l'implémentation de la classe Fin
* \author Samia Ennaji
* \date 27.11.2015
*/

#include "Fin.hpp"

//--------------------------------------------------
/*!
* \brief Constructeur
*/
Fin::Fin(bool victoire)
{
	type = FIN;
	victoire_ = victoire;
}

//--------------------------------------------------
/*!
* \brief Destructeur
*/
Fin::~Fin()
{
	unload();
}

//--------------------------------------------------
/*!
* \brief Méthode qui charge les composants
*/
void Fin::load()
{
	if(!font.loadFromFile("res/Smart_Kid.otf"))
		std::cout << "Impossible de charger le fichier \"Smart_Kid.otf\"" << std::endl;
	if(victoire_){
		cout<<"victoire"<<endl;
		play.setString("YOU WIN");
	}
	else
		play.setString("GAME OVER");
	play.setFont(font);
	play.setColor(Color::White);
	play.setPosition(320,240);
}

//--------------------------------------------------
/*!
* \brief Méthode qui décharge les composants
*/
void Fin::unload()
{
}

//--------------------------------------------------
/*!
* \brief Méthode qui gère les déplacements gauche droite
*/
void Fin::move(int x,int y){}

//--------------------------------------------------
/*!
* \brief Méthode qui gère les déplacements haut
*/
void Fin::haut(){}

//--------------------------------------------------
/*!
* \brief Méthode qui affiche les composants
*/
void Fin::draw(RenderWindow &window)
{
	window.draw(play);
}
