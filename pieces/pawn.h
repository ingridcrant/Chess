#include "piece.h"

class Pawn : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;
    bool skipsTwo;
    
    public:
        Pawn(Colour colour, char symbol, Position pos);
        void generateNextPositions(Board* board) override;
        bool getSkipsTwo() override;
};
