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
#include "../Entite/Etoile.hpp"
#include "../Entite/Monstre.hpp"
#include "../Bloc/Neutre.hpp"
#include "../Bloc/Cassable.hpp"
#include "../Bloc/Exit.hpp"

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
		TileMap map;
		Texture texture;
		Texture neutre;
		Texture cassable;
		Sprite background;
		Joueur* perso;
		vector<Bloc*> blocs;
		vector<Entite*> entites;

};
#endif //GAME_H
