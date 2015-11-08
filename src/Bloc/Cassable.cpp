#include "Cassable.hpp"

Cassable::Cassable(Bloc* bloc,sf::Texture& texture):Decorator(bloc,texture){
}

void Cassable::setCassable(){
	bloc->setCassable(true);
}
