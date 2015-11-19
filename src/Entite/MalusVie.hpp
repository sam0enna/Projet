#ifndef MALUSVIE_H
#define MALUSVIE_H

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class MalusVie : public ActionBonus{
			
	public:
		MalusVie();
		~MalusVie();
		void action(Joueur*);
		
};


#endif
