//
// Created by Aurélien Brachet on 08/09/2025.
//

#ifndef POSITION_H
#define POSITION_H


struct PositionData {
    float x;
    float y;
};

struct Rect {
    unsigned int height;
    unsigned int width;
};

class Position {
    float x;
    float y;
    unsigned int width;
    unsigned int height;
    public:
    Position(float x, float y, unsigned int width, unsigned int height);

    PositionData getPosition();
    void setPosition(PositionData pos);
    void updatePosition(PositionData pos);
};

#endif //POSITION_H