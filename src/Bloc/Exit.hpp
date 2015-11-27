/*!
* \file Exit.hpp
* \brief Fichier contenant la déclaration de la classe Exit
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef EXIT_H
#define EXIT_H

#include "Decorator.hpp"
#include "Bloc.hpp"

/*!
* \class Exit
* \brief classe qui hérite de Decorator et définit la propriété exit d'un bloc
*/
class Exit : public Decorator {
		
	public :
		Exit(Bloc*);
		~Exit();
		void setCassable();
};

#endif
