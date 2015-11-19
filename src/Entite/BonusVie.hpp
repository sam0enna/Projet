#ifndef BONUSVIE_H
#define BONUSVIE_H

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class BonusVie : public ActionBonus{
			
	public:
		BonusVie();
		~BonusVie();
		void doAction(Joueur*);
		
};


#endif
