//
// Created by Aurélien Brachet on 15/09/2025.
//

#ifndef SPELL_H
#define SPELL_H
#include "drawable-entity.h"


class Fireball: public DrawableEntity {
    public:
    explicit Fireball(PositionData pos, Sprite::Name spriteName, Rect rect);
};

#endif //SPELL_H
