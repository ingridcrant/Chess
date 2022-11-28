#include "rook.h"

Rook::Rook() : dist(INFINITE), specialCapture(false) {
    directions.push_back(UP);
    directions.push_back(DOWN);
    directions.push_back(LEFT);
    directions.push_back(RIGHT);
}
