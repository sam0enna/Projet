/*!
* \file Fin.hpp
* \brief Fichier contenant la déclaration de la classe Fin
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef FIN_H
#define FIN_H
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "ScreenState.hpp"

/*!
* \class Fin
* \brief classe qui définit l'écran de jeu Fin
*/
class Fin : public ScreenState 
{
	public :
		Fin(bool);
		~Fin();
		void load();
		void unload();
		void move(int x,int y);
		void haut();
		void draw(RenderWindow &window);
		
	private :
		bool victoire_;//!< la condition de victoire
		sf::Font font;//!< la police
		sf::Text play;//!< le texte à afficher

};
#endif //FIN_H
