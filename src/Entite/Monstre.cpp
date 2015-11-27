#include "Monstre.hpp"

Monstre::Monstre(string nom){
	t_vivant.loadFromFile("res/Ennemis/"+nom+".png");
	t_mort.loadFromFile("res/Ennemis/"+nom+"_dead.png");	
	sprite.setTexture(t_vivant); 
	sprite.setOrigin(0,128);
	sprite.scale(0.35f,0.35f);	
	vivant = true;
	action = new MalusVie();
}

Monstre::~Monstre(){}

void Monstre::setMort(){
	sprite.setTexture(t_mort);
	vivant = false;
	delete action;
	action = new VieNeutre();
}

bool Monstre::estVivant(){
	return vivant;
}

int Monstre::doAction(){
	return action->doAction();
}
