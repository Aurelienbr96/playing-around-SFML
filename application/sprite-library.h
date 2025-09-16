//
// Created by Aurélien Brachet on 13/09/2025.
//

#ifndef SPRITE_LIBRARY_H
#define SPRITE_LIBRARY_H
#include <unordered_map>

#include "../../../../../opt/homebrew/Cellar/sfml/3.0.1/include/SFML/Graphics/Sprite.hpp"

namespace Sprite {
    enum Name {
        Fireball,
        BackgroundHigh,
        BackgroundHigh2,
        BackgroundLow,
        BackgroundLow2,
        BackgroundMedium,
        BackgroundMedium2,
        FlyingBoonUp,
        FlyingBoonDown,
        FlyingBoonCalm,
    };
}

class SpriteLibrary {
    std::unordered_map<Sprite::Name, sf::Sprite> spriteLib;
    public:
      SpriteLibrary() = default;
      void addSprite(Sprite::Name spriteName, sf::Sprite& sprite);
      sf::Sprite& getSprite(Sprite::Name spriteName);
};

#endif //SPRITE_LIBRARY_H
