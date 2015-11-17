#include "Etoile.hpp"

Etoile::Etoile(){
	star.loadFromFile("res/star.png");
	sprite.setTexture(star);
	sprite.setOrigin(0,128);
	sprite.scale(0.25f,0.25f);
}

Etoile::~Etoile(){}

void Etoile::draw(RenderWindow& window){
	window.draw(sprite);
}
