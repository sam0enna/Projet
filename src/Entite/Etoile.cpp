#include "Etoile.hpp"

Etoile::Etoile(){
	star.loadFromFile("res/star.png");
	sprite.setTexture(star);
	sprite.setOrigin(0,128);
	sprite.scale(0.25f,0.25f);
	action = new BonusVie();
}

Etoile::~Etoile(){}

int Etoile::doAction(){
	return action->doAction();
}
