
#include <SFML/system.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
 
#define NB_BLOC 100
#define TAILLE_MARIO 34
#define LARGEUR_FENETRE 408
#define HAUTEUR_FENETRE 408
 
enum {VIDE, MUR, CAISSE, OBJECTIF, MARIO, CAISSE_OK};
 
class Joueur
{
    public :
 
    Joueur();
    ~Joueur();
    void display();
    void moove(sf::RenderWindow& app);
    void position();
    void displayCard();
    sf::Sprite getSprite();
 
    private :
 
    sf::Image *m_Mario, *m_Blanc;
    sf::Sprite *m_sMario, *m_sBlanc;
 
};
