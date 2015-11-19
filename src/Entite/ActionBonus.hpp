#ifndef ACTION_BONUS_H
#define ACTION_BONUS_H

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class ActionBonus {
			
	public:
		ActionBonus();
		~ActionBonus();
		virtual void action(Joueur*);
		
};


#endif
