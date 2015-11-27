/*!
* \file ActionBonus.hpp
* \brief Fichier contenant la déclaration de la classe ActionBonus
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef ACTION_BONUS_H
#define ACTION_BONUS_H

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

/*!
* \class ActionBonus
* \brief classe qui définit le type ActionBonus
*/
class ActionBonus {
			
	public:
		ActionBonus();
		~ActionBonus();
		virtual int doAction();
		
};


#endif
