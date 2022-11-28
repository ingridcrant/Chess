#include "motion.h"

class Pawn : public Motion {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        Pawn();
};
