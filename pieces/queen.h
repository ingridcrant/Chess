#include "motion.h"

class Queen : public Motion {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        Queen();
};
