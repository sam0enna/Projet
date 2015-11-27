/*!
* \file TileMap.hpp
* \brief Fichier contenant la déclaration de la classe TileMap
* \author Samia Ennaji
* \date 27.11.2015
*/

#ifndef TILEMAP_TRAIN_TILEMAP_H
#define TILEMAP_TRAIN_TILEMAP_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

/*!
* \class TileMap
* \brief classe qui implémente la création d'un niveau via un fichier tileset
*/
class TileMap : public Drawable, public Transformable
{
public:

    bool load(const string& tileset, Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

private:

    virtual void draw(RenderTarget& target, RenderStates states) const;
    VertexArray m_vertices;//!< le décor du niveau
    Texture m_tileset;//!< la tileset
};

#endif //TILEMAP_TRAIN_TILEMAP_H
