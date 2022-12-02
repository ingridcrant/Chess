#include "piece.h"

class Queen : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        Queen(Colour colour, char symbol, Position pos);
        ~Queen() = default;
        void generateNextPositions(Board* board, Move lastMove) override;
};
