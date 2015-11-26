#include "Exit.hpp"

Exit::Exit(Bloc* bloc):Decorator(bloc){
	texture.loadFromFile("res/exit.png");
	bloc->getSprite()->setTexture(texture);
	bloc->setVictoire(true);
}

void Exit::setCassable(){
	bloc->setCassable(false);
}
