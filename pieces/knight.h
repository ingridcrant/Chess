#include "piece.h"

class Knight : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        Knight(Colour colour, char symbol, std::shared_ptr<Board> board, Position pos);
        void generateNextPositions() override;
};
