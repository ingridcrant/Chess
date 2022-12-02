#include "piece.h"

class King : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;
    bool inCheck;
    bool positionInCheck(Board* board, Position pos);

    public:
        King(Colour colour, char symbol, Position pos);
        ~King() = default;
        void generateNextPositions(Board* board) override;
};
