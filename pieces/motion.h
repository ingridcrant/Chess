#include <string>
#include <vector>

enum motion { UP, DOWN, LEFT, RIGHT, LEFT_DIAGONAL, RIGHT_DIAGOONAL };
enum distance { ONE, INFINITE };

class Motion {
    distance dist;
    std::vector<motion> directions;
    bool specialCapture;

    int* nextPos(int* currPos, std::string direction);
};
