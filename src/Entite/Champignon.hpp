/*!
* \file Champignon.hpp
* \brief Fichier contenant la déclaration de la classe Champignon
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef CHAMP_H
#define CHAMP_H

#include <SFML/Graphics.hpp>
#include "../Screen/ScreenState.hpp"
#include "Entite.hpp"

using namespace std;
using namespace sf;

/*!
* \class Champignon
* \brief classe qui définit le type Champignon
*/
class Champignon : public Entite{
			
	public:
		Champignon();
		~Champignon();
		int doAction();
	    
	protected:
		Texture champ;//!< texture du champignon
		
};


#endif
