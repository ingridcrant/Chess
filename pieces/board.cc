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
    auto whitePawnOne = std::make_shared<Pawn>(WHITE, 'P', this->shared_from_this(), Position{1, 0});
    auto whitePawnTwo = std::make_shared<Pawn>(WHITE, 'P', this->shared_from_this(), Position{1, 1});
    auto whitePawnThree = std::make_shared<Pawn>(WHITE, 'P', this->shared_from_this(), Position{1, 2});
    auto whitePawnFour = std::make_shared<Pawn>(WHITE, 'P', this->shared_from_this(), Position{1, 3});
    auto whitePawnFive = std::make_shared<Pawn>(WHITE, 'P', this->shared_from_this(), Position{1, 4});
    auto whitePawnSix = std::make_shared<Pawn>(WHITE, 'P', this->shared_from_this(), Position{1, 5});
    auto whitePawnSev = std::make_shared<Pawn>(WHITE, 'P', this->shared_from_this(), Position{1, 6});
    auto whitePawnEight = std::make_shared<Pawn>(WHITE, 'P', this->shared_from_this(), Position{1, 7});
    auto whiteKing = std::make_shared<King>(WHITE, 'K', this->shared_from_this(), Position{0, 4});
    auto whiteQueen = std::make_shared<Queen>(WHITE, 'Q', this->shared_from_this(), Position{0, 3});
    auto whiteRookOne = std::make_shared<Rook>(WHITE, 'R', this->shared_from_this(), Position{0, 0});
    auto whiteRookTwo = std::make_shared<Rook>(WHITE, 'R', this->shared_from_this(), Position{0, 7});
    auto whiteBishopOne = std::make_shared<Bishop>(WHITE, 'B', this->shared_from_this(), Position{0, 2});
    auto whiteBishopTwo = std::make_shared<Bishop>(WHITE, 'B', this->shared_from_this(), Position{0, 5});
    auto whiteKnightOne = std::make_shared<Knight>(WHITE, 'N', this->shared_from_this(), Position{0, 1});
    auto whiteKnightTwo = std::make_shared<Knight>(WHITE, 'N', this->shared_from_this(), Position{0, 6});

    auto blackPawnOne = std::make_shared<Pawn>(BLACK, 'p', this->shared_from_this(), Position{6, 0});
    auto blackPawnTwo = std::make_shared<Pawn>(BLACK, 'p', this->shared_from_this(), Position{6, 1});
    auto blackPawnThree = std::make_shared<Pawn>(BLACK, 'p', this->shared_from_this(), Position{6, 2});
    auto blackPawnFour = std::make_shared<Pawn>(BLACK, 'p', this->shared_from_this(), Position{6, 3});
    auto blackPawnFive = std::make_shared<Pawn>(BLACK, 'p', this->shared_from_this(), Position{6, 4});
    auto blackPawnSix = std::make_shared<Pawn>(BLACK, 'p', this->shared_from_this(), Position{6, 5});
    auto blackPawnSev = std::make_shared<Pawn>(BLACK, 'p', this->shared_from_this(), Position{6, 6});
    auto blackPawnEight = std::make_shared<Pawn>(BLACK, 'p', this->shared_from_this(), Position{6, 7});
    auto blackKing = std::make_shared<King>(BLACK, 'k', this->shared_from_this(), Position{7, 4});
    auto blackQueen = std::make_shared<Queen>(BLACK, 'q', this->shared_from_this(), Position{7, 3});
    auto blackRookOne = std::make_shared<Rook>(BLACK, 'r', this->shared_from_this(), Position{7, 0});
    auto blackRookTwo = std::make_shared<Rook>(BLACK, 'r', this->shared_from_this(), Position{7, 7});
    auto blackBishopOne = std::make_shared<Bishop>(BLACK, 'b', this->shared_from_this(), Position{7, 2});
    auto blackBishopTwo = std::make_shared<Bishop>(BLACK, 'b', this->shared_from_this(), Position{7, 5});
    auto blackKnightOne = std::make_shared<Knight>(BLACK, 'n', this->shared_from_this(), Position{7, 1});
    auto blackKnightTwo = std::make_shared<Knight>(BLACK, 'n', this->shared_from_this(), Position{7, 6});


    //add all pieces to the board rows
    std::vector<std::shared_ptr<Piece>> rowOne{whitePawnOne, whitePawnTwo, 
                                               whitePawnThree, whitePawnFour, 
                                               whitePawnFive, whitePawnSix, 
                                               whitePawnSev, whitePawnEight};
    std::vector<std::shared_ptr<Piece>> rowTwo{whiteRookOne, whiteKnightOne, 
                                               whiteBishopOne, whiteQueen, 
                                               whiteKing, whiteBishopTwo, 
                                               whiteKnightTwo, whiteRookTwo};
    std::vector<std::shared_ptr<Piece>> rowThree{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    std::vector<std::shared_ptr<Piece>> rowFour{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    std::vector<std::shared_ptr<Piece>> rowFive{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    std::vector<std::shared_ptr<Piece>> rowSix{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    std::vector<std::shared_ptr<Piece>> rowSev{blackPawnOne, blackPawnTwo, 
                                               blackPawnThree, blackPawnFour, 
                                               blackPawnFive, blackPawnSix, 
                                               blackPawnSev, blackPawnEight};

    std::vector<std::shared_ptr<Piece>> rowEight{blackRookOne, blackKnightOne, 
                                               blackBishopOne, blackQueen, 
                                               blackKing, blackBishopTwo, 
                                               blackKnightTwo, blackRookTwo};

    //add all rows to board
    board.push_back(rowOne);
    board.push_back(rowTwo);
    board.push_back(rowThree);
    board.push_back(rowFour);
    board.push_back(rowFive);
    board.push_back(rowSix);
    board.push_back(rowSev);
    board.push_back(rowEight);
}


std::vector<std::vector<std::shared_ptr<Piece>>> Board::getBoard() const {return board;}


