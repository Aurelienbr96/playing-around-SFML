
//
// Created by Aurélien Brachet on 15/09/2025.
//

#include "fireball.h"


Fireball::Fireball(PositionData pos, Sprite::Name spriteName, Rect rect)
    : DrawableEntity(Position(pos.x, pos.y, rect.width, rect.height), spriteName) {}