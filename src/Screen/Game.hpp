/*!
* \file Game.hpp
* \brief Fichier contenant la déclaration de la classe Game
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "ScreenState.hpp"
#include "TileMap.hpp"
#include "../Entite/Joueur.hpp"
#include "../Entite/Entite.hpp"
#include "../Entite/Champignon.hpp"
#include "../Entite/Etoile.hpp"
#include "../Entite/Monstre.hpp"
#include "../Bloc/Neutre.hpp"
#include "../Bloc/Cassable.hpp"
#include "../Bloc/Exit.hpp"

/*!
* \class Game
* \brief classe qui définit l'écran de jeu Game
*/
class Game : public ScreenState 
{
	public :
		Game();
		~Game();
		void load();
		void unload();
		void draw(RenderWindow &window);
		void move(int x,int y);
		Joueur* getJoueur();
		void haut();
		bool estFini();
		bool perdu();
		
	private :
		TileMap map;//!< le niveau
		Texture texture; //!< la texture de l'arrière plan
		Sprite background;//!< l'arrière plan
		Joueur* perso;//!< le joueur
		vector<Bloc*> blocs;//!< les blocs du niveau
		vector<Entite*> entites;//!< les entites du niveau

};
#endif //GAME_H
