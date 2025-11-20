//
// Created by Aurélien Brachet on 19/11/2025.
//

#ifndef LEVEL1_H
#define LEVEL1_H
#include "level.h"


class Level1: public Level {
public:
    Level1();

    // In Level1.h
    std::vector<std::vector<unsigned int>> &getLevel() override;
private:
    std::vector<std::vector<unsigned int>> levels;
};



#endif //LEVEL1_H
