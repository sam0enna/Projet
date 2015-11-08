#include "Decorator.hpp"

Decorator::Decorator(Bloc* bloc,sf::Texture& texture){
	this->bloc = bloc;
	this->bloc->getSprite()->setTexture(texture);
}

Decorator::~Decorator(){}

void Decorator::setCassable(){}
