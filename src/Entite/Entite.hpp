#ifndef ENTITE_H
#define ENTITE_H

#include <SFML/Graphics.hpp>

class Entite : public Sprite
{
			
	public:
		Entite();
		~Entite();
	    virtual bool collision(Entite& entite);
	    virtual ScreenState* update() ;
		
}


#endif
