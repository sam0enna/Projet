#ifndef ETOILE_H
#define ETOILE_H

#include <SFML/Graphics.hpp>
#include "../Screen/ScreenState.hpp"
#include "Entite.hpp"

using namespace std;
using namespace sf;

class Etoile : public Entite{
			
	public:
		Etoile();
		~Etoile();
		int doAction();
	    
	protected:
		Texture star;
		
};


#endif
