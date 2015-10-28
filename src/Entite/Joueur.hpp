
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Entite.hpp" 
 
#define JOUEUR_STOP 0
#define JOUEUR_MARCHE_1 1
#define JOUEUR_MARCHE_2 2
 
using namespace std;
using namespace sf;
 
class Joueur : public Entite
{
    public :
 
    Joueur();
    ~Joueur();
    
    void setPosition(int x, int y);
    void move(int x,int y);
    void draw(RenderWindow &window);
    void anim_stop(RenderWindow &window);
    
    private :
		Texture stop;
		Texture marche1;
		Texture marche2;
		int animation;
 
};
