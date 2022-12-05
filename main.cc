#include <memory>
#include <iostream>
#include <vector>
#include "pieces/board.h"
#include "display/game.h"
#include "players/human.h"
#include "pieces/piece.h"
#include "display/textObserver.h"

int main() {
    auto b = std::make_unique<Board>();
    auto p1 = std::make_unique<Human>(WHITE);
    auto p2 = std::make_unique<Human>(BLACK);
    std::vector<Player *> players;
    players.push_back(p1.get());
    players.push_back(p2.get());
    std::vector<Observer*> observers;

    auto g = std::make_shared<Game>(b.get());
    auto text = std::make_unique<TextObserver>(g, 8, 8);
    //std::cout << b->getPieceAt(0, 4)->getSymbol() << std::endl; row 0, col 4 is K
    bool draw = false;
    Colour c = g->playGame(draw, players);

}

