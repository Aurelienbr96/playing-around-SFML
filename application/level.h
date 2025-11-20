//
// Created by Aurélien Brachet on 19/11/2025.
//

#ifndef LEVEL_H
#define LEVEL_H
#include <vector>

class Level {
public:
  virtual ~Level() = default;
  virtual std::vector<std::vector<unsigned int>> &getLevel() = 0;
};

#endif //LEVEL_H
