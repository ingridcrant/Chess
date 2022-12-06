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

std::unique_ptr<PlayerImpl> getPlayerImpl(std::string str, Board * board) {
    if (str == "human") {
        return std::make_unique<Human>();
    }
    else if (str == "one") {
        return std::make_unique<LevelOne>(board);
    }
    else if (str == "two") {
        return std::make_unique<LevelTwo>(board);
    } else {
        throw InvalidInput{"Not a type of player."};
    }
}

int main() {
    auto b = std::make_unique<Board>();
    std::vector<Player *> players;
    std::vector<Observer*> observers;
    bool draw = false;
    auto g = std::make_shared<Game>(b.get());
    auto text = std::make_unique<TextObserver>(g, 8, 8);
//    auto window = std::make_unique<Xwindow>();
//    auto graph = std::make_unique<GraphicalObserver>(g, std::move(window), 8, 8);


    auto human = std::make_unique<Human>();
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
                playerOne->setBehaviour(getPlayerImpl(playerOneStr, b.get()).get());
                playerTwo->setBehaviour(getPlayerImpl(playerTwoStr, b.get()).get());
                players.push_back(playerOne.get());
                players.push_back(playerTwo.get());

                Colour winner = g->playGame(draw, players);

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
    }

    std::cout << "Final score:" << std::endl;
    //print out everyone's final scores
    for (int i = 0 ; i < players.size(); i++) {
        std::cout << getColourStr(players[i]->getColour()) << ": " << players[i]->getWins() << std::endl;
    }
}

