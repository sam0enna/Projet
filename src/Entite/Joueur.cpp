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
    velocity = Vector2f(0,0);
    gauche = true;
    droite = true;
    victoire_ = false;
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
	if(x>0 && droite || x<0 && gauche){
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
		velocity.x += x;
	}
}

void Joueur::draw(RenderWindow &window)
{
	update();
	window.draw(sprite);
}

void Joueur::anim_stop(RenderWindow &window)
{	
    sprite.setTexture(stop);
    animation = JOUEUR_STOP;
    window.draw(sprite);
}

void Joueur::collisionBloc(vector<Bloc*>* blocs)
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
		else if((*it)->getSprite()->getGlobalBounds().intersects(sprite.getGlobalBounds()))
		{
			if((*it)->estVictorieux()){
				victoire_ = true;
				++it;
			}
			else{
				if((*it)->getSprite()->getGlobalBounds().left <= sprite.getGlobalBounds().left+sprite.getGlobalBounds().height)//collision avec un bloc neutre
				{
					droite = false;//annulation du mouvement
					++it;
				}
				else if((*it)->getSprite()->getGlobalBounds().left+(*it)->getSprite()->getGlobalBounds().height >= sprite.getGlobalBounds().left)
				{
					gauche = false;//annulation du mouvement
					++it;
				}
			}
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
			if(Etoile* e = dynamic_cast<Etoile*>((*it))){
				modifierVie((*it)->doAction());
				it = entites->erase(it);
				delete e;
			}else if (Monstre* e = dynamic_cast<Monstre*>((*it))){
				if(onGround() && e->estVivant())
				{
					setPosition(0,448);
				}
				else if(!onGround() &&e->estVivant()){
					e->setMort();
				}
				modifierVie((*it)->doAction());
				++it;
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

void Joueur::modifierVie(int i){
	vie+=i;
}

void Joueur::jump(){	
	if(onGround()){
		velocity.y = -12;
	}
}


bool Joueur::onGround(){
	return getPosition().y == 448;
}

void Joueur::update(){
	velocity.y += gravity;
	sprite.move(velocity.x,velocity.y);
	if(Keyboard::isKeyPressed(Keyboard::Left)){
		if(gauche){
			velocity.x = -5;
			droite = true;
		}
	}
	else if(Keyboard::isKeyPressed(Keyboard::Right)){ 
		if(droite){
			velocity.x = 5;
			gauche = true;
		}
	}
	else 
		velocity.x = 0;
	if(getPosition().y >448)
	{
		setPosition(getPosition().x,448);
		velocity.y = 0;
	}
}

bool Joueur::estMort(){
	return vie <= 0;
}


bool Joueur::estVictorieux(){
	return victoire_;
}
