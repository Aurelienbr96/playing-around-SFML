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

        PositionData getPosition() const;
        Rect getSize() const;
};

#endif //DRAWABLE_ENTITY_H
