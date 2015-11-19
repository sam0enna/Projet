#include "BonusVie.hpp"

BonusVie::BonusVie(){}

BonusVie::~BonusVie(){}

void BonusVie::action(Joueur* j){
	j->viePlus();
}
