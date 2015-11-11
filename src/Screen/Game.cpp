#include "Game.hpp"

Game::Game()
{
	type = GAME;
	perso = new Joueur();
}

Game::~Game()
{
	unload();
}

void Game::load()
{

// on définit le niveau à l'aide de numéro de tuiles
    const int level[] =
            {
                    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,56,48,48,48,48,48,48,48,48,48,48,48,48,48,40,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
            };

    // on crée la tilemap avec le niveau précédemment défini
    map;
    if (!map.load("res/tileset_ground.png", Vector2u(128, 128), level, 40, 16))
        std::cout << "Impossible de charger le fichier \"tileset_ground.png\"" << std::endl;

	//la carte est ensuite redimensionné
    map.scale(0.25f,0.25f);//tile en 32*32
	//La carte est prête
	
	// Chargement de l'arrière plan
	texture;
	if (!texture.loadFromFile("res/blue_grass.png", sf::IntRect(0, 272, 1024, 480)))
		std::cout << "Impossible de charger le fichier \"blue_grass.png\"" << std::endl;
	texture.setRepeated(true);
	// chargement de la texture dans un sprite
	background.setTexture(texture);
	background.setTextureRect({ 0, 0, 1280, 480 });//la texture se répète dans un bloc de 1280*480
	
	//positionnement du perso
	perso->setPosition(0,448);
	//448 car il y a 16 rangées de tuiles, les deux dernières représentent le sol.
	//on veut que le coin gauche du perso touche le sol (donc la 14eme rangée)
	//14*32=448 (32 la taille d'une tuile)
	
	neutre.loadFromFile("res/box_neutre.png");
	cassable.loadFromFile("res/box_cassable.png");
	blocs.push_back(new Bloc(500,448));
	blocs.push_back(new Bloc(60,448));
	
	(new Neutre(blocs.at(0),neutre))->setCassable();
	(new Cassable(blocs.at(1),cassable))->setCassable();
	(new Neutre(blocs.at(2),neutre))->setCassable();

}

void Game::unload()
{
	
}

void Game::draw(RenderWindow &window)
{
	window.draw(background);
	window.draw(map);
	perso->draw(window);
	for(vector<Bloc*>::iterator it = blocs.begin(); it!=blocs.end();++it)
		(*it)->display(window);
	
}

void Game::move(int x,int y)
{
	perso->move(x,y);
	perso->collision(&blocs,x,y);
}

Joueur* Game::getJoueur()
{
	return perso;
}


