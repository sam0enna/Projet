/*!
* \file MalusVie.hpp
* \brief Fichier contenant la déclaration de la classe MalusVie
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef MALUSVIE_H
#define MALUSVIE_H

#include <SFML/Graphics.hpp>
#include "ActionBonus.hpp"

using namespace std;
using namespace sf;

/*!
* \class MalusVie
* \brief classe qui définit le type MalusVie
*/
class MalusVie : public ActionBonus{
			
	public:
		MalusVie();
		~MalusVie();
		int doAction();
		
};


#endif
