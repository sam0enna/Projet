/*!
* \file Main.cpp
* \brief Application
* \author Samia Ennaji
* \author Michelle Sonia Guiadem Kaptue
* \date 27.11.2015
*/

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Screen/ScreenManager.hpp"
#include "Screen/ScreenState.hpp"
#include "Screen/Menu.hpp"
#include "Screen/Game.hpp"
#include "Screen/Fin.hpp"

using namespace std;
using namespace sf;



int main() {
    // on crée la fenêtre
    RenderWindow window(VideoMode(640,480), "The Game");

	ScreenManager manager;
	manager.init();
    // on fait tourner la boucle principale
    View vue(sf::Vector2f(320, 240), sf::Vector2f(640, 480));
    window.setView(vue);
    while (window.isOpen())
    {
        // on gère les évènements
        Event event;
        while (window.pollEvent(event))
        {
            if(event.type == Event::Closed)
                window.close();
                
            if(event.type == Event::KeyPressed){
					switch(event.key.code)
					{
						case Keyboard::Space:
							manager.setCurrentScreen(new Game());
							break;
							
						case Keyboard::Left:
							manager.getCurrentScreen()->move(-3,0);
							break;
						
						case Keyboard::Right:
							manager.getCurrentScreen()->move(3,0);
							break;
							
						case Keyboard::Up:
							manager.getCurrentScreen()->haut();
							break;
							
						default:
							break;
					}
			}
           
        }
        
        if(Game* scene = dynamic_cast<Game*>(manager.getCurrentScreen())){
			Vector2f position;
			if(scene->estFini()){
				manager.setCurrentScreen(new Fin(true));
				position.x = 320;
				position.y = 240;
				vue.setCenter(position);
			}
			else if(scene->perdu()){
				manager.setCurrentScreen(new Fin(false));
				position.x = 320;
				position.y = 240;
				vue.setCenter(position);
			}
			else{
				position  = scene->getJoueur()->getPosition();
				if(position.x < 320)
					position.x = 320;
				if(position.x > 960)
					position.x = 960;
				if(position.y > 240)
					position.y = 240;
				
				vue.setCenter(position);
			}
			
			//sf::Music music;
			//if (music.openFromFile("res/music.wav"))
				//music.play();
		}
		window.setView(vue);
        // on dessine le niveau
        window.clear();
        manager.draw(window);
        window.display();
        
    }


    return 0;
}
