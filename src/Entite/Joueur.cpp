/*!
* \file Joueur.cpp
* \brief Fichier contenant l'implémentation de la classe Joueur
* \author Samia Ennaji
* \date 27.11.2015
*/

#include "Joueur.hpp"
using namespace std;
using namespace sf;

//--------------------------------------------------
/*!
* \brief Constructeur
*/
Joueur::Joueur()
{
    stop.loadFromFile("res/Green/alienGreen_front.png");
    marche1.loadFromFile("res/Green/alienGreen_walk1.png");
    marche2.loadFromFile("res/Green/alienGreen_walk2.png");
    sprite.setTexture(stop);
    sprite.setOrigin(0,256);//coin inférieur gauche.
    sprite.scale(0.3f,0.3f);
    animation = JOUEUR_STOP;
    vie = 3;
    velocity = Vector2f(0,0);
    gauche = true;
    droite = true;
    victoire_ = false;
}

//--------------------------------------------------
/*!
* \brief Destructeur
*/
Joueur::~Joueur() 
{
}

//--------------------------------------------------
/*!
* \brief Méthode qui modifie la position du joueur
* \param x la coordonnée x
* \param y la coordonnée y
*/
void Joueur::setPosition(int x,int y)
{
	sprite.setPosition(x,y);	
}

//--------------------------------------------------
/*!
* \brief Méthode qui retourne la position du joueur
*/
Vector2f Joueur::getPosition()
{
	return sprite.getPosition();
}

//--------------------------------------------------
/*!
* \brief Méthode qui déplace le joueur
* \param x la coordonnée x
* \param y la coordonnée y
*/
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

//--------------------------------------------------
/*!
* \brief Méthode qui affiche le joueur
* \param window la fenêtre
*/
void Joueur::draw(RenderWindow &window)
{
	update();
	window.draw(sprite);
}

//--------------------------------------------------
/*!
* \brief Méthode qui réinitialise l'animation du joueur
* \param window la fenêtre
*/
void Joueur::anim_stop(RenderWindow &window)
{	
    sprite.setTexture(stop);
    animation = JOUEUR_STOP;
    window.draw(sprite);
}

//--------------------------------------------------
/*!
* \brief Méthode qui test les collisions avec les blocs
* \param blocs les blocs du niveau
*/
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
				if((*it)->getSprite()->getGlobalBounds().left <= sprite.getGlobalBounds().left+sprite.getGlobalBounds().width)//collision avec un bloc neutre
				{
					droite = false;//annulation du mouvement
					cout<<"collision gauche"<<endl;
					++it;
				}
				else if((*it)->getSprite()->getGlobalBounds().left+(*it)->getSprite()->getGlobalBounds().width >= sprite.getGlobalBounds().left)
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

//--------------------------------------------------
/*!
* \brief Méthode qui teste les collisions avec les entités
* \param entités les entités du niveau
*/
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
			}else{
				float taille = (float)((*it)->doAction())/10.0f;
				cout<<"taille:"<<taille<<endl;
				sprite.scale(taille,taille);
				it = entites->erase(it);
			}
		}
		else
			++it;
	}
}

//--------------------------------------------------
/*!
* \brief Méthode qui retourne la vie du joueur
*/
int Joueur::getVie()
{
	return vie;
}

//--------------------------------------------------
/*!
* \brief Méthode qui décrémente la vie du joueur
*/
void Joueur::vieMoins()
{
	--vie;
}

//--------------------------------------------------
/*!
* \brief Méthode qui incrémente la vie du joueur
*/
void Joueur::viePlus()
{
	++vie;
}

//--------------------------------------------------
/*!
* \brief Méthode qui modifie la vie du joueur
* \param i l'incrément de la vie
*/
void Joueur::modifierVie(int i){
	vie+=i;
}

//--------------------------------------------------
/*!
* \brief Méthode qui réalise le saut du joueur
*/
void Joueur::jump(){	
	if(onGround()){
		velocity.y = -12;
	}
}

//--------------------------------------------------
/*!
* \brief Méthode qui teste si le joueur est au sol
*/
bool Joueur::onGround(){
	return getPosition().y == 448;
}

//--------------------------------------------------
/*!
* \brief Méthode qui met à jour la position du joueur
*/
void Joueur::update(){
	velocity.y += gravity;
	sprite.move(velocity.x,velocity.y);
	if(Keyboard::isKeyPressed(Keyboard::Left)){
		if(gauche){
			velocity.x = -3;
			droite = true;
		}
	}
	else if(Keyboard::isKeyPressed(Keyboard::Right)){ 
		if(droite){
			velocity.x = 3;
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
	
	if(getPosition().x<0){
		setPosition(0,getPosition().y);
		velocity.x = 0;
	}
}

//--------------------------------------------------
/*!
* \brief Méthode qui teste si le joueur est mort
*/
bool Joueur::estMort(){
	return vie <= 0;
}

//--------------------------------------------------
/*!
* \brief Méthode qui teste si le joueur a gagné
*/
bool Joueur::estVictorieux(){
	return victoire_;
}
