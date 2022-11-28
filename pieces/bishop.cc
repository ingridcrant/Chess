#include "bishop.h"

Bishop::Bishop() : dist(INFINITE), specialCapture(false) {
    directions.push_back(LEFT_UP_DIAGONAL);
    directions.push_back(LEFT_DOWN_DIAGONAL);
    directions.push_back(RIGHT_UP_DIAGONAL);
    directions.push_back(RIGHT_DOWN_DIAGONAL);
}

Position Bishop::nextPos(Colour colour, Position currPos, Direction direction) {
    int dx = 1;
    int dy = 1;

    if (colour == BLACK) {
        dx *= -1;
        dy *= -1;
    }
}
