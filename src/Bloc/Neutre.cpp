#include "Neutre.hpp"

Neutre::Neutre(Bloc* bloc):Decorator(bloc){
}

void Neutre::setCassable(){
	bloc->setCassable(false);
}
