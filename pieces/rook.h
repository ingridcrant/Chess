#include "motion.h"

class Rook : public Motion {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;
};
