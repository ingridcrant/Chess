#include "piece.h"

class Board;

class Queen : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool specialCapture;

    public:
        Queen(Colour colour, char symbol, Position pos);
        ~Queen() = default;
        void generateNextPositions(std::vector<std::vector<Piece*>> board, int rows, int cols, Move* lastMove, bool checkIfKingInCheck = true) override;
};
