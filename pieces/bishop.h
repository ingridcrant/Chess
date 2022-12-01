#include "piece.h"

class Bishop : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        Bishop(Colour colour, char symbol, Position pos);
        void generateNextPositions(Board* board) override;
};
