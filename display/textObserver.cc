#include "textObserver.h"
#include "../pieces/piece.h"
#include <iostream>


TextObserver::TextObserver(std::shared_ptr<Game> subject, int rows, int cols): subject{subject}, rows{rows}, cols{cols} {
    subject->attach(this);
}

TextObserver::~TextObserver() {subject->detach(this);}

std::string TextObserver::getPieceImage(char c) {
    switch (c) {
        case 'p': return "♟";
        case 'P': return "♙";
        case 'k': return "♚";
        case 'K': return "♔";
        case 'q': return "♛";
        case 'Q': return "♕";
        case 'b': return "♝";
        case 'B': return "♗";
        case 'n': return "♞";
        case 'N': return "♘";
        case 'r': return "♜";
        case 'R': return "♖";
        default:
            return std::string{c};
    }
}

void TextObserver::notify() {
    for(int row = rows - 1; row >= 0; row--) {
        std::cout << row + 1 << " ";
        for (int col = 0; col < cols; col++) {
            std::cout << getPieceImage(subject->getState(row, col));
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "  abcdefgh" << std::endl;
    
}


