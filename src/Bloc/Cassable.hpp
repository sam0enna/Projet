#ifndef CASSABLE_H
#define CASSABLE_H

#include "Decorator.hpp"
#include "Bloc.hpp"

class Cassable : public Decorator {
		
	public :
		Cassable(Bloc*,sf::Texture&);
		~Cassable();
		void setCassable();
};

#endif
