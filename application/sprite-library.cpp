//
// Created by Aurélien Brachet on 13/09/2025.
//

#include "sprite-library.h"
#include <iostream>

void SpriteLibrary::addSprite(unsigned int spriteId, sf::Sprite &sprite) {
    if (spriteLib.find(spriteId) != spriteLib.end()) {
        // Already exists
        std::cout << "Sprite with ID " << spriteId << " already exists!\n";
        return;
    }
    this->spriteLib.insert({spriteId, sprite});
}


sf::Sprite &SpriteLibrary::getSprite(const unsigned int id) {
    return this->spriteLib.at(id);
}
