#include "Monstre.hpp"

Monstre::Monstre(string nom){
	vivant.loadFromFile("res/Ennemis/"+nom+".png");
	mort.loadFromFile("res/Ennemis/"+nom+"_dead.png");	
	sprite.setTexture(vivant); 
}

Monstre::~Monstre(){}

void Monstre::draw(RenderWindow& window){}

void Monstre::estMort(){
	sprite.setTexture(mort);
}
