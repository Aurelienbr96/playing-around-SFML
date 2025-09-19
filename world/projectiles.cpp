//
// Created by Aurélien Brachet on 15/09/2025.
//

#include "projectiles.h"
#include "../domain/fireball.h"
#include "../domain/player.h"

Projectiles::Projectiles(SpellBook& spellbook, SpriteLibrary& spriteLibrary): spellbook(spellbook), spritelibrary(spriteLibrary) {
}

void Projectiles::addProjectile(unsigned int projectileId, PositionData intialPosition) {
    if (auto spellDef = this->spellbook.get(projectileId)) {
        if (spellDef->name == "fireball") {
            Fireball fireball = Fireball({intialPosition.x + 20, intialPosition.y + 20}, spellDef->spriteName, spellDef->rect);
            this->projectiles.push_back(fireball);
        }
    }
}

void Projectiles::update() {
    for (auto& projectile : this->projectiles) {
        projectile.move({0,0.2});
    }
}

std::vector<Fireball> Projectiles::getProjectiles() const {
    return this->projectiles;
}