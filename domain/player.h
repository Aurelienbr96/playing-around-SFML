//
// Created by Aurélien Brachet on 08/09/2025.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include "direction.h"
#include "position.h"
#include "../world/projectiles.h"

class Player: public DrawableEntity {
    int speedFactor;
    unsigned int playerId;
    Direction currentDirection;

public:
    explicit Player(PositionData pos, float speedFactor, Sprite::Name spriteName, unsigned int playerId, Rect rect);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    PositionData getNextPosition(Direction direction) const;
    void moveTo(PositionData pos);
    void setSpriteName(Sprite::Name spriteName);
    void castSpell(unsigned int spellId, Projectiles& projectiles);

    PositionData getPosition() const;
};

#endif //CHARACTER_H
