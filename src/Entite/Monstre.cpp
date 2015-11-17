#include "Monstre.hpp"

Monstre::Monstre(string nom){
	vivant.loadFromFile(nom+"_alive.png");
	mort.loadFromFile(nom+"_dead.png");	
	sprite.setTexture(vivant); 
}

Monstre::~Monstre(){}

void Monstre::draw(RenderWindow& window){}

void Monstre::estMort(){
	sprite.setTexture(mort);
}
