#include "Bloc.hpp"

//constructeur
Bloc::Bloc(int x, int y){
	sprite = new Sprite();
	sprite->scale(0.32f,0.32f);
	sprite->setOrigin(0,128);
	sprite->setPosition( x, y);
}

Bloc::~Bloc(){
	delete sprite;
}

bool Bloc::estCassable(){
	return cassable;
}

void Bloc::setCassable(bool casse){
	cassable = casse;
}

Bloc* Bloc::quandCasse(){ // lorsqu'une une entité essaye de casser un bloc
	delete sprite;
}
 
void Bloc::display(RenderWindow& window){ //pour afficher un bloc 
	if(sprite != nullptr)
		window.draw(*sprite);
}

Sprite* Bloc::getSprite()
{
	return sprite;
}

Vector2f Bloc::getPosition(){
	return sprite->getPosition();
}

void Bloc::setVictoire(bool v){
	victoire = v;
}

bool Bloc::estVictorieux(){
	return victoire;
}
