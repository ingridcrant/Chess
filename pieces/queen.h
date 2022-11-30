#include "piece.h"

class Queen : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        Queen(Colour colour, char symbol, std::shared_ptr<Board> board, Position pos);
        void generateNextPositions() override;
};
