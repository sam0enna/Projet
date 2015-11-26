#ifndef VIENEUTRE_H
#define VIENEUTRE_H

#include <SFML/Graphics.hpp>
#include "ActionBonus.hpp"

using namespace std;
using namespace sf;

class VieNeutre : public ActionBonus{
			
	public:
		VieNeutre();
		~VieNeutre();
		int doAction();
		
};


#endif
