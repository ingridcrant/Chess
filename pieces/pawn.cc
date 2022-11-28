#include "pawn.h"

Pawn::Pawn() : dist(ONE), specialCapture(true), skipsTwo(false) {
    directions.push_back(UP);
}
