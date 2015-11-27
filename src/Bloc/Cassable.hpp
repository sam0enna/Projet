/*!
* \file Cassable.hpp
* \brief Fichier contenant la déclaration de la classe Cassable
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef CASSABLE_H
#define CASSABLE_H

#include "Decorator.hpp"
#include "Bloc.hpp"

/*!
* \class Cassable
* \brief classe qui hérite de Decorator et définit la propriété cassable d'un bloc
*/
class Cassable : public Decorator {
		
	public :
		Cassable(Bloc*);
		~Cassable();
		void setCassable();
};

#endif
