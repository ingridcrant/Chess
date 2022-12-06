#include "board.h"
#include "piece.h"
#include <vector>
#include <memory>
#include "../shared.h"
#include "pawn.h"
#include "king.h"
#include "bishop.h"
#include "rook.h"
#include "queen.h"
#include "knight.h"
#include <iostream>

Board::Board() {
    // create all the piece pointers
    auto whitePawnOne = std::make_unique<Pawn>(WHITE, 'P', Position{1, 0});
    auto whitePawnTwo = std::make_unique<Pawn>(WHITE, 'P', Position{1, 1});
    auto whitePawnThree = std::make_unique<Pawn>(WHITE, 'P', Position{1, 2});
    auto whitePawnFour = std::make_unique<Pawn>(WHITE, 'P', Position{1, 3});
    auto whitePawnFive = std::make_unique<Pawn>(WHITE, 'P', Position{1, 4});
    auto whitePawnSix = std::make_unique<Pawn>(WHITE, 'P', Position{1, 5});
    auto whitePawnSev = std::make_unique<Pawn>(WHITE, 'P', Position{1, 6});
    auto whitePawnEight = std::make_unique<Pawn>(WHITE, 'P', Position{1, 7});
    auto whiteKing = std::make_unique<King>(WHITE, 'K', Position{0, 4});
    auto whiteQueen = std::make_unique<Queen>(WHITE, 'Q', Position{0, 3});
    auto whiteRookOne = std::make_unique<Rook>(WHITE, 'R', Position{0, 0});
    auto whiteRookTwo = std::make_unique<Rook>(WHITE, 'R', Position{0, 7});
    auto whiteBishopOne = std::make_unique<Bishop>(WHITE, 'B', Position{0, 2});
    auto whiteBishopTwo = std::make_unique<Bishop>(WHITE, 'B', Position{0, 5});
    auto whiteKnightOne = std::make_unique<Knight>(WHITE, 'N', Position{0, 1});
    auto whiteKnightTwo = std::make_unique<Knight>(WHITE, 'N', Position{0, 6});

    auto blackPawnOne = std::make_unique<Pawn>(BLACK, 'p', Position{6, 0});
    auto blackPawnTwo = std::make_unique<Pawn>(BLACK, 'p', Position{6, 1});
    auto blackPawnThree = std::make_unique<Pawn>(BLACK, 'p', Position{6, 2});
    auto blackPawnFour = std::make_unique<Pawn>(BLACK, 'p', Position{6, 3});
    auto blackPawnFive = std::make_unique<Pawn>(BLACK, 'p', Position{6, 4});
    auto blackPawnSix = std::make_unique<Pawn>(BLACK, 'p', Position{6, 5});
    auto blackPawnSev = std::make_unique<Pawn>(BLACK, 'p', Position{6, 6});
    auto blackPawnEight = std::make_unique<Pawn>(BLACK, 'p', Position{6, 7});
    auto blackKing = std::make_unique<King>(BLACK, 'k', Position{7, 4});
    auto blackQueen = std::make_unique<Queen>(BLACK, 'q', Position{7, 3});
    auto blackRookOne = std::make_unique<Rook>(BLACK, 'r', Position{7, 0});
    auto blackRookTwo = std::make_unique<Rook>(BLACK, 'r', Position{7, 7});
    auto blackBishopOne = std::make_unique<Bishop>(BLACK, 'b', Position{7, 2});
    auto blackBishopTwo = std::make_unique<Bishop>(BLACK, 'b', Position{7, 5});
    auto blackKnightOne = std::make_unique<Knight>(BLACK, 'n', Position{7, 1});
    auto blackKnightTwo = std::make_unique<Knight>(BLACK, 'n', Position{7, 6});


    //add all pieces to the board rows
    std::vector<std::unique_ptr<Piece>> rowTwo;
    rowTwo.push_back(std::move(whitePawnOne));
    rowTwo.push_back(std::move(whitePawnTwo));
    rowTwo.push_back(std::move(whitePawnThree));
    rowTwo.push_back(std::move(whitePawnFour));
    rowTwo.push_back(std::move(whitePawnFive));
    rowTwo.push_back(std::move(whitePawnSix));
    rowTwo.push_back(std::move(whitePawnSev));
    rowTwo.push_back(std::move(whitePawnEight));

    std::vector<std::unique_ptr<Piece>> rowOne;
    rowOne.push_back(std::move(whiteRookOne));
    rowOne.push_back(std::move(whiteKnightOne));
    rowOne.push_back(std::move(whiteBishopOne));
    rowOne.push_back(std::move(whiteQueen));
    rowOne.push_back(std::move(whiteKing));
    rowOne.push_back(std::move(whiteBishopTwo));
    rowOne.push_back(std::move(whiteKnightTwo));
    rowOne.push_back(std::move(whiteRookTwo));
    
    std::vector<std::unique_ptr<Piece>> rowThree{};
    rowThree.push_back(std::move(nullptr));
    rowThree.push_back(std::move(nullptr));
    rowThree.push_back(std::move(nullptr));
    rowThree.push_back(std::move(nullptr));
    rowThree.push_back(std::move(nullptr));
    rowThree.push_back(std::move(nullptr));
    rowThree.push_back(std::move(nullptr));
    rowThree.push_back(std::move(nullptr));

    std::vector<std::unique_ptr<Piece>> rowFour;
    rowFour.push_back(std::move(nullptr));
    rowFour.push_back(std::move(nullptr));
    rowFour.push_back(std::move(nullptr));
    rowFour.push_back(std::move(nullptr));
    rowFour.push_back(std::move(nullptr));
    rowFour.push_back(std::move(nullptr));
    rowFour.push_back(std::move(nullptr));
    rowFour.push_back(std::move(nullptr));

    std::vector<std::unique_ptr<Piece>> rowFive;
    rowFive.push_back(std::move(nullptr));
    rowFive.push_back(std::move(nullptr));
    rowFive.push_back(std::move(nullptr));
    rowFive.push_back(std::move(nullptr));
    rowFive.push_back(std::move(nullptr));
    rowFive.push_back(std::move(nullptr));
    rowFive.push_back(std::move(nullptr));
    rowFive.push_back(std::move(nullptr));

    std::vector<std::unique_ptr<Piece>> rowSix;
    rowSix.push_back(std::move(nullptr));
    rowSix.push_back(std::move(nullptr));
    rowSix.push_back(std::move(nullptr));
    rowSix.push_back(std::move(nullptr));
    rowSix.push_back(std::move(nullptr));
    rowSix.push_back(std::move(nullptr));
    rowSix.push_back(std::move(nullptr));
    rowSix.push_back(std::move(nullptr));

    std::vector<std::unique_ptr<Piece>> rowSev;
    rowSev.push_back(std::move(blackPawnOne));
    rowSev.push_back(std::move(blackPawnTwo));
    rowSev.push_back(std::move(blackPawnThree));
    rowSev.push_back(std::move(blackPawnFour));
    rowSev.push_back(std::move(blackPawnFive));
    rowSev.push_back(std::move(blackPawnSix));
    rowSev.push_back(std::move(blackPawnSev));
    rowSev.push_back(std::move(blackPawnEight));

    std::vector<std::unique_ptr<Piece>> rowEight;
    rowEight.push_back(std::move(blackRookOne));
    rowEight.push_back(std::move(blackKnightOne));
    rowEight.push_back(std::move(blackBishopOne));
    rowEight.push_back(std::move(blackQueen));
    rowEight.push_back(std::move(blackKing));
    rowEight.push_back(std::move(blackBishopTwo));
    rowEight.push_back(std::move(blackKnightTwo));
    rowEight.push_back(std::move(blackRookTwo));

    //add all rows to board
    board.push_back(std::move(rowOne)); 
    board.push_back(std::move(rowTwo));
    board.push_back(std::move(rowThree));
    board.push_back(std::move(rowFour));
    board.push_back(std::move(rowFive));
    board.push_back(std::move(rowSix));
    board.push_back(std::move(rowSev));
    board.push_back(std::move(rowEight));

    kingWhite = board[0][4].get();
    kingBlack = board[7][4].get();
}

