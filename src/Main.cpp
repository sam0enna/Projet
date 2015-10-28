#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Screen/ScreenManager.hpp"
#include "Screen/ScreenState.hpp"
#include "Screen/Menu.hpp"
#include "Screen/Game.hpp"

using namespace std;
using namespace sf;



int main() {
    // on crée la fenêtre
    RenderWindow window(VideoMode(640,480), "The Game");

	ScreenManager manager;
	manager.init();
    // on fait tourner la boucle principale
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
							manager.getCurrentScreen()->move(-5,0);
							break;
						
						case Keyboard::Right:
							manager.getCurrentScreen()->move(5,0);
							break;
							
						default:
							break;
					}
			}
           
        }
        // on dessine le niveau
        window.clear();
        manager.draw(window);
        window.display();
        
    }


    return 0;
}
