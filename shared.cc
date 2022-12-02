#include "shared.h"

// map requires operator<
bool Position::operator<(Position const& other) const {
    return (row < other.row && col < other.col);
}

// for finding in map
bool Position::operator==(Position const& other) const {
    return (row == other.row && col == other.col);
}
