#include "Decorator.hpp"

Decorator::Decorator(Bloc* bloc){
	this->bloc = bloc;
}

Decorator::~Decorator(){}

void Decorator::setCassable(){}
