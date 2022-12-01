#include "piece.h"

class King : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        King(Colour colour, char symbol, std::shared_ptr<Board> board, Position pos);
        void generateNextPositions() override;
};
