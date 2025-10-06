//
// Created by Aurélien Brachet on 05/10/2025.
//

#ifndef COLISIONABLEENTITY_H
#define COLISIONABLEENTITY_H
#include "drawable-entity.h"


class ColisionableEntity: public DrawableEntity {
public:
    explicit ColisionableEntity(PositionData position, Sprite::Name spriteName, Rect rect);
    bool willColide(const DrawableEntity &entity) const;
};

#endif //COLISIONABLEENTITY_H
