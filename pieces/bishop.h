#include "motion.h"

class Bishop : public Motion {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        Bishop();
        Position nextPos(Colour colour, Position currPos, Direction direction) override;
};
