//
// Created by Aurélien Brachet on 25/09/2025.
//

#ifndef TILE_MAP_H
#define TILE_MAP_H
#include <filesystem>
#include <SFML/Graphics.hpp>
using namespace std;

class TileMap: public sf::Drawable, public sf::Transformable {
    sf::VertexArray m_vertices;
    sf::Texture     m_tileset;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    public:
    TileMap() = default;
    bool load(const filesystem::path& tileset, sf::Vector2u tileSize, const unsigned int (&map)[16][16], unsigned int width, unsigned int height);
};

#endif //TILE_MAP_H
