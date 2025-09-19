
//
// Created by Aurélien Brachet on 15/09/2025.
//

#include "fireball.h"

#include "player.h"
#include "direction.h"


Fireball::Fireball(PositionData pos, Sprite::Name spriteName, Rect rect, Direction direction)
    : DrawableEntity(Position(pos.x, pos.y, rect.width, rect.height), spriteName), direction(direction) {}
void Fireball::move() {
    if (this->direction == Up) {
        this->position.updatePosition({0, 0.2});
    }

    if (this->direction == Down) {
        this->position.updatePosition({0, -0.2});
    }

    if (this->direction == Right) {
        this->position.updatePosition({0.2, 0});
    }
    if (this->direction == Left) {
        this->position.updatePosition({-0.2, 0});
    }
}
