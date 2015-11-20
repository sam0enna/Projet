#ifndef MALUSVIE_H
#define MALUSVIE_H

#include <SFML/Graphics.hpp>
#include "ActionBonus.hpp"

using namespace std;
using namespace sf;

class MalusVie : public ActionBonus{
			
	public:
		MalusVie();
		~MalusVie();
		int doAction();
		
};


#endif
