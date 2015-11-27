/*!
* \file TileMap.cpp
* \brief Fichier contenant l'implémentation de la classe TileMap
* \author Samia Ennaji
* \date 27.11.2015
*/

#include "TileMap.hpp"

//--------------------------------------------------
/*!
* \brief Méthode qui crée un niveau via un tileset
* \param tileset le fichier image utilisé pour les textures
* \param tileSize la taille d'une tuile
* \param tiles un tableau représentant la grille du niveau où chaque entier fait référence à une texture
* \param width la largeur de la grille
* \param height la hauteur de la grille
*/
bool TileMap::load(const string& tileset, Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height)
    {
        // on charge la texture du tileset
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices.setPrimitiveType(Quads);
        m_vertices.resize(width * height * 4);

        // on remplit le tableau de vertex, avec un quad par tuile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // on récupère le numéro de tuile courant
                int tileNumber = tiles[i + j * width];

                // on en déduit sa position dans la texture du tileset
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                Vertex* quad = &m_vertices[(i + j * width) * 4];

                // on définit ses quatre coins
                quad[0].position = Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // on définit ses quatre coordonnées de texture
                quad[0].texCoords = Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }

//--------------------------------------------------
/*!
* \brief Méthode qui affiche le niveau
* \param target objet qui affiche le niveau
* \param states défini les propriétés du niveau
*/
void TileMap::draw(RenderTarget& target, RenderStates states) const
{
        // on applique la transformation
        states.transform *= getTransform();

        // on applique la texture du tileset
        states.texture = &m_tileset;

        // et on dessine enfin le tableau de vertex
        target.draw(m_vertices, states);
}

