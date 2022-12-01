#include "piece.h"

class Queen : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        Queen(Colour colour, char symbol, Position pos);
        void generateNextPositions(Board* board) override;
};
