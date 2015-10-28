#ifndef ENTITE_H
#define ENTITE_H

#include <SFML/Graphics.hpp>
#include "../Screen/ScreenState.hpp"

using namespace std;
using namespace sf;

class Entite
{
			
	public:
		Entite();
		~Entite();
	    virtual bool collision(Entite& entite);
	    virtual ScreenState* update() ;
	    
	protected:
		Sprite sprite;
		
};


#endif
