#include <memory>
#include <iostream>
#include "pieces/board.h"
#include "display/game.h"
#include "players/human.h"
#include "pieces/piece.h"

int main() {
    auto b = std::make_unique<Board>();
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
    }
}

