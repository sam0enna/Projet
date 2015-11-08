#ifndef DECORATOR_H
#define DECORATOR_H

#include <SFML/Graphics.hpp>
#include "Bloc.hpp"

class Decorator {
	
	protected :
		Bloc* bloc;
		
	public :
		Decorator(Bloc*,sf::Texture&);
		~Decorator();
		virtual void setCassable();
};

#endif
