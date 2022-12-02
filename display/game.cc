#include "game.h"
#include "../pieces/piece.h"
#include "../players/player.h"
#include <memory>
#include <vector>
#include <iostream>
#include <string>

Game::Game(Board * board, Player * playerWhite, Player * playerBlack): board{board}, 
                                                                                  turn{WHITE}, status{IN_PLAY} {
    players.push_back(playerWhite);
    players.push_back(playerBlack);
}

Piece * Game::getState(int col, int row) const {
    return board->getPieceAt(col, row);
}

void Game::playGame() {
    // get first player
    int playerIndex = 0;
    Player * curPlayer;
    for (int i = 0; i < players.size(); i++) {
        if (players[i]->getColour() == turn) {
            curPlayer = players[i];
            playerIndex = i;
            break;
        }
    }

    
} 


bool Game::verifyProperSetup() const {
    int whiteKing = 0;
    int blackKing = 0;

    for(int col = board->getCols() - 1; col >= 0; col--) {
        for (int row = 0; row < board->getRows(); row++) {
            //std::cout << "COL " << col << " ROW " << row << std::endl;
            //check to see if there are any pawns in first/last row
            if (row == 0 || row == board->getRows() - 1) {
                if (board->getPieceAt(row, col) && tolower(board->getPieceAt(row, col)->getSymbol()) == 'p') {
                    return false;
                }
            }

            //add to counter if king is found
            if (board->getPieceAt(row, col) && board->getPieceAt(row, col)->getSymbol() == 'k') {
                    blackKing++;
                    //TODO: check if king is in check
            }
            else if (board->getPieceAt(row, col) && board->getPieceAt(row, col)->getSymbol() == 'K') {
                    whiteKing++;
                    //TODO: chec if king is in check
            }
        }
    }

    if (whiteKing != 1 || blackKing != 1) return false;

    return true;
}


void Game::customSetup() {
    std::string cmd;

    while(std::cin >> cmd) {
        if (cmd == "+") {
            try {
                std::string piece, posStr;
                std::cin >> piece >> posStr;
                Position pos = convertToPos(posStr);
                //std::cout << pos.row << " " << pos.col << std::endl;

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
                //std::cout << pos.col << " " << pos.row << " TEST" << std::endl;
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


/*auto b = std::make_unique<Board>();
    auto p1 = std::make_unique<Human>(WHITE);
    auto p2 = std::make_unique<Human>(BLACK);

    Game g = Game{b.get(), p1.get(), p2.get()};
    //std::cout << b->getPieceAt(0, 4)->getSymbol() << std::endl; row 0, col 4 is K
    g.customSetup();

    for(int i = b->getRows() - 1; i >= 0; i--) {
        for (int j = 0; j < b->getCols(); j++) {
            if(b->getPieceAt(i, j)) {
                std::cout << b->getPieceAt(i, j)->getSymbol();
            } else {
                std::cout << "-";
            }
        }
        std::cout << std::endl;
    }*/


