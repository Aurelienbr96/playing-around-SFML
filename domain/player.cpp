//
// Created by Aurélien Brachet on 08/09/2025.
//

#include <utility>
#include "position.h"
#include "player.h"
#include "direction.h"

Player::Player(PositionData pos, float speedFactor, Sprite::Name spriteName, unsigned int playerId, Rect rect)
    : DrawableEntity(Position(pos.x, pos.y, rect.width, rect.height), spriteName), // call base constructor
      speedFactor(speedFactor), playerId(playerId) {}


// MOVEMENT METHODS

PositionData Player::getNextPosition(Direction direction) const {
    const float mov = this->speedFactor * 0.1;
    if (direction == Direction::Down) {
        return {this->getPosition().x, this->getPosition().y + mov};
    }
    if (direction == Direction::Right) {
        return {this->getPosition().x + mov, this->getPosition().y};
    }
    if (direction == Direction::Left) {
        return {this->getPosition().x - mov, this->getPosition().y};
    }
    if (direction == Direction::Up) {
        return {this->getPosition().x, this->getPosition().y - mov};
    }
    // sketchy imo
    return {this->getPosition().x + mov, this->getPosition().y};
}

void Player::moveDown() {
    const float mov = this->speedFactor * 0.1;
    this->position.setPosition({this->getPosition().x, this->getPosition().y + mov});
    this->currentDirection = Down;
}

void Player::setSpriteName(Sprite::Name spriteName) {
    this->spriteName = spriteName;
}

void Player::moveUp() {
    const float mov = this->speedFactor * 0.1;

    this->position.setPosition({this->getPosition().x, this->getPosition().y - mov});
    this->currentDirection = Up;
}

void Player::moveLeft() {
    const float mov = this->speedFactor * 0.1;

    this->position.setPosition({this->getPosition().x - mov, this->getPosition().y});
    this->currentDirection = Left;
}

void Player::moveTo(PositionData position) {
    this->position.setPosition({position.x, position.y});
    this->currentDirection = Left;
}

void Player::moveRight() {
    const float mov = this->speedFactor * 0.1;

    this->position.setPosition({this->getPosition().x + mov, this->getPosition().y});
    this->currentDirection = Right;
}

PositionData Player::getPosition() const {
    return this->position.getPosition();
}

void Player::castSpell(unsigned int spellId, Projectiles& projectiles) {
    projectiles.addProjectile(spellId, {this->getPosition().x, this->getPosition().y}, this->currentDirection);
}
