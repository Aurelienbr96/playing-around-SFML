//
// Created by Aurélien Brachet on 13/09/2025.
//

#include "SFMLRenderer.h"

#include "../../../../../opt/homebrew/Cellar/sfml/3.0.1/include/SFML/Graphics/RenderWindow.hpp"


SFMLRenderer::SFMLRenderer(sf::RenderWindow *w, SpriteLibrary& spriteLibrary): window(w), spriteLibrary(spriteLibrary) {}


void SFMLRenderer::render(PositionData pos, Sprite::Name spriteName) {
    auto sprite = this->spriteLibrary.getSprite(spriteName);
    sprite.setPosition(sf::Vector2f(pos.x, pos.y ));
    this->window->draw(sprite);
}

