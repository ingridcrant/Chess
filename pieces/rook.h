#include "piece.h"

class Rook : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        Rook(Colour colour, char symbol, std::shared_ptr<Board> board, Position pos);
        void generateNextPositions() override;
};
