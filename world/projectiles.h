//
// Created by Aurélien Brachet on 15/09/2025.
//

#ifndef PROJECTILES_H
#define PROJECTILES_H
#include <vector>

#include "../application/spell-book.h"
#include "../application/sprite-library.h"
#include "../domain/drawable-entity.h"
#include "../domain/fireball.h"

class Projectiles {
    std::vector<Fireball> projectiles;
    SpellBook& spellbook;
    SpriteLibrary& spritelibrary;
    public:
    Projectiles(SpellBook& spellbook, SpriteLibrary& spritelibrary);
    std::vector<Fireball> getProjectiles() const;
    void addProjectile(unsigned int spellId, PositionData initialPosition);
    void deleteProjectile(unsigned int projectilId);
};

#endif //PROJECTILES_H
