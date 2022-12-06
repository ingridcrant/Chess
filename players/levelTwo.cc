#include "levelTwo.h"
#include "../shared.h"
#include "../pieces/board.h"
#include "../pieces/piece.h"
#include <map>

LevelTwo::LevelTwo(Board * board): Computer(board) {}

Move LevelTwo::chooseMove(Move* lastMove) { 
    if(!lastMove) {
        if (colour == WHITE) return Move{"e2 e4"};
        else return Move{"d7 d5"};
    }
    
    std::vector<std::vector<Piece*>> boardCopy = board->copyBoard();
    std::vector<Position> captureMoves;
    std::vector<Position> normalMoves;
    std::vector<Position> checkMoves;
    std::vector<Piece*> capturePieces;
    std::vector<Piece*> normalPieces;
    std::vector<Piece*> checkPieces;

    Piece* oppositeKing = (colour == BLACK) ? board->getKingWhite() : board->getKingBlack();
    bool currInCheck = oppositeKing->getInCheck();

    for (int r = 0; r < board->getRows(); r++) {
        for (int c = 0; c < board->getCols(); c++) {
            if (boardCopy[r][c] && boardCopy[r][c]->getColour() == colour) {
                oppositeKing->setInCheck(false);
                boardCopy[r][c]->generateNextPositions(boardCopy, board->getRows(), board->getCols(), lastMove);
                for (auto pair : boardCopy[r][c]->getNextPositions()) {
                    if (oppositeKing->getInCheck()) {
                        checkMoves.emplace_back(pair.first);
                        checkPieces.emplace_back(boardCopy[r][c]);
                    } else if (pair.second == CAPTURE) {
                        captureMoves.emplace_back(pair.first);
                        capturePieces.emplace_back(boardCopy[r][c]);
                    } else {
                        normalMoves.emplace_back(pair.first);
                        normalPieces.emplace_back(boardCopy[r][c]);
                    }
                }
                oppositeKing->setInCheck(false);
            }
        }
    }

    oppositeKing->setInCheck(currInCheck);

    if (!checkPieces.empty()) {
        int randMove = rand() % checkMoves.size();
        return Move{checkPieces.at(randMove)->getPos(), checkMoves.at(randMove), checkPieces.at(randMove)};
    } else {
        if (!capturePieces.empty()) {
            int randMove = rand() % captureMoves.size();
            return Move{capturePieces.at(randMove)->getPos(), captureMoves.at(randMove), capturePieces.at(randMove)};
        } else {
            int randMove = rand() % normalMoves.size();
            return Move{normalPieces.at(randMove)->getPos(), normalMoves.at(randMove), normalPieces.at(randMove)};
        }
    }
}


