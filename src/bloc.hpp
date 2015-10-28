#include <SFML/Graphics.hpp>
#define LARGEUR_BLOC 32
#define HAUTEUR_BLOC 32
class Bloc
{
	protected: 
				 sf::Sprite sprite;
				 
				virtual bool collisionMont();// monter à travers le bloc
				virtual bool collisionDesc();// descendre ...
				virtual Bloc* quandTouche(Entite& entite);
				virtual Bloc* quandCasse();
				void display(float x,float y);
				
			
			

			Bloc (sf::Texture& texture,int x, int y);


		 
}
