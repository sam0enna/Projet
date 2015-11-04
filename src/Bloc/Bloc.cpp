#include "Bloc.hpp"

//constructeur
Bloc::Bloc(sf::Texture& texture,int x, int y){
	sprite = new Sprite();
	sprite->setTexture(texture);
	sprite->setPosition( x, y);
	sprite->scale(0.25f,0.25f);
	sprite->setOrigin(0,128);
}

Bloc::~Bloc(){
}

bool Bloc::estCassable(){
	return cassable;
}

void Bloc::setCassable(bool casse){
	cassable = casse;
}

Bloc* Bloc :: quandCasse(){ // lorsqu'une une entité essaye de casser un bloc
	delete sprite;
}
 
void Bloc ::display(RenderWindow& window){ //pour afficher un bloc 
	if(sprite != nullptr)
		window.draw(*sprite);
}
