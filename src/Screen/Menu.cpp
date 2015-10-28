#include "Menu.hpp"

Menu::Menu()
{
	type = MENU;
}

Menu::~Menu()
{
	unload();
}

void Menu::load()
{
	if(!font.loadFromFile("res/Smart_Kid.otf"))
		std::cout << "Impossible de charger le fichier \"Smart_Kid.otf\"" << std::endl;
	play.setString("PRESS SPACE TO PLAY");
	play.setFont(font);
	play.setColor(Color::White);
}

void Menu::unload()
{
	
}

void Menu::draw(RenderWindow &window)
{
	window.draw(play);
}
