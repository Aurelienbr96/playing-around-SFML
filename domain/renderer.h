//
// Created by Aurélien Brachet on 14/09/2025.
//

#ifndef RENDERER_H
#define RENDERER_H
#include "position.h"

class Renderer {
    public:
    virtual ~Renderer() = default;

    virtual void render(PositionData pos, unsigned int spriteId) = 0;
};

#endif //RENDERER_H
