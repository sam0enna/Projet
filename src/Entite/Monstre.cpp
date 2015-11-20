#include "Monstre.hpp"

Monstre::Monstre(string nom){
	t_vivant.loadFromFile("res/Ennemis/"+nom+".png");
	t_mort.loadFromFile("res/Ennemis/"+nom+"_dead.png");	
	sprite.setTexture(t_vivant); 
	sprite.setOrigin(0,128);
	sprite.scale(0.25f,0.25f);	
	vivant = true;
	action = new MalusVie();
}

Monstre::~Monstre(){}

void Monstre::setMort(){
	sprite.setTexture(t_mort);
	vivant = false;
}

bool Monstre::estVivant(){
	return vivant;
}

int Monstre::doAction(){
	int effet;
	if(estVivant())
		effet = action->doAction();
	else
		effet = 0;
	return effet;
}
