#include "game.h"
#include <memory>
#include <vector>
#include <iostream>
#include <string>

Game::Game(Board * board, std::unique_ptr<Player> playerOne, std::unique_ptr<Player> playerTwo): board{board}, 
                                                                                  turn{WHITE}, status{IN_PLAY} {
    players.push_back(std::move(playerOne));
    players.push_back(std::move(playerTwo));
}

Piece * Game::getState(int col, int row) const {
    return board->getPieceAt(col, row);
}

void Game::playGame() {} //needs to be implemented


//TODO: implement
bool Game::verifyProperSetup() const {}


void Game::customSetup() {
    std::string cmd;

    while(std::cin >> cmd) {
        if (cmd == "+") {
            try {
                std::string piece, posStr;
                std::cin >> piece >> posStr;
                Position pos = convertToPos(posStr);

                if(validPiece(piece)) {
                    // change up board
                    board->changeBoard(piece[0], pos);

                    //update display
                    notifyObservers();
                }
            } catch (InvalidInput err) {
                err.printMessage();
            }

        }
        else if (cmd == "-") {
            try {
                std::string posStr;
                std::cin >> posStr;
                Position pos = convertToPos(posStr);
                //remove piece from that square
                board->changeBoard(pos);

                //update display
                notifyObservers();

            } catch (InvalidInput err) {
                err.printMessage();
            }
            
        }
        else if (cmd == "=") {
            try {
                std::string colourStr;
                std::cin >> colourStr;
                Colour colour = convertToColour(colourStr);
                turn = colour;

            } catch (InvalidInput err) {
                err.printMessage();
            }

        }
        else if (cmd == "done") {
            if (Game::verifyProperSetup()) {
                break;
            } else {
                std::cout << "Board not set up correctly." << std::endl;
            }

        }
        else {
            std::cout << "Invalid command, type in again." << std::endl;
        }

    }
}



