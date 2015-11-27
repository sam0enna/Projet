#include "Champignon.hpp"

Champignon::Champignon(){
	champ.loadFromFile("res/champignon.png");
	sprite.setTexture(champ);
	sprite.setOrigin(0,128);
	sprite.scale(0.3f,0.3f);
	action = new BonusChamp();
}

Champignon::~Champignon(){}

int Champignon::doAction(){
	return action->doAction();
}
