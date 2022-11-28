#include "queen.h"

Queen::Queen() : dist(INFINITE), specialCapture(false) {
    directions.push_back(UP);
    directions.push_back(DOWN);
    directions.push_back(LEFT);
    directions.push_back(RIGHT);
    directions.push_back(LEFT_DIAGONAL);
    directions.push_back(RIGHT_DIAGONAL);
}