int Board::getRows() {return boardRows;}

int Board::getCols() {return boardCols;}

Piece* Board::getKingWhite() {return kingWhite;}

Piece* Board::getKingBlack() {return kingBlack;}

Piece * Board::getPieceAt(int row, int col) const {
    if (board[row][col]) {
        return board[row][col].get();
    }
    return nullptr;
}


void Board::resetBoard() {
    Board newBoard{};

    for (int row = 0; row < boardRows; row++) {
        for (int col = 0; col < boardCols; col++) {
            board[row][col] = std::move(newBoard.board[row][col]);
        }
    }
    
}


void Board::updateKingPointer(Position pos) {
    if (board[pos.row][pos.col]->getSymbol() == 'k') {
        kingBlack = board[pos.row][pos.col].get();
    }
    else if (board[pos.row][pos.col]->getSymbol() == 'K') {
        kingWhite = board[pos.row][pos.col].get();
    }
}

void Board::changeBoard(Position pos) {
    board[pos.row][pos.col] = std::move(nullptr);
}


void Board::changeBoard(char piece, Position pos) {
    bool done = false;

    for (int col = boardCols - 1; col >= 0; col--) {
        for (int row = 0; row < boardRows; row++) {
            if (board[row][col] && board[row][col]->getSymbol() == piece) {
                board[pos.row][pos.col] = std::move(board[row][col]);
                board[pos.row][pos.col].get()->setPos(Position{pos.row, pos.col});
                done = true;

                //if king was moved, update king pointer
                Board::updateKingPointer(pos);
                break;
            }
        }
        if (done) break;
    }
}

