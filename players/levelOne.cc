#include "levelOne.h"
#include "../shared.h"
#include "../pieces/board.h"
#include "../pieces/piece.h"
#include <map>
#include <iostream>


LevelOne::LevelOne(Board * board): Computer{board} {}

Move LevelOne::chooseMove(Move* lastMove) {
    std::vector<std::vector<Piece*>> boardCopy = board->copyBoard();
    std::vector<Position> possibleMoves;
    std::vector<Piece*> pieces;

    for (int r = 0; r < board->getRows(); r++) {
        for (int c = 0; c < board->getCols(); c++) {
            if (board->getPieceAt(r, c) && board->getPieceAt(r, c)->getColour() == colour) {
                board->getPieceAt(r, c)->generateNextPositions(boardCopy, board->getRows(), board->getCols(), lastMove);
                for (auto pair : board->getPieceAt(r, c)->getNextPositions()) {
                    possibleMoves.emplace_back(pair.first);
                    pieces.emplace_back(board->getPieceAt(r, c));
                }
            }
        }
    }

    int randMove = rand() % possibleMoves.size();
    Move newMove = Move{pieces.at(randMove)->getPos(), possibleMoves.at(randMove), pieces.at(randMove)};
    return newMove;
}


