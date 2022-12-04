#include "textObserver.h"
#include "../pieces/piece.h"
#include <iostream>


TextObserver::TextObserver(std::shared_ptr<Game> subject, int rows, int cols): subject{subject}, rows{rows}, cols{cols} {
    subject->attach(this);
}

TextObserver::~TextObserver() {subject->detach(this);}

void TextObserver::notify() {
    for(int row = rows - 1; row >= 0; row--) {
        std::cout << row + 1 << " ";
        for (int col = 0; col < cols; col++) {
            std::cout << subject->getState(row, col);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "  abcdefgh" << std::endl;
    
}


