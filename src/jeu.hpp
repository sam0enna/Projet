#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "etat.hpp"
class Jeu : public Etat 
{
	private:
			std::vector <Bloc*> blocs;
			std::vector <std::vector<int> > grille;
			std::vector <Entite*> entites; 
			Joueur* joueur;
	public:
			Jeu(sf::RenderWindow& window);
	protected:
			virtual void display();
			virtual Etat* update();
			virtual Etat* input();
	

}
