#ifndef BOUSCHAMP_H
#define BOUSCHAMP_H

#include <SFML/Graphics.hpp>
#include "ActionBonus.hpp"

using namespace std;
using namespace sf;

class BonusChamp : public ActionBonus{
			
	public:
		BonusChamp();
		~BonusChamp();
		int doAction();
		
};


#endif
