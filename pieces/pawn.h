#include "piece.h"

class Pawn : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;
    bool skipsTwo;
    
    public:
        Pawn(Colour colour, char symbol, std::shared_ptr<Board> board, Position pos);
        void generateNextPositions() override;
};
