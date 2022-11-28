#include "knight.h"

Knight::Knight() : dist(ONE), specialCapture(false) {
    directions.push_back(KNIGHT_DOWN_LEFT);
    directions.push_back(KNIGHT_DOWN_RIGHT);
    directions.push_back(KNIGHT_UP_LEFT);
    directions.push_back(KNIGHT_UP_RIGHT);
}
