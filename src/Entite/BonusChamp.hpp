/*!
* \file BonusChamp.hpp
* \brief Fichier contenant la déclaration de la classe BonusChamp
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef BOUSCHAMP_H
#define BOUSCHAMP_H

#include <SFML/Graphics.hpp>
#include "ActionBonus.hpp"

using namespace std;
using namespace sf;

/*!
* \class BonusChamp
* \brief classe qui définit le type BonusChamp
*/
class BonusChamp : public ActionBonus{
			
	public:
		BonusChamp();
		~BonusChamp();
		int doAction();
		
};


#endif
