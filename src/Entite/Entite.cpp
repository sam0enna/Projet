#include "Entite.hpp"

Entite::Entite(){}

Entite::~Entite(){}

bool Entite::collision(Entite& entite)
{
	return sprite.getGlobalBounds().intersect(entite.sprite.getGlobalBounds()); //on teste avec une réference
}

ScreenState* Entite::update(){}
