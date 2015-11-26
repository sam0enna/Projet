#ifndef CASSABLE_H
#define CASSABLE_H

#include "Decorator.hpp"
#include "Bloc.hpp"

class Cassable : public Decorator {
		
	public :
		Cassable(Bloc*);
		~Cassable();
		void setCassable();
};

#endif
