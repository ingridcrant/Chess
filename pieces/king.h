#include "motion.h"

class King : public Motion {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;
};
