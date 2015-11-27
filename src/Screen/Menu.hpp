/*!
* \file Menu.hpp
* \brief Fichier contenant la déclaration de la classe Menu
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef MENU_H
#define MENU_H
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "ScreenState.hpp"

/*!
* \class Menu
* \brief classe qui définit l'écran de jeu Menu
*/
class Menu : public ScreenState 
{
	public :
		Menu();
		~Menu();
		void load();
		void unload();
		void move(int x,int y);
		void haut();
		void draw(RenderWindow &window);
		
	private :
		sf::Font font;//!< police utilisé
		sf::Text play;//!< le texte à afficher
		Texture texture; //!< la texture de l'arrière plan
		Sprite background;//!< l'arrière plan

};
#endif //MENU_H
