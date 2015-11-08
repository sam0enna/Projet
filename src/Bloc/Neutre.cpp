#include "Neutre.hpp"

Neutre::Neutre(Bloc* bloc,sf::Texture& texture):Decorator(bloc,texture){
}

void Neutre::setCassable(){
	bloc->setCassable(false);
}
