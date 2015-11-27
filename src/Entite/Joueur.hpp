/*!
* \file Joueur.hpp
* \brief Fichier contenant la déclaration de la classe Joueur
* \author Samia Ennaji
* \date 27.11.2015
*/

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "Etoile.hpp"
#include "Champignon.hpp"
#include "Monstre.hpp"
#include "../Bloc/Bloc.hpp"
#include "../Bloc/Decorator.hpp"
#include "../Bloc/Exit.hpp"
 
#define JOUEUR_STOP 0
#define JOUEUR_MARCHE_1 1
#define JOUEUR_MARCHE_2 2
 
using namespace std;
using namespace sf;
 
/*!
* \class Joueur
* \brief classe qui définit le type Joueur
*/
class Joueur
{
    public :
 
    Joueur();
    ~Joueur();
    
    void setPosition(int x, int y);
    Vector2f getPosition();
    void move(int x,int y);
    void draw(RenderWindow &window);
    void anim_stop(RenderWindow &window);
    void collisionBloc(vector<Bloc*>* blocs);
    void collisionEntites(vector<Entite*>* entites);
    int getVie();
    void vieMoins();
    void viePlus();
    void modifierVie(int i);
    void jump();
    bool onGround();
    void update();
    bool estMort();
    bool estVictorieux();
    
    private :
		Texture stop; //!< texture du personnage à l'arrêt
		Texture marche1;//!< texture de marche
		Texture marche2;//!<texture de marche
		int animation;//!< Etat du joueur
		int vie;//!< vie du joueur
		Sprite sprite;//!< sprite du joueur
		Vector2f velocity;//!< vélocité du joueur
		const float gravity = 1.0f;//!< gravité 
		bool gauche;//!< test si déplacement à gauche possible
		bool droite;//!< test si déplacement à droite possible
		bool victoire_;//!< paramètre de victoire
 
};
