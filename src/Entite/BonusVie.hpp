/*!
* \file BonusVie.hpp
* \brief Fichier contenant la déclaration de la classe BonusVie
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef BONUSVIE_H
#define BONUSVIE_H

#include <SFML/Graphics.hpp>
#include "ActionBonus.hpp"
using namespace std;
using namespace sf;

/*!
* \class BonusVie
* \brief classe qui définit le type BonusVie
*/
class BonusVie : public ActionBonus{
			
	public:
		BonusVie();
		~BonusVie();
		int doAction();
		
};


#endif
