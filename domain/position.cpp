//
// Created by Aurélien Brachet on 08/09/2025.
//

#include "position.h"


Position::Position(float x, float y, unsigned int width, unsigned int height): x(x), y(y), width(width), height(height) {
}

void Position::setPosition(PositionData pos) {
    this->x = pos.x;
    this->y = pos.y;
}

PositionData Position::getPosition() {
    return {x, y};
}

