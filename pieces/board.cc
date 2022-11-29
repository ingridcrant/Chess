#include "board.h"
#include <vector>
#include "../shared.h"

Board::Board() {

}


std::vector<std::vector<std::shared_ptr<Piece>>> Board::getBoard() const {return board;}


