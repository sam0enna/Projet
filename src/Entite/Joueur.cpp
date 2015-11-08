#include "Joueur.hpp"
using namespace std;
using namespace sf;

Joueur::Joueur()
{
    stop.loadFromFile("res/Green/alienGreen_front.png");
    marche1.loadFromFile("res/Green/alienGreen_walk1.png");
    marche2.loadFromFile("res/Green/alienGreen_walk2.png");
    sprite.setTexture(stop);
    sprite.setOrigin(0,256);//coin inférieur gauche.
    sprite.scale(0.25f,0.25f);
    animation = JOUEUR_STOP;
}

Joueur::~Joueur() 
{
}

void Joueur::setPosition(int x,int y)
{
	sprite.setPosition(x,y);	
}

void Joueur::move(int x, int y)
{
	if(x>0){
		switch(animation)
		{
			case JOUEUR_MARCHE_1:
				sprite.setTexture(marche2);
				animation = JOUEUR_MARCHE_2;
				break;
			
			case JOUEUR_MARCHE_2:
				sprite.setTexture(marche1);
				animation = JOUEUR_MARCHE_1;
				break;
				
			default:
				sprite.setTexture(marche1);
				animation = JOUEUR_MARCHE_1;
		}	
	}
	
	sprite.move(x,y);
}

void Joueur::draw(RenderWindow &window)
{
	window.draw(sprite);
}

void Joueur::anim_stop(RenderWindow &window)
{	
    sprite.setTexture(stop);
    animation = JOUEUR_STOP;
    window.draw(sprite);
}

void Joueur::collision(vector<Bloc*>* blocs)
{
	vector<Bloc*>::iterator it = blocs->begin();
	while(it != blocs->end())
	{
		if((*it)->getSprite()->getGlobalBounds().intersects(sprite.getGlobalBounds()) && (*it)->estCassable())
		{	
			Bloc* b = *it;	
			it = blocs->erase(it);
			delete b;
		}
		else
			++it;
	}
}
