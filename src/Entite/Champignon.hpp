#ifndef CHAMP_H
#define CHAMP_H

#include <SFML/Graphics.hpp>
#include "../Screen/ScreenState.hpp"
#include "Entite.hpp"

using namespace std;
using namespace sf;

class Champignon : public Entite{
			
	public:
		Champignon();
		~Champignon();
		int doAction();
	    
	protected:
		Texture champ;
		
};


#endif
