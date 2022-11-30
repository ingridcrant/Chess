#include "piece.h"

class Bishop : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        Bishop(Colour colour, char symbol, std::shared_ptr<Board> board, Position pos);
        void generateNextPositions() override;
};