void Board::changeBoard(Move move, Move* lastMove) {
    Position curPos = move.getCurPos();
    Position newPos = move.getNewPos();

    Piece * piece = board[curPos.row][curPos.col].get();

    if (Board::validMove(piece, lastMove, curPos, newPos)) {
        // change state of board based on MoveTypes
        // MOVE, CAPTURE, SKIP_TWO, EN_PASSANT, CASTLE_LEFT, CASTLE_RIGHT
        MoveTypes moveType = piece->getNextPositions()[newPos];

        if (moveType == MOVE || moveType == CAPTURE) {
            board[newPos.row][newPos.col] = std::move(board[curPos.row][curPos.col]);
        } else if (moveType == SKIP_TWO) {
            board[newPos.row][newPos.col] = std::move(board[curPos.row][curPos.col]);
            piece->setSkipsTwo(true);
        } else if (moveType == EN_PASSANT) {
            // eliminate avoided piece
            int dRow = (piece->getColour() == BLACK) ? -1 : 1;
            board[newPos.row][newPos.col] = std::move(board[curPos.row][curPos.col]);
            board[newPos.row - dRow][newPos.col] = std::move(nullptr);
        } else if (moveType == CASTLE_LEFT) {
            board[newPos.row][2] = std::move(board[newPos.row][4]);
            board[newPos.row][0] = std::move(board[newPos.row][3]);
        } else {
            board[newPos.row][6] = std::move(board[newPos.row][4]);
            board[newPos.row][5] = std::move(board[newPos.row][7]);
        }

        if (move.getPromotion()) {
            if (piece->getColour() == BLACK) {
                if (newPos.row == 0)  {
                    if (move.getPromoteTo() == 'r') {
                        piece->setDirections({UP, DOWN, LEFT, RIGHT});
                        piece->setDistance(INFINITE);
                    } else if (move.getPromoteTo() == 'n') {
                        piece->setDirections({KNIGHT_DOWN_LEFT, KNIGHT_DOWN_RIGHT, KNIGHT_LEFT_DOWN, KNIGHT_LEFT_UP, KNIGHT_RIGHT_DOWN, KNIGHT_RIGHT_UP, KNIGHT_UP_LEFT, KNIGHT_UP_RIGHT});
                        piece->setDistance(INFINITE);
                    } else if (move.getPromoteTo() == 'b') {
                        piece->setDirections({LEFT_UP_DIAGONAL, LEFT_DOWN_DIAGONAL, RIGHT_UP_DIAGONAL, RIGHT_DOWN_DIAGONAL});
                        piece->setDistance(INFINITE);
                    } else if (move.getPromoteTo() == 'q') {
                        piece->setDirections({UP, DOWN, LEFT, RIGHT, LEFT_UP_DIAGONAL, LEFT_DOWN_DIAGONAL, RIGHT_UP_DIAGONAL, RIGHT_DOWN_DIAGONAL});
                        piece->setDistance(INFINITE);
                    } else {
                        throw InvalidInput{"Invalid promotion piece"};
                    }
                } else {
                    throw InvalidMove{};
                }
            } else {
                if (newPos.row == getRows() - 1)  {
                    if (move.getPromoteTo() == 'R') {
                        piece->setDirections({UP, DOWN, LEFT, RIGHT});
                        piece->setDistance(INFINITE);
                    } else if (move.getPromoteTo() == 'N') {
                        piece->setDirections({KNIGHT_DOWN_LEFT, KNIGHT_DOWN_RIGHT, KNIGHT_LEFT_DOWN, KNIGHT_LEFT_UP, KNIGHT_RIGHT_DOWN, KNIGHT_RIGHT_UP, KNIGHT_UP_LEFT, KNIGHT_UP_RIGHT});
                        piece->setDistance(INFINITE);
                    } else if (move.getPromoteTo() == 'B') {
                        piece->setDirections({LEFT_UP_DIAGONAL, LEFT_DOWN_DIAGONAL, RIGHT_UP_DIAGONAL, RIGHT_DOWN_DIAGONAL});
                        piece->setDistance(INFINITE);
                    } else if (move.getPromoteTo() == 'Q') {
                        piece->setDirections({UP, DOWN, LEFT, RIGHT, LEFT_UP_DIAGONAL, LEFT_DOWN_DIAGONAL, RIGHT_UP_DIAGONAL, RIGHT_DOWN_DIAGONAL});
                        piece->setDistance(INFINITE);
                    } else {
                        throw InvalidInput{"Invalid promotion piece"};
                    }
                } else {
                    throw InvalidMove{};
                }
            }
        }

        piece->notFirstMove();
        piece->setPos(newPos);

        //if king was moved, update king pointer
        Board::updateKingPointer(newPos);
    } else {
        throw InvalidMove{};
    }
}

