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
#include <iostream>
#include <string>


std::unique_ptr<Player> createPlayer(std::string str, Colour col) {
    if (str == "human") {
        return std::make_unique<Human>(col);
    }
    else if (str == "One") {
        return std::make_unique<LevelOne>(col);
    }
    else if (str == "Two") {
        return std::make_unique<LevelTwo>(col);
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
    auto window = std::make_unique<Xwindow>();
    auto graph = std::make_unique<GraphicalObserver>(g, std::move(window), 8, 8);
    
    std::string cmd;
    float whiteWins = 0;
    float blackWins = 0;

    std::cout << "WELCOME TO CHESS! To play as a computer, type in either One, Two, or Three for the levels. Please enter your commands:" << std::endl;

    while (std::cin >> cmd) {
        if (cmd == "setup") {
            g->customSetup();
        }
        else if (cmd == "game") {
            
            std::string playerOneStr, playerTwoStr;
            std::cin >> playerOneStr >> playerTwoStr;

            try {
                //create the player pointers
                auto playerOne = std::move(createPlayer(playerOneStr, WHITE));
                auto playerTwo = std::move(createPlayer(playerTwoStr, BLACK));
                players.push_back(playerOne.get());
                players.push_back(playerTwo.get());

                Colour winner = g->playGame(draw, players);

                if(draw) {
                    whiteWins += 0.5;
                    blackWins += 0.5;
                } else {
                    if (winner == WHITE) whiteWins++;
                    else blackWins++;
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
    std::cout << "White: " << whiteWins << std::endl;
    std::cout << "Black: " << whiteWins << std::endl;

}

