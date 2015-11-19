#include "Entite.hpp"

Entite::Entite(){}

Entite::~Entite(){}

Sprite Entite::getSprite()
{
	return sprite;
}

void Entite::draw(RenderWindow& window){}

void Entite::setPosition(int x,int y){
	sprite.setPosition(x,y);	
}

void Entite::doAction(Joueur* j){
	action->doAction(j);
}
