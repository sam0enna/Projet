#include "pause.hpp"

// constructeur

Pause::Pause(sf::RenderWindow& window,Jeu* jeu):jeu(jeu),texte("Pause",font,50),Etat(window){

}

virtual void Pause::display(){ // afficher le texte 
window.draw(texte); 
}
virtual Etat* Pause::update(){
return this; // pour le changement d'état
}
virtual Etat* Pause input(sf::Event& event){
if( event.type == sf::Event::KeyPressed) //si on touche un bouton de clavier 
//on quitte l'état pause 
{
delete this;
return jeu ;
}
else 
return this; // on reste dans l'état pause 

}
