#include "game.h"
#include <memory>
#include <vector>
#include <iostream>

Game::Game(std::unique_ptr<Board> board, std::unique_ptr<Player> playerOne, std::unique_ptr<Player> playerTwo): board{std::move(board)}, 
                                                                                  turn{WHITE}, status{IN_PLAY} {
    players.push_back(std::move(playerOne));
    players.push_back(std::move(playerTwo));
}

Piece * Game::getState(int col, int row) const {
    return board->getPieceAt(col, row);
}

void Game::playGame() {} //needs to be implemented

void customSetup() {

}



