//
// Created by Aurélien Brachet on 08/09/2025.
//

#ifndef CHARACTER_H
#define CHARACTER_H
#include "drawable-entity.h"
#include "position.h"
#include "../world/projectiles.h"

class Player: public DrawableEntity {
    int speedFactor;
    unsigned int playerId;

public:
    explicit Player(PositionData pos, float speedFactor, Sprite::Name spriteName, unsigned int playerId, Rect rect);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void setSpriteName(Sprite::Name spriteName);
    void castSpell(unsigned int spellId, Projectiles& projectiles);

    PositionData getPosition();
};

#endif //CHARACTER_H
