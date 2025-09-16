//
// Created by Aurélien Brachet on 14/09/2025.
//

#include "drawable-entity.h"

void DrawableEntity::draw(Renderer &renderer) {
    auto position = this->position.getPosition();
    renderer.render({position.x, position.y}, this->spriteName);
}

