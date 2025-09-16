//
// Created by Aurélien Brachet on 14/09/2025.
//

#ifndef DRAWABLE_ENTITY_H
#define DRAWABLE_ENTITY_H
#include "position.h"
#include "renderer.h"

class DrawableEntity {
    protected:
        Sprite::Name spriteName;
        Position position;
    public:
        DrawableEntity(Position pos, Sprite::Name spriteName)
            : position(pos), spriteName(spriteName) {}
        void draw(Renderer& renderer);
};

#endif //DRAWABLE_ENTITY_H
