//
// Created by Aurélien Brachet on 15/09/2025.
//

#include "projectiles.h"
#include "../domain/fireball.h"

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


std::vector<Fireball> Projectiles::getProjectiles() const {
    return this->projectiles;
}