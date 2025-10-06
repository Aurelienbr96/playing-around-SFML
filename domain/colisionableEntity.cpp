//
// Created by Aurélien Brachet on 05/10/2025.
//

#include "colisionableEntity.h"

ColisionableEntity::ColisionableEntity(PositionData pos, Sprite::Name spriteName, const Rect rect):
DrawableEntity(Position(pos.x, pos.y, rect.width, rect.height), spriteName) {}


bool ColisionableEntity::willColide(const DrawableEntity &entity) const {
    auto posA = this->getPosition();
    auto sizeA = this->getSize();
    auto posB = entity.getPosition();
    auto sizeB = entity.getSize();

    // Axis-Aligned Bounding Box (AABB) collision detection
    bool overlapX = posA.x < posB.x + sizeB.height && posA.x + sizeA.height > posB.x;
    bool overlapY = posA.y < posB.y + sizeB.width && posA.y + sizeA.width > posB.y;

    return overlapX && overlapY;
}
