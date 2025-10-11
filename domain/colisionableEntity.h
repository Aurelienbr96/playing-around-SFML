//
// Created by Aurélien Brachet on 05/10/2025.
//

#ifndef COLISIONABLEENTITY_H
#define COLISIONABLEENTITY_H
#include "drawable-entity.h"
#include "player.h"


class ColisionableEntity: public DrawableEntity {
public:
    explicit ColisionableEntity(PositionData position, Sprite::Name spriteName, Rect rect);
    bool willColide(const Player &player, Direction direction) const;
};

#endif //COLISIONABLEENTITY_H
