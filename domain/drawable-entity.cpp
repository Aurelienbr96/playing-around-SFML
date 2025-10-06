//
// Created by Aurélien Brachet on 14/09/2025.
//

#include "drawable-entity.h"


void DrawableEntity::draw(Renderer &renderer) {
    auto position = this->position.getPosition();
    renderer.render({position.x, position.y}, this->spriteName);
}

Rect DrawableEntity::getSize() const {
    auto pos = this->position;
    return pos.getRect();
}

PositionData DrawableEntity::getPosition() const {
    auto pos = this->position;
    return pos.getPosition();
}
