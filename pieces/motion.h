#include <string>
#include <vector>

enum Direction { UP, DOWN, LEFT, RIGHT, LEFT_UP_DIAGONAL, LEFT_DOWN_DIAGONAL, RIGHT_UP_DIAGONAL, RIGHT_DOWN_DIAGONAL, KNIGHT_UP_LEFT, KNIGHT_UP_RIGHT, KNIGHT_DOWN_LEFT, KNIGHT_DOWN_RIGHT };
enum Distance { ONE, INFINITE };

class Motion {
    virtual int* nextPos(int* currPos, Direction direction) = 0;
};
