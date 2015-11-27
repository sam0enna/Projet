/*!
* \file Decorator.hpp
* \brief Fichier contenant la déclaration de la classe Decorator
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef DECORATOR_H
#define DECORATOR_H

#include <SFML/Graphics.hpp>
#include "Bloc.hpp"

/*!
* \class Decorator
* \brief classe qui définit le type Decorator
*/
class Decorator {
	
	protected :
		Bloc* bloc;//!< le bloc décoré
		
	public :
		Decorator(Bloc*);
		~Decorator();
		virtual void setCassable();
		Texture texture;//!< la texture du bloc
};

#endif
