//
// Created by Aurélien Brachet on 08/09/2025.
//

#include <utility>
#include "position.h"
#include "player.h"

Player::Player(PositionData pos, float speedFactor, Sprite::Name spriteName, unsigned int playerId, Rect rect)
    : DrawableEntity(Position(pos.x, pos.y, rect.width, rect.height), spriteName), // call base constructor
      speedFactor(speedFactor), playerId(playerId) {}


// MOVEMENT METHODS

void Player::moveDown() {
    const float mov = this->speedFactor * 0.5;
    this->position.setPosition({this->getPosition().x, this->getPosition().y + mov});
}

void Player::setSpriteName(Sprite::Name spriteName) {
    this->spriteName = spriteName;
}

void Player::moveUp() {
    const float mov = this->speedFactor * 0.5;

    this->position.setPosition({this->getPosition().x, this->getPosition().y - mov});
}

void Player::moveLeft() {
    const float mov = this->speedFactor * 0.5;

    this->position.setPosition({this->getPosition().x - mov, this->getPosition().y});
}

void Player::moveRight() {
    const float mov = this->speedFactor * 0.5;

    this->position.setPosition({this->getPosition().x + mov, this->getPosition().y});
}

PositionData Player::getPosition() {
    return this->position.getPosition();
}

void Player::castSpell(unsigned int spellId, Projectiles& projectiles) {
    projectiles.addProjectile(spellId, {this->getPosition().x, this->getPosition().y});
}
