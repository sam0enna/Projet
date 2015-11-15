
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Entite.hpp" 
#include "Etoile.hpp"
#include "../Bloc/Bloc.hpp"
 
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
    Vector2f getPosition();
    void move(int x,int y);
    void draw(RenderWindow &window);
    void anim_stop(RenderWindow &window);
    void collision(vector<Bloc*>* blocs,int x, int y);
    int getVie();
    void vieMoins();
    void viePlus();
    
    private :
		Texture stop;
		Texture marche1;
		Texture marche2;
		int animation;
		int vie;
 
};
