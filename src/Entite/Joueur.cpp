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
    vie = 3;
}

Joueur::~Joueur() 
{
}

void Joueur::setPosition(int x,int y)
{
	sprite.setPosition(x,y);	
}

Vector2f Joueur::getPosition()
{
	return sprite.getPosition();
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

void Joueur::collisionBloc(vector<Bloc*>* blocs,int x,int y)
{
	vector<Bloc*>::iterator it = blocs->begin();
	while(it != blocs->end())
	{
		if((*it)->getSprite()->getGlobalBounds().intersects(sprite.getGlobalBounds()) && (*it)->estCassable())//collision avec un bloc cassable
		{	
			Bloc* b = *it;
			it = blocs->erase(it);
			delete b;
			
		}
		else if((*it)->getSprite()->getGlobalBounds().intersects(sprite.getGlobalBounds()))//collision avec un bloc neutre
		{
			sprite.move(-x,-y);//annulation du mouvement
			++it;
		}
		else
			++it;
	}
}

void Joueur::collisionEntites(vector<Entite*>* entites)
{
	vector<Entite*>::iterator it = entites->begin();
	while(it != entites->end())
	{
		if((*it)->getSprite().getGlobalBounds().intersects(sprite.getGlobalBounds()))//collision avec un bloc cassable
		{	
			if(Etoile* e = dynamic_cast<Etoile*>(*it) ){
				it = entites->erase(it);
				delete e;
				viePlus();
			}	
		}
		else
			++it;
	}
}

int Joueur::getVie()
{
	return vie;
}

void Joueur::vieMoins()
{
	--vie;
}

void Joueur::viePlus()
{
	++vie;
}
