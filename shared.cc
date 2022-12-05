#include "shared.h"
#include <string>

// map requires operator<
bool Position::operator<(Position const& other) const {
    return (row < other.row && col < other.col);
}

// for finding in map
bool Position::operator==(Position const& other) const {
    return (row == other.row && col == other.col);
}


std::string getColourStr(Colour colour) {
    if (colour == WHITE) return "White";
    else return "Black";
}

