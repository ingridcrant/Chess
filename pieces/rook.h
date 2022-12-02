#include "piece.h"

class Rook : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        Rook(Colour colour, char symbol, Position pos);
        ~Rook() = default;
        void generateNextPositions(Board* board) override;
};
