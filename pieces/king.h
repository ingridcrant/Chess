#include "piece.h"

class King : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        King(Colour colour, char symbol, Position pos);
        void generateNextPositions(Board* board) override;
};
