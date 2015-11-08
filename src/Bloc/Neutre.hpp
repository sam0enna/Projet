#ifndef Neutre_H
#define Neutre_H

#include "Decorator.hpp"
#include "Bloc.hpp"

class Neutre : public Decorator {
		
	public :
		Neutre(Bloc*,sf::Texture& texture);
		~Neutre();
		void setCassable();
};

#endif
