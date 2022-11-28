#include <string>
#include <vector>
#include "../shared.h"

class Motion {
    virtual Position nextPos(Colour colour, Position currPos, Direction direction) = 0;
};
