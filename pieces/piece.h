#include <string>
#include <vector>

class Motion;

class Piece {
    std::string colour;
    char symbol;
    Motion* motion;
    int* currPos;
    int* newPos;
    bool firstMove;

    std::vector<int*> validMoves();
};
