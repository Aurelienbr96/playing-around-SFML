//
// Created by Aurélien Brachet on 08/09/2025.
//

#ifndef CHARACTER_H
#define CHARACTER_H
#include "drawable-entity.h"
#include "position.h"

class Player: public DrawableEntity {
    int speedFactor;

public:
    explicit Player(PositionData pos, int speedFactor, unsigned int spriteId);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    PositionData getPosition();
};

#endif //CHARACTER_H
