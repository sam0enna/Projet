#include "joueur.hpp"
using namespace std;
using namespace sf;
 
Joueur::Joueur() 
 // allocation attribus
{
    m_Mario = new Image();
    m_Blanc = new Image();
    m_sMario = new Sprite();
    m_sBlanc = new Sprite();
}
// destructeur pour désallouer la mémoire
Joueur::~Joueur() 
{
    delete m_Mario;
    delete m_sMario;
    delete m_Blanc;
    delete m_sBlanc;
}
 void Joueur::display() 
 // affiche mario en position bas
{
    m_Mario->LoadFromFile("mario_bas.gif");
    m_sMario->SetImage(*m_Mario);
}

//deplacer 
void Joueur::moove(RenderWindow &App)
{
    Event event;
 
    while (App.IsOpened())
    {
        while (App.GetEvent(event))   // deplacer mario dans la fenêtre
        {
            if ((event.Type == Event::KeyPressed) && (event.Key.Code == Key::Up))
            {
                m_Mario->LoadFromFile("mario_haut.gif");
                m_sMario->Move(0, -TAILLE_MARIO);
            }
 
            if ((event.Type == Event::KeyPressed) && (event.Key.Code == Key::Down))
            {
                m_Mario->LoadFromFile("mario_bas.gif");
                m_sMario->Move(0, TAILLE_MARIO);
            }
 
 
 if ((event.Type == Event::KeyPressed) && (event.Key.Code == Key::Left))
            {
                m_Mario->LoadFromFile("mario_gauche.jpg");
                m_sMario->Move(-TAILLE_MARIO, 0);
            }
 
            if ((event.Type == Event::KeyPressed) && (event.Key.Code == Key::Right))
            {
                m_Mario->LoadFromFile("mario_droite.jpg");
                m_sMario->Move(TAILLE_MARIO, 0);
            }
 
 // on ferme  la fenêtre si on clique sur la croie
            if (event.Type == Event::Closed) 
                App.Close();
        }
 
        App.Clear();
        App.Draw(*m_sMario);
        App.Draw(*m_sBlanc);
        App.Display();
    }
    
}
 void Joueur::displayCard()
{
    long carte[NB_BLOC][NB_BLOC] = {VIDE}; // création d'un double tableau qui va definir la carte
    Vector2f posElementCard;
 
    card[3][9] = VIDE;
 
   for (long i = 0 ; i < NB_BLOC ; i++)
    {
        for (long j = 0 ; j < NB_BLOC ; j++)
        {
            posElementCard.x = i * TAILLE_MARIO;
            posElementCard.y = j * TAILLE_MARIO;
 
            switch (card[i][j])
            {
                case VIDE:   //  mettre du blanc
                    m_Blanc->LoadFromFile("blanc.jpg");
                    m_sBlanc->SetImage(*m_Blanc);
                    m_sBlanc->SetPosition(posElementCard);
                    break;
            }
        }
    }
 
}
 
Sprite Joueur::getSprite()
{
    return *m_sMario;
}
