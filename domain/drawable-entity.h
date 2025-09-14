//
// Created by Aurélien Brachet on 14/09/2025.
//

#ifndef DRAWABLE_ENTITY_H
#define DRAWABLE_ENTITY_H
#include "position.h"
#include "renderer.h"

class DrawableEntity {
    protected:
        unsigned int spriteId;
        Position position;
    public:
        DrawableEntity(Position pos, unsigned int spriteId)
            : position(pos), spriteId(spriteId) {}
        void draw(Renderer& renderer);
};

#endif //DRAWABLE_ENTITY_H
