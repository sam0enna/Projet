#include "Cassable.hpp"

Cassable::Cassable(Bloc* bloc):Decorator(bloc){
	texture.loadFromFile("res/box_cassable.png");
	bloc->getSprite()->setTexture(texture);
}

void Cassable::setCassable(){
	bloc->setCassable(true);
}
