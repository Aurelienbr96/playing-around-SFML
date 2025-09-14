//
// Created by Aurélien Brachet on 08/09/2025.
//

#ifndef POSITION_H
#define POSITION_H

struct PositionData {
    float x;
    float y;
};

class Position {
    float x;
    float y;
    public:
    Position(float x, float y);
    PositionData getPosition();
    void setPosition(PositionData pos);
};

#endif //POSITION_H