#include "motion.h"

class Knight : public Motion {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;
};
