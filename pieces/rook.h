#include "piece.h"

class Rook : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        Rook(Colour colour, char symbol, Position pos);
        ~Rook() = default;
        void generateNextPositions(std::vector<std::vector<Piece*>> board, int rows, int cols, Move* lastMove, bool checkIfKingInCheck = true) override;
};
