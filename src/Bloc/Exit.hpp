#ifndef EXIT_H
#define EXIT_H

#include "Decorator.hpp"
#include "Bloc.hpp"

class Exit : public Decorator {
		
	public :
		Exit(Bloc*);
		~Exit();
		void setCassable();
};

#endif
