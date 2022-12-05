#include "shared.h"
#include <string>

// map requires operator<
bool Position::operator<(Position const& other) const {
    if ( this->row != other.row )
    {
        return (this->row < other.row);
    }
    return (this->col < other.col);
}

// for finding in map
bool Position::operator==(Position const& other) const {
    return (this->row == other.row && this->col == other.col);
}


std::string getColourStr(Colour colour) {
    if (colour == WHITE) return "White";
    else return "Black";
}

