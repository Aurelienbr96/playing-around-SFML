//
// Created by Aurélien Brachet on 15/09/2025.
//

#ifndef SPELL_H
#define SPELL_H
#include "direction.h"
#include "drawable-entity.h"

class Fireball: public DrawableEntity {
    Direction direction;
    public:
    explicit Fireball(PositionData pos, Sprite::Name spriteName, Rect rect, Direction direction);
    void move();
};

#endif //SPELL_H
