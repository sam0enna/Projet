#include "Exit.hpp"

Exit::Exit(Bloc* bloc):Decorator(bloc){
	texture.loadFromFile("res/exit.png");
	bloc->getSprite()->setTexture(texture);
}

void Exit::setCassable(){
	bloc->setCassable(false);
}
