/*!
* \file Etoile.hpp
* \brief Fichier contenant la déclaration de la classe Etoile
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef ETOILE_H
#define ETOILE_H

#include <SFML/Graphics.hpp>
#include "../Screen/ScreenState.hpp"
#include "Entite.hpp"

using namespace std;
using namespace sf;

/*!
* \class Etoile
* \brief classe qui définit le type Etoile
*/
class Etoile : public Entite{
			
	public:
		Etoile();
		~Etoile();
		int doAction();
	    
	protected:
		Texture star;//!< texture de l'étoile
		
};


#endif
