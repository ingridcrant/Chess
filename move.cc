#include "shared.h"
#include <string>
#include <iostream>
#include <sstream>

InvalidInput::InvalidInput(std::string message): message{message} {}

void InvalidInput::printMessage() const {std::cout << message << std::endl;};

int alphaToNum(char c) {
    switch(c) {
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case 'e': return 4;
        case 'f': return 5;
        case 'g': return 6;
        case 'h': return 7;
        default:
            throw InvalidInput{"Column out of scope."};
    }
}

bool validPiece(std::string str) {
    if (str.length() == 1) {
        switch(str[0]) {
            case 'r':
            case 'R':
            case 'q':
            case 'Q':
            case 'n':
            case 'N':
            case 'b':
            case 'B':
            case 'p':
            case 'P':
            case 'k':
            case 'K':
                return true;
            default:
                return false;
        }

    } else {
        throw InvalidInput("Invalid input.");
    }
}

Position convertToPos(std::string str) {
    int col, row;

    // string represents a position
    if (str.length() == 2) {
        col = alphaToNum(str[0]);
        row = 0;

        // check if the row is inputted as a proper digit under 8
        if (isdigit(str[1])) {
            row = str[1] - '0' - 1;
            if (row > 7 || row < 0) {
                throw InvalidInput{"Row out of scope."};
            }

        } else {
            throw InvalidInput{"Row not a digit."};
        }

    } else {
        throw InvalidInput("Invalid input.");
    }

    return Position{row, col};
}


Colour convertToColour(std::string colour) {
    //convert to lowercase
    for (int i = 0; i < colour.length(); i++) colour[i] = tolower(colour[i]);

    if (colour == "white") {
        return WHITE;
    }
    else if (colour == "black") {
        return BLACK;
    } else {
        throw InvalidInput("Invalid colour.");
    }
}

bool Move::validPromotionPiece(std::string str) const {
    if (str.length() == 1) {
        switch(str[0]) {
            case 'r':
            case 'R':
            case 'q':
            case 'Q':
            case 'n':
            case 'N':
            case 'b':
            case 'B':
                return true;
            default:
                return false;
        }

    } else {
        throw InvalidInput("Invalid input.");
    }

}

void Move::convertFormat(std::string str, int counter) {


    // check if it is a curPost or newPos
    if (counter == 0) {
        curPos = convertToPos(str);
    }
    else if (counter == 1) {
        newPos = convertToPos(str);
    }
    //string represents a piece that pawn should be promoted to
    else if (counter == 2 && Move::validPromotionPiece(str)) {
        promoteTo = str[0];
    }
}

Move::Move(std::string input) {
    int counter = 0;
    std::stringstream ss{input};
    std::string s;

    while(ss >> s) {
        if (counter < 3) Move::convertFormat(s, counter);
        else {
            throw InvalidInput{"Too much input."};
        }
        counter++;
    }

    if (counter == 2) promotion = false;
    else if (counter == 3) promotion = true;
}

Position Move::getCurPos() const {return curPos;}

Position Move::getNewPos() const {return newPos;}

bool Move::getPromotion() const {return promotion;}

char Move::getPromoteTo() const {return promoteTo;}


/*void test() {
    try {
        std::string str = "fds e5 e4";
        Move m{str};
        std::cout << m.getCurPos().col << " " << m.getCurPos().row << std::endl;
        std::cout << m.getNewPos().col << " " << m.getNewPos().row << std::endl;
        std::cout << m.getPromotion() << std::endl;
    } catch (InvalidInput e) {
        e.printMessage();
    }
}*/




