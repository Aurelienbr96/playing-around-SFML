//
// Created by Aurélien Brachet on 13/09/2025.
//

#include "sprite-library.h"
#include <iostream>

void SpriteLibrary::addSprite(Sprite::Name spriteName, sf::Sprite &sprite) {
    if (spriteLib.find(spriteName) != spriteLib.end()) {
        // Already exists
        std::cout << "Sprite with ID " << spriteName << " already exists!\n";
        return;
    }
    this->spriteLib.insert({spriteName, sprite});
}


sf::Sprite &SpriteLibrary::getSprite(Sprite::Name spriteName) {
    return this->spriteLib.at(spriteName);
}
