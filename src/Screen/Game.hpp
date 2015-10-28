#ifndef GAME_H
#define GAME_H
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "ScreenState.hpp"
#include "TileMap.hpp"

class Game : public ScreenState 
{
	public :
		Game();
		~Game();
		void load();
		void unload();
		void draw(RenderWindow &window);
		
	private :
		TileMap map;
		Texture texture;
		Sprite background;

};
#endif //GAME_H
