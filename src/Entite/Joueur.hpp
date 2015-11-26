#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "Etoile.hpp"
#include "../Bloc/Bloc.hpp"
 
#define JOUEUR_STOP 0
#define JOUEUR_MARCHE_1 1
#define JOUEUR_MARCHE_2 2
 
using namespace std;
using namespace sf;
 
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
    void collisionBloc(vector<Bloc*>* blocs,int x, int y);
    void collisionEntites(vector<Entite*>* entites);
    int getVie();
    void vieMoins();
    void viePlus();
    void modifierVie(int i);
    void jump();
    bool onGround();
    void update();
    bool estMort();
    
    private :
		Texture stop;
		Texture marche1;
		Texture marche2;
		int animation;
		int vie;
		Sprite sprite;
		Vector2f velocity;
		const float gravity = 1.0f;
		bool gauche;
		bool droite;
 
};
