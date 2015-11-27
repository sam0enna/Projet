/*!
* \file Neutre.hpp
* \brief Fichier contenant la déclaration de la classe Neutre
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef Neutre_H
#define Neutre_H

#include "Decorator.hpp"
#include "Bloc.hpp"

/*!
* \class Neutre
* \brief classe qui hérite de Decorator et définit la propriété neutre d'un bloc
*/
class Neutre : public Decorator {
		
	public :
		Neutre(Bloc*);
		~Neutre();
		void setCassable();
};

#endif
