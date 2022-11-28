#include "motion.h"

class Bishop : public Motion {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        Bishop();
};
