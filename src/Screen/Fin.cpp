#include "Fin.hpp"

Fin::Fin(bool victoire)
{
	type = FIN;
	victoire_ = victoire;
}

Fin::~Fin()
{
	unload();
}

void Fin::load()
{
	if(!font.loadFromFile("res/Smart_Kid.otf"))
		std::cout << "Impossible de charger le fichier \"Smart_Kid.otf\"" << std::endl;
	if(victoire_)
		play.setString("YOU WIN");
	else
		play.setString("GAME OVER");
	play.setFont(font);
	play.setColor(Color::White);
}

void Fin::unload()
{
	
}

void Fin::move(int x,int y){}

void Fin::draw(RenderWindow &window)
{
	window.draw(play);
}