std::vector<std::vector<Piece*>> Board::copyBoard() {
    std::vector<std::vector<Piece*>> boardCopy;
    for (int r = 0; r < getRows(); r++) {
        std::vector<Piece*> row;
        for (int c = 0; c < getCols(); c++) {
            row.push_back(getPieceAt(r, c));
        }
        boardCopy.push_back(std::move(row));
    }

    return boardCopy;
}

//TODO: Test
bool Board::boardInCheck(Colour colour) const {
    if (colour == WHITE && kingWhite->getInCheck()) {
        return true;
    }
    else if (colour == BLACK && kingBlack->getInCheck()) {
        return true;
    }

    return false;
}


//TODO: FIX CURRENTLY WRONG
bool Board::boardInCheckmate(Colour colour) const {
    if (colour == WHITE && kingWhite->getInCheck() && kingWhite->getNextPositions().empty()) {
        return true;
    }
    else if (colour == BLACK && kingBlack->getInCheck() && kingBlack->getNextPositions().empty()) {
        return true;
    }

    return false;
}

bool Board::validMove(Piece* piece, Move* lastMove, Position curPos, Position newPos) {
    std::vector<std::vector<Piece*>> boardCopy = copyBoard();

    // call generateAllMoves with a board copy
    if (boardCopy[curPos.row][curPos.col]) {
        piece->generateNextPositions(boardCopy, boardRows, boardCols, lastMove, true);
        for (auto nextPos : piece->getNextPositions()) {
            if (nextPos.first.row == newPos.row && nextPos.first.col == newPos.col) {
                return true;
            }
        }
    }
    return false;
}


//TODO: Implement
bool Board::boardInStalemate(Colour colour) const {
    //must check that both sides have no possible moves
    if (colour == WHITE) {
        for (int r = 0; r < boardRows; r++) {
            for (int c = 0; c < boardCols; c++) {
                if (getPieceAt(r, c) && getPieceAt(r, c)->getColour() == WHITE && !getPieceAt(r, c)->getNextPositions().empty()) {
                    return false;
                }
            }
        }
        return true;
    } else {
        for (int r = 0; r < boardRows; r++) {
            for (int c = 0; c < boardCols; c++) {
                if (getPieceAt(r, c) && getPieceAt(r, c)->getColour() == BLACK && !getPieceAt(r, c)->getNextPositions().empty()) {
                    return false;
                }
            }
        }
        return true;
    }
}


/*void test() {
    Board board{};

    for(int i = board.getRows() - 1; i >= 0; i--) {
        for (int j = 0; j < board.getCols(); j++) {
            if(board.getPieceAt(i, j)) {
                std::cout << board.getPieceAt(i, j)->getSymbol();
            } else {
                std::cout << "-";
            }
        }
        std::cout << std::endl;
    }

    board.changeBoard('k', Position{3, 5});
    std::cout << std::endl;

    for(int i = board.getRows() - 1; i >= 0; i--) {
        for (int j = 0; j < board.getCols(); j++) {
            if(board.getPieceAt(i, j)) {
                std::cout << board.getPieceAt(i, j)->getSymbol();
            } else {
                std::cout << "-";
            }
        }
        std::cout << std::endl;
    }
}*/


