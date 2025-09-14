//
// Created by Aurélien Brachet on 13/09/2025.
//

#ifndef SPRITE_LIBRARY_H
#define SPRITE_LIBRARY_H
#include <unordered_map>

#include "../../../../../opt/homebrew/Cellar/sfml/3.0.1/include/SFML/Graphics/Sprite.hpp"

class SpriteLibrary {
    std::unordered_map<unsigned int, sf::Sprite> spriteLib;
    public:
      SpriteLibrary() = default;
      void addSprite(unsigned int spriteId, sf::Sprite& sprite);
      sf::Sprite& getSprite(unsigned int id);
};

#endif //SPRITE_LIBRARY_H
