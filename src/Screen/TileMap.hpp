#ifndef TILEMAP_TRAIN_TILEMAP_H
#define TILEMAP_TRAIN_TILEMAP_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class TileMap : public Drawable, public Transformable
{
public:

    bool load(const string& tileset, Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

private:

    virtual void draw(RenderTarget& target, RenderStates states) const;
    VertexArray m_vertices;
    Texture m_tileset;
};

#endif //TILEMAP_TRAIN_TILEMAP_H
