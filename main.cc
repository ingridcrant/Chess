#include <memory>
#include <iostream>
#include <vector>
#include "pieces/board.h"
#include "display/game.h"
#include "players/human.h"
#include "players/levelOne.h"
#include "players/levelTwo.h"
#include "shared.h"
#include "display/textObserver.h"
#include "display/graphicalObserver.h"
#include "pieces/piece.h"
#include <iostream>
#include <string>

int main() {
    auto b = std::make_unique<Board>();
    std::vector<Player *> players;
    std::vector<Observer*> observers;
    bool draw = false;
    auto g = std::make_shared<Game>(b.get());
    auto text = std::make_unique<TextObserver>(g, 8, 8);
    auto window = std::make_unique<Xwindow>();
    auto graph = std::make_unique<GraphicalObserver>(g, std::move(window), 8, 8);


    auto human = std::make_unique<Human>();
    auto levelOne = std::make_unique<LevelOne>(b.get());
    auto levelTwo = std::make_unique<LevelTwo>(b.get());
    auto playerOne = std::make_unique<Player>(WHITE, human.get()); //default
    auto playerTwo = std::make_unique<Player>(BLACK, human.get()); //default

    std::string cmd;

    std::cout << "WELCOME TO CHESS! To play as a computer, type in either 'one' or 'two' for the levels. Please enter your commands:" << std::endl;

    while (std::cin >> cmd) {
        if (cmd == "setup") {
            g->customSetup();
        }
        else if (cmd == "game") {

            std::string playerOneStr, playerTwoStr;
            std::cin >> playerOneStr >> playerTwoStr;

            try {
                //add the player behaviour pointers
                if (playerOneStr == "human") {
                    playerOne->setBehaviour(human.get());
                }
                else if (playerOneStr == "one") {
                    playerOne->setBehaviour(levelOne.get());
                }
                else if (playerOneStr == "two") {
                    playerOne->setBehaviour(levelTwo.get());
                } else {
                    throw InvalidInput{"Not a type of player."};
                }

                if (playerTwoStr == "human") {
                    playerTwo->setBehaviour(human.get());
                }
                else if (playerTwoStr == "one") {
                    playerTwo->setBehaviour(levelOne.get());
                }
                else if (playerTwoStr == "two") {
                    playerTwo->setBehaviour(levelTwo.get());
                } else {
                    throw InvalidInput{"Not a type of player."};
                }

                players.push_back(playerOne.get());
                players.push_back(playerTwo.get());

                //play game
                Colour winner = g->playGame(draw, players);

                //determine result
                if(draw) {
                    //increase everyone by 0.5
                    for (int i = 0 ; i < players.size(); i++) {
                        players[i]->increaseWin(0.5);
                    }


                } else {
                    //increase winner points
                    for (int i = 0 ; i < players.size(); i++) {
                        if (players[i]->getColour() == winner) {
                            players[i]->increaseWin(1);
                        }
                    }
                }

            } catch (InvalidInput err) {
                err.printMessage();
            }


        }
        else if (cmd == "done") {
            break;
        }
        else {
            std::cout << "Invalid command, try again." << std::endl;
        }
    }

    std::cout << "Final score:" << std::endl;
    //print out everyone's final scores
    for (int i = 0 ; i < players.size(); i++) {
        std::cout << getColourStr(players[i]->getColour()) << ": " << players[i]->getWins() << std::endl;
    }
}

