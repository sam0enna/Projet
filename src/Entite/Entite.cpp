#include "Entite.hpp"

Entite::Entite(){}

Entite::~Entite(){}

Sprite Entite::getSprite()
{
	return sprite;
}

void Entite::draw(RenderWindow& window){
	window.draw(sprite);	
}

void Entite::setPosition(int x,int y){
	sprite.setPosition(x,y);	
}

int Entite::doAction(){}
