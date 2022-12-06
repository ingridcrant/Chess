#include "game.h"
#include "../pieces/piece.h"
#include "../players/player.h"
#include <memory>
#include <vector>
#include <iostream>
#include <string>

Game::Game(Board * board): board{board}, turn{WHITE}, status{IN_PLAY} {}

char Game::getState(int row, int col) const {
    if (board->getPieceAt(row, col)) {
        return board->getPieceAt(row, col)->getSymbol();
    }
    else if ((row + col) % 2 == 0) {
        return '_';
    }
    return ' ';
}

Colour Game::playGame(bool & draw, std::vector<Player *> players) {
    notifyObservers();
    bool done = false;
    Move* lastMovePtr = nullptr;
    Move lastMove = Move{"a1 a3"}; // random
    Colour winner;

    // get first player
    int playerIndex = 0;
    Player * curPlayer;
    for (int i = 0; i < players.size(); i++) {
        if (players[i]->getColour() == turn) {
            playerIndex = i;
            break;
        }
    }

    //game loop
    while (!done) {
        curPlayer = players[playerIndex];
        std::cout << "It is now " << getColourStr(curPlayer->getColour()) << "'s turn!" << std::endl;
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "resign") {

            if (curPlayer->getColour() == WHITE) { //announce opponent as winner
                winner = BLACK;
                std::cout << "Black wins!" << std::endl;
            } else {
                winner = WHITE;
                std::cout << "White wins!" << std::endl;
            }
            draw = false;
            done = true;
        }
        else if (cmd == "move") {
            Move move{"a2 a1"}; //randomly construct

            //choose Move from player, if throws exception then go again
            try {
                move = curPlayer->chooseMove(lastMovePtr);
                move.setPiece(board->getPieceAt(move.getCurPos().row, move.getCurPos().col));
                if (!board->getPieceAt(move.getCurPos().row, move.getCurPos().col) || board->getPieceAt(move.getCurPos().row, move.getCurPos().col)->getColour() != curPlayer->getColour()) {
                    throw InvalidInput("Atempting to move an invalid piece");
                }

                //get opponent's colour
                Colour opponentCol;
                if (curPlayer->getColour() == WHITE) opponentCol = BLACK;
                else opponentCol = WHITE;

                board->changeBoard(move, lastMovePtr);

                lastMove = Move{move.getCurPos(), move.getNewPos(), move.getPiece()};
                lastMovePtr = &lastMove;
                notifyObservers();

                //check if board is in check
                if (board->boardInCheck(opponentCol)) {
                    if (opponentCol == WHITE) {
                        std::cout << "White is in check." << std::endl;
                    } else std::cout << "Black is in check." << std::endl;
                }
                //check if board is in checkmate
                else if (board->boardInCheckmate(opponentCol)) {
                    if (opponentCol == WHITE) {
                        std::cout << "Checkmate! Black wins!" << std::endl;
                    } else std::cout << "Checkmate! White wins!" << std::endl;

                    draw = false;
                    done = true;
                } else if (board->boardInStalemate(curPlayer->getColour())){ //check if board is in a stalemate
                    std::cout << "Stalemate!" << std::endl;
                    draw = true;
                    done = true;
                }


            } catch (InvalidInput err) {
                err.printMessage();
                std::cout << "Try again." << std::endl; 
                playerIndex--; //player goes again
            } catch (InvalidMove err) {
                std::cout << "Invalid move, try again." << std::endl;
                playerIndex--;
            }

        } else {
            std::cout << "Invalid command, try again" << std::endl;
            playerIndex--; //same player goes again
        }

        //change to next player
        playerIndex++;
        if (playerIndex == players.size()) playerIndex = 0;

    }


    return winner;
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
                    if (board->getPieceAt(row, col)->getInCheck()) return false;
            }
            else if (board->getPieceAt(row, col) && board->getPieceAt(row, col)->getSymbol() == 'K') {
                    whiteKing++;
                    //TODO: chec if king is in check
                    if (board->getPieceAt(row, col)->getInCheck()) return false;
            }
        }
    }

    if (whiteKing != 1 || blackKing != 1) return false;

    return true;
}


void Game::customSetup() {
    notifyObservers();
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
                std::cout << "Back to main menu." << std::endl;
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


