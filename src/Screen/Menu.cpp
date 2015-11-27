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
	
	// Chargement de l'arrière plan
	texture;
	if (!texture.loadFromFile("res/blue_grass.png", sf::IntRect(0, 272, 1024, 480)))
		std::cout << "Impossible de charger le fichier \"blue_grass.png\"" << std::endl;
	texture.setRepeated(true);
	// chargement de la texture dans un sprite
	background.setTexture(texture);
	background.setTextureRect({ 0, 0, 1280, 480 });//la texture se répète dans un bloc de 1280*480
	
	if(!font.loadFromFile("res/Smart_Kid.otf"))
		std::cout << "Impossible de charger le fichier \"Smart_Kid.otf\"" << std::endl;
	play.setString("PRESS SPACE TO PLAY");
	play.setFont(font);
	sf::Color color(128, 128, 128);
	play.setColor(color);
	play.setPosition(190,240);
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
	window.draw(background);
	window.draw(play);
}
