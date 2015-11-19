#include "BonusVie.hpp"

BonusVie::BonusVie(){}

BonusVie::~BonusVie(){}

void BonusVie::doAction(Joueur* j){
	j->viePlus();
}
