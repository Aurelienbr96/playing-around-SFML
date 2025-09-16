//
// Created by Aurélien Brachet on 15/09/2025.
//

#ifndef SPELL_BOOK_H
#define SPELL_BOOK_H
#include <unordered_map>

#include <string>

#include "sprite-library.h"
#include "../domain/position.h"

struct SpellDef {
    std::string name;
    Sprite::Name spriteName;
    int damage;
    float speed;
    float lifetime;
    Rect rect;
};

class SpellBook {
    std::unordered_map<unsigned int, SpellDef> spells;
    public:
    explicit SpellBook(const std::unordered_map<unsigned int, SpellDef>& spells);


    const SpellDef* get(unsigned int id) const;
};

#endif //SPELL_BOOK_H
