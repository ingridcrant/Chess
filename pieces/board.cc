#include "board.h"
#include "piece.h"
#include <vector>
#include <memory>
#include "../shared.h"

Board::Board() {
    // create all the piece pointers
    auto whitePawnOne = std::make_unique<Piece>();
    auto whitePawnTwo = std::make_unique<Piece>();
    auto whitePawnThree = std::make_unique<Piece>();
    auto whitePawnFour = std::make_unique<Piece>();
    auto whitePawnFive = std::make_unique<Piece>();
    auto whitePawnSix = std::make_unique<Piece>();
    auto whitePawnSev = std::make_unique<Piece>();
    auto whitePawnEight = std::make_unique<Piece>();
    auto whiteKing = std::make_unique<Piece>();
    auto whiteQueen = std::make_unique<Piece>();
    auto whiteRookOne = std::make_unique<Piece>();
    auto whiteRookTwo = std::make_unique<Piece>();
    auto whiteBishopOne = std::make_unique<Piece>();
    auto whiteBishopTwo = std::make_unique<Piece>();
    auto whiteKnightOne = std::make_unique<Piece>();
    auto whiteKnightTwo = std::make_unique<Piece>();

    auto blackPawnOne = std::make_unique<Piece>();
    auto blackPawnTwo = std::make_unique<Piece>();
    auto blackPawnThree = std::make_unique<Piece>();
    auto blackPawnFour = std::make_unique<Piece>();
    auto blackPawnFive = std::make_unique<Piece>();
    auto blackPawnSix = std::make_unique<Piece>();
    auto blackPawnSev = std::make_unique<Piece>();
    auto blackPawnEight = std::make_unique<Piece>();
    auto blackKing = std::make_unique<Piece>();
    auto blackQueen = std::make_unique<Piece>();
    auto blackRookOne = std::make_unique<Piece>();
    auto blackRookTwo = std::make_unique<Piece>();
    auto blackBishopOne = std::make_unique<Piece>();
    auto blackBishopTwo = std::make_unique<Piece>();
    auto blackKnightOne = std::make_unique<Piece>();
    auto blackKnightTwo = std::make_unique<Piece>();


    //add all pieces to the board rows
    std::vector<Piece *> rowOne{whitePawnOne.get(), whitePawnTwo.get(), 
                                               whitePawnThree.get(), whitePawnFour.get(), 
                                               whitePawnFive.get(), whitePawnSix.get(), 
                                               whitePawnSev.get(), whitePawnEight.get()};
    std::vector<Piece *> rowTwo{whiteRookOne.get(), whiteKnightOne.get(), 
                                               whiteBishopOne.get(), whiteQueen.get(), 
                                               whiteKing.get(), whiteBishopTwo.get(), 
                                               whiteKnightTwo.get(), whiteRookTwo.get()};
    std::vector<Piece *> rowThree{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    std::vector<Piece *> rowFour{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    std::vector<Piece *> rowFive{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    std::vector<Piece *> rowSix{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
    std::vector<Piece *> rowSev{blackPawnOne.get(), blackPawnTwo.get(), 
                                               blackPawnThree.get(), blackPawnFour.get(), 
                                               blackPawnFive.get(), blackPawnSix.get(), 
                                               blackPawnSev.get(), blackPawnEight.get()};

    std::vector<Piece *> rowEight{blackRookOne.get(), blackKnightOne.get(), 
                                               blackBishopOne.get(), blackQueen.get(), 
                                               blackKing.get(), blackBishopTwo.get(), 
                                               blackKnightTwo.get(), blackRookTwo.get()};

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


std::vector<std::vector<Piece *>> Board::getBoard() const {return board;}


