#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "ScreenState.hpp"
#include "TileMap.hpp"
#include "../Entite/Entite.hpp"
#include "../Entite/Etoile.hpp"
#include "../Entite/Joueur.hpp"
#include "../Bloc/Neutre.hpp"
#include "../Bloc/Cassable.hpp"

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
