/*!
* \file Menu.cpp
* \brief Fichier contenant l'implémentation de la classe Menu
* \author Samia Ennaji
* \date 27.11.2015
*/

#include "Menu.hpp"

//--------------------------------------------------
/*!
* \brief Constructeur
*/
Menu::Menu()
{
	type = MENU;
}

//--------------------------------------------------
/*!
* \brief Destructeur
*/
Menu::~Menu()
{
	unload();
}

//--------------------------------------------------
/*!
* \brief Méthode qui charge les composants
*/
void Menu::load()
{
	if(!font.loadFromFile("res/Smart_Kid.otf"))
		std::cout << "Impossible de charger le fichier \"Smart_Kid.otf\"" << std::endl;
	play.setString("PRESS SPACE TO PLAY");
	play.setFont(font);
	play.setColor(Color::White);
}

//--------------------------------------------------
/*!
* \brief Méthode qui décharge les composants
*/
void Menu::unload()
{
}

//--------------------------------------------------
/*!
* \brief Méthode qui gère les déplacements gauche droite dans le menu
*/
void Menu::move(int x,int y){}

//--------------------------------------------------
/*!
* \brief Méthode qui gère les déplacements haut dans le menu
*/
void Menu::haut(){}

//--------------------------------------------------
/*!
* \brief Méthode qui affiche les composants
*/
void Menu::draw(RenderWindow &window)
{
	window.draw(play);
}
