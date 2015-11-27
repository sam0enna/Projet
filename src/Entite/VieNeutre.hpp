/*!
* \file VieNeutre.hpp
* \brief Fichier contenant la déclaration de la classe VieNeutre
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef VIENEUTRE_H
#define VIENEUTRE_H

#include <SFML/Graphics.hpp>
#include "ActionBonus.hpp"

using namespace std;
using namespace sf;

/*!
* \class VieNeutre
* \brief classe qui définit le type VieNeutre
*/
class VieNeutre : public ActionBonus{
			
	public:
		VieNeutre();
		~VieNeutre();
		int doAction();
		
};


#endif
