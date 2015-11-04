#include "Cassable.hpp"

Cassable::Cassable(Bloc* bloc):Decorator(bloc){
}

void Cassable::setCassable(){
	bloc->setCassable(true);
}
