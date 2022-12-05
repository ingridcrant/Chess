#include "piece.h"

class Pawn : public Piece {
    Distance dist;
    std::vector<Direction> directions;
    bool skipsTwo;
    
    public:
        Pawn(Colour colour, char symbol, Position pos);
        ~Pawn() = default;
        void generateNextPositions(std::vector<std::vector<Piece*>> board, int rows, int cols, Move* lastMove, bool checkIfKingInCheck = true) override;
        bool getSkipsTwo() override;
        void setSkipsTwo(bool val) override;
};
