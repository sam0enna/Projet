/*!
* \file Game.cpp
* \brief Fichier contenant l'implémentation de la classe Game
* \author Samia Ennaji
* \date 27.11.2015
*/

#include "Game.hpp"

//--------------------------------------------------
/*!
* \brief Constructeur
*/
Game::Game()
{
	type = GAME;
	perso = new Joueur();
}

//--------------------------------------------------
/*!
* \brief Destructeur
*/
Game::~Game()
{
	unload();
}

//--------------------------------------------------
/*!
* \brief Méthode qui charge les composants
*/
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
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,56,48,48,40,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,56,48,48,48,48,48,48,48,48,48,48,48,48,48,40,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
            };

   
    // on crée la tilemap avec le niveau précédemment défini
    map;
    if (!map.load("res/tileset_ground.png", Vector2u(128, 128), level, 40, 16))
        std::cout << "Impossible de charger le fichier \"tileset_ground.png\"" << std::endl;

// on définit le niveau à l'aide de numéro de tuiles
    const int level_decor[] =
            {
                    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,42,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,43,7,7,42,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,42,7,7,7,7,7,7,7,43,7,7,7,7,7,7,7,43,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
					7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
            };

   decor;
    // on crée la tilemap avec le niveau précédemment défini
    if (!decor.load("res/tileset_decor.png", Vector2u(128, 128), level_decor, 40, 16))
        std::cout << "Impossible de charger le fichier \"tileset_decor.png\"" << std::endl;



	//la carte est ensuite redimensionné
    decor.scale(0.25f,0.25f);//tile en 32*32
	//La carte est prête
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
	blocs.push_back(new Bloc(500,352));
	blocs.push_back(new Bloc(60,448));
	blocs.push_back(new Bloc(256,352));
	blocs.push_back(new Bloc(1220,448));
	
	(new Neutre(blocs.at(0)))->setCassable();
	(new Cassable(blocs.at(1)))->setCassable();
	(new Cassable(blocs.at(2)))->setCassable();
	(new Exit(blocs.at(3)))->setCassable();
	
	entites.push_back(new Etoile());
	(entites.at(0))->setPosition(67,448);
	
	entites.push_back(new Etoile());
	(entites.at(1))->setPosition(259,340);
	
	entites.push_back(new Monstre("slimePurple"));
	(entites.at(2))->setPosition(300,448);

	entites.push_back(new Monstre("slimeBlue"));
	(entites.at(3))->setPosition(800,448);
	
	entites.push_back(new Monstre("slimeGreen"));
	(entites.at(4))->setPosition(540,448);

	entites.push_back(new Champignon());
	(entites.at(5))->setPosition(400,340);
	
	entites.push_back(new Etoile());
	(entites.at(6))->setPosition(1154,340);
	
	entites.push_back(new Etoile());
	(entites.at(7))->setPosition(673,340);

}

//--------------------------------------------------
/*!
* \brief Méthode qui décharge les composants
*/
void Game::unload()
{	
}

//--------------------------------------------------
/*!
* \brief Méthode qui affiche les composants
*/
void Game::draw(RenderWindow &window)
{
	window.draw(background);
	window.draw(decor);
	window.draw(map);
	
	perso->collisionBloc(&blocs);
	perso->collisionEntites(&entites);
	perso->draw(window);
	for(vector<Entite*>::iterator at = entites.begin(); at!=entites.end();++at){
		(*at)->draw(window);
	}
	for(vector<Bloc*>::iterator it = blocs.begin(); it!=blocs.end();++it){
		(*it)->display(window);
	}	
}

//--------------------------------------------------
/*!
* \brief Méthode qui gère les déplacements gauche droite
*/
void Game::move(int x,int y)
{
	cout << perso->getVie() << endl;
	perso->move(x,y);
	perso->collisionBloc(&blocs);
	perso->collisionEntites(&entites);
}

//--------------------------------------------------
/*!
* \brief Méthode qui gère les déplacements haut
*/
void Game::haut()
{
	perso->jump();
}

//--------------------------------------------------
/*!
* \brief Méthode qui retourne le joueur
*/
Joueur* Game::getJoueur()
{
	return perso;
}

//--------------------------------------------------
/*!
* \brief Méthode qui teste si le joueur a trouvé la sortie
*/
bool Game::estFini(){
	return perso->estVictorieux();
}

//--------------------------------------------------
/*!
* \brief Méthode qui teste si le joueur est mort
*/
bool Game::perdu(){
	return perso->estMort();
}
