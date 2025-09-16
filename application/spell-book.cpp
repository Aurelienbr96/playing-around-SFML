//
// Created by Aurélien Brachet on 15/09/2025.
//

#include "spell-book.h"

#include <iostream>


SpellBook::SpellBook(const std::unordered_map<unsigned int, SpellDef>& spells): spells(spells) {}

const SpellDef* SpellBook::get(unsigned int id) const {
    auto it = this->spells.find(id);
    if (it != this->spells.end()) {
        return  &it->second;
    }
    return nullptr;
}
