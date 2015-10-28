#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "etat.hpp"
#include "jeu.hpp"
class Pause : public Etat 
{
	private:
			Jeu* jeu;
			sf::Text texte;
	public:
			Pause(sf::RenderWindow& window,Jeu* jeu);
	protected:
			virtual void display();
			virtual Etat* update();
			virtual Etat* input();
	
}
