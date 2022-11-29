#include "board.h"
#include "piece.h"
#include <vector>
#include <memory>
#include "../shared.h"

Board::Board() {
    // create all the piece pointers
    auto whitePawnOne = std::make_shared<Piece>();
    auto whitePawnTwo = std::make_shared<Piece>();
    auto whitePawnThree = std::make_shared<Piece>();
    auto whitePawnFour = std::make_shared<Piece>();
    auto whitePawnFive = std::make_shared<Piece>();
    auto whitePawnSix = std::make_shared<Piece>();
    auto whitePawnSev = std::make_shared<Piece>();
    auto whitePawnEight = std::make_shared<Piece>();
    auto whiteKing = std::make_shared<Piece>();
    auto whiteQueen = std::make_shared<Piece>();
    auto whiteRookOne = std::make_shared<Piece>();
    auto whiteRookTwo = std::make_shared<Piece>();
    auto whiteBishopOne = std::make_shared<Piece>();
    auto whiteBishopTwo = std::make_shared<Piece>();
    auto whiteKnightOne = std::make_shared<Piece>();
    auto whiteKnightTwo = std::make_shared<Piece>();

    auto blackPawnOne = std::make_shared<Piece>();
    auto blackPawnTwo = std::make_shared<Piece>();
    auto blackPawnThree = std::make_shared<Piece>();
    auto blackPawnFour = std::make_shared<Piece>();
    auto blackPawnFive = std::make_shared<Piece>();
    auto blackPawnSix = std::make_shared<Piece>();
    auto blackPawnSev = std::make_shared<Piece>();
    auto blackPawnEight = std::make_shared<Piece>();
    auto blackKing = std::make_shared<Piece>();
    auto blackQueen = std::make_shared<Piece>();
    auto blackRookOne = std::make_shared<Piece>();
    auto blackRookTwo = std::make_shared<Piece>();
    auto blackBishopOne = std::make_shared<Piece>();
    auto blackBishopTwo = std::make_shared<Piece>();
    auto blackKnightOne = std::make_shared<Piece>();
    auto blackKnightTwo = std::make_shared<Piece>();


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


