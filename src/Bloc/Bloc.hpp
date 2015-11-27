/*!
* \file Bloc.hpp
* \brief Fichier contenant la déclaration de la classe Bloc
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef BLOC_H
#define BLOC_H

#include <SFML/Graphics.hpp>
using namespace sf;

/*!
* \class Bloc
* \brief classe qui définit le type Bloc
*/
class Bloc
{
	private: 
		Sprite* sprite;//!< le sprite du bloc
		bool cassable;//!< détermine si le bloc est cassable ou non
		bool victoire;//!< détermine si le bloc met fin à la partie
	
	public:
		Bloc (int x, int y);
		~Bloc();
		bool estCassable();
		void setCassable(bool);
		void display(RenderWindow& window);
		Sprite* getSprite();
		Vector2f getPosition();
		void setVictoire(bool);
		bool estVictorieux();
		
};

#endif
