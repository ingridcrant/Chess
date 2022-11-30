#include "game.h"
#include <memory>
#include <vector>
#include <iostream>

Game::Game(std::unique_ptr<Board> board, Player & playerOne, Player & playerTwo): board{std::move(board)}, 
                                                                                  turn{WHITE}, status{IN_PLAY} {
    players.push_back(playerOne);
    players.push_back(playerTwo);
}

Piece * Game::getState(int col, int row) const {
    return board->getPieceAt(col, row);
}

void Game::playGame() {} //needs to be implemented

void customSetup() {

}



