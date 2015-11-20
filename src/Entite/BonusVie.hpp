#ifndef BONUSVIE_H
#define BONUSVIE_H

#include <SFML/Graphics.hpp>
#include "ActionBonus.hpp"
using namespace std;
using namespace sf;

class BonusVie : public ActionBonus{
			
	public:
		BonusVie();
		~BonusVie();
		int doAction();
		
};


#endif
