#include "Neutre.hpp"

Neutre::Neutre(Bloc* bloc):Decorator(bloc){
	texture.loadFromFile("res/box_neutre.png");
	bloc->getSprite()->setTexture(texture);
	bloc->setVictoire(false);
}

void Neutre::setCassable(){
	bloc->setCassable(false);
}

