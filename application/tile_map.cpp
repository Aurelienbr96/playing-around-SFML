//
// Created by Aurélien Brachet on 25/09/2025.
//

#include "tile_map.h"

int getTileNumber(unsigned int tileNumber) {
    if (tileNumber == 0) {
        return 1;
    }
    if (tileNumber == 1) {
        return 4;
    }
    if (tileNumber == 2) {
        return 5;
    }
    if (tileNumber == 3) {
        return 2;
    }
    return 0;
}

bool  TileMap::load(const std::filesystem::path& tileset, sf::Vector2u tileSize, std::vector<std::vector<unsigned int>>& map, unsigned int width, unsigned int height)
    {
        // load the tileset texture
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // resize the vertex array to fit the level size
        m_vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
        m_vertices.resize(width * height * 6);

        // populate the vertex array, with two triangles per tile
    for (unsigned int j = 0; j < height; ++j)      // rows
    {
        for (unsigned int i = 0; i < width; ++i)   // cols
        {
            const int tileNumber = map[j][i];
            if (tileNumber == 0) continue;   // skip empty tile

            const int tilesPerRow = m_tileset.getSize().x / tileSize.x;

            const int tu = (tileNumber - 1) % tilesPerRow;
            const int tv = (tileNumber - 1) / tilesPerRow;

            sf::Vertex* triangles = &m_vertices[(i + j * width) * 6];

            float x = i * tileSize.x;
            float y = j * tileSize.y;

            triangles[0].position = {x, y};
            triangles[1].position = {x + tileSize.x, y};
            triangles[2].position = {x, y + tileSize.y};
            triangles[3].position = {x, y + tileSize.y};
            triangles[4].position = {x + tileSize.x, y};
            triangles[5].position = {x + tileSize.x, y + tileSize.y};

            float u = tu * tileSize.x;
            float v = tv * tileSize.y;

            triangles[0].texCoords = {u, v};
            triangles[1].texCoords = {u + tileSize.x, v};
            triangles[2].texCoords = {u, v + tileSize.y};
            triangles[3].texCoords = {u, v + tileSize.y};
            triangles[4].texCoords = {u + tileSize.x, v};
            triangles[5].texCoords = {u + tileSize.x, v + tileSize.y};
        }
    }


        return true;
    }


void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &m_tileset;

        // draw the vertex array
        target.draw(m_vertices, states);
}
