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
    std::vector<std::unique_ptr<Piece>> rowOne;
    rowOne.push_back(std::move(whitePawnOne));
    rowOne.push_back(std::move(whitePawnTwo));
    rowOne.push_back(std::move(whitePawnThree));
    rowOne.push_back(std::move(whitePawnFour));
    rowOne.push_back(std::move(whitePawnFive));
    rowOne.push_back(std::move(whitePawnSix));
    rowOne.push_back(std::move(whitePawnSev));
    rowOne.push_back(std::move(whitePawnEight));

    std::vector<std::unique_ptr<Piece>> rowTwo;
    rowTwo.push_back(std::move(whiteRookOne));
    rowTwo.push_back(std::move(whiteKnightOne));
    rowTwo.push_back(std::move(whiteBishopOne));
    rowTwo.push_back(std::move(whiteQueen));
    rowTwo.push_back(std::move(whiteKing));
    rowTwo.push_back(std::move(whiteBishopTwo));
    rowTwo.push_back(std::move(whiteKnightTwo));
    rowTwo.push_back(std::move(whiteRookTwo));
    
    std::vector<std::unique_ptr<Piece>> rowThree{};
    rowThree.push_back(nullptr);
    rowThree.push_back(nullptr);
    rowThree.push_back(nullptr);
    rowThree.push_back(nullptr);
    rowThree.push_back(nullptr);
    rowThree.push_back(nullptr);
    rowThree.push_back(nullptr);
    rowThree.push_back(nullptr);

    std::vector<std::unique_ptr<Piece>> rowFour;
    rowFour.push_back(nullptr);
    rowFour.push_back(nullptr);
    rowFour.push_back(nullptr);
    rowFour.push_back(nullptr);
    rowFour.push_back(nullptr);
    rowFour.push_back(nullptr);
    rowFour.push_back(nullptr);
    rowFour.push_back(nullptr);

    std::vector<std::unique_ptr<Piece>> rowFive;
    rowFive.push_back(nullptr);
    rowFive.push_back(nullptr);
    rowFive.push_back(nullptr);
    rowFive.push_back(nullptr);
    rowFive.push_back(nullptr);
    rowFive.push_back(nullptr);
    rowFive.push_back(nullptr);
    rowFive.push_back(nullptr);

    std::vector<std::unique_ptr<Piece>> rowSix;
    rowSix.push_back(nullptr);
    rowSix.push_back(nullptr);
    rowSix.push_back(nullptr);
    rowSix.push_back(nullptr);
    rowSix.push_back(nullptr);
    rowSix.push_back(nullptr);
    rowSix.push_back(nullptr);
    rowSix.push_back(nullptr);

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
}

Board::~Board() {}

int Board::getRows() {return boardRows;}

int Board::getCols() {return boardCols;}

Piece * Board::getPieceAt(int col, int row) const {
    return board[col][row].get();
}

bool Board::validMove(Piece * piece, Position curPos, Position newPos) const {
    return true;
}

void Board::changeBoard(Move move) {
    Position curPos = move.getCurPos();
    Position newPos = move.getNewPos();
    Piece * piece = board[curPos.col][curPos.row].get();

    if (Board::validMove(piece, curPos, newPos)) {
        //change state of board
        board[newPos.col][newPos.row] = std::move(board[curPos.col][curPos.row]); //memory leak??
    } else {
        throw InvalidMove{};
    }

}

//TODO:
void Board::changeBoard(Position pos) {
    board[pos.col][pos.row] = std::move(nullptr); //memory leak??
}

//TODO:
void Board::changeBoard(char piece, Position pos) {
    
}





/*void test() {
    Board board{};

    for(int i = 0; i < board.getCols(); i++) {
        for (int j = 0; j < board.getRows(); j++) {
            if(board.getPieceAt(i, j)) {
                std::cout << board.getPieceAt(i, j)->symbol;
            } else {
                std::cout << "N ";
            }
        }
        std::cout << std::endl;
    }
}*/


