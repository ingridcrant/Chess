#include "bishop.h"

Bishop::Bishop() : dist(INFINITE), specialCapture(false) {
    directions.push_back(LEFT_DIAGONAL);
    directions.push_back(RIGHT_DIAGONAL);
}
