#include "piece.h"

class Knight : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        Knight(Colour colour, char symbol, Position pos);
        ~Knight() = default;
        void generateNextPositions(std::vector<std::vector<Piece*>> board, int rows, int cols, Move* lastMove, bool checkIfKingInCheck = true) override;
};
