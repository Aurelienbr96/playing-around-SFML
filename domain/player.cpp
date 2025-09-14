//
// Created by Aurélien Brachet on 08/09/2025.
//
#include "player.h"

#include <utility>
#include "position.h"
Player::Player(PositionData pos, int speedFactor, unsigned int spriteId)
    : DrawableEntity(Position(pos.x, pos.y), spriteId), // call base constructor
      speedFactor(speedFactor) {}


// MOVEMENT METHODS

void Player::moveDown() {
    const float mov = this->speedFactor * 2;
    this->position.setPosition({this->getPosition().x, this->getPosition().y + mov});
}

void Player::moveUp() {
    const float mov = this->speedFactor * 2;

    this->position.setPosition({this->getPosition().x, this->getPosition().y - mov});
}

void Player::moveLeft() {
    const float mov = this->speedFactor * 2;

    this->position.setPosition({this->getPosition().x - mov, this->getPosition().y});

}

void Player::moveRight() {
    const float mov = this->speedFactor * 2;

    this->position.setPosition({this->getPosition().x + mov, this->getPosition().y});
}

PositionData Player::getPosition() {
    return this->position.getPosition();
}
