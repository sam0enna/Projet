#include "bloc.hpp"

//constructeur
Bloc:: Bloc(sf::Texture& texture,int x, int y):sprite(texture){

sf::IntRect rect ;
rect.left= x*LARGEUR_BLOC;
rect.top= y*HAUTEUR_BLOC;
rect.width=LARGEUR_BLOC;
rect.height=HAUTEUR_BLOC;

sprite.setTextureRect(rect);
}
 bool Bloc:: collisionMont(){ // monter à travers le bloc
 
 return false ; 
 }
 bool Bloc :: collisionDesc(){ // descendre à travers le bloc
 return false ;
 }
Bloc* Bloc :: quandTouche(Entite& entite){ //lorsqu'une entité touche un bloc

return this;
}
 Bloc* Bloc :: quandCasse(){ // lorsqu'une une entité essaye de casser un bloc
 return this; // le bloc lui méme
 
 }
 void Bloc ::display(float x,float y){ //pour afficher un bloc 
 sprite.setPosition( x, y);
 window.draw(sprite);

 }
 
 
				
