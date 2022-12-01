#include "piece.h"

class Knight : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        Knight(Colour colour, char symbol, Position pos);
        void generateNextPositions(Board* board) override;
};
