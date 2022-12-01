#include "piece.h"
#include "iostream"

Piece::Piece(Colour colour, char symbol, Position pos, Distance dist, bool specialCapture):colour{colour}, symbol{symbol}, currPos{pos}, dist{dist}, specialCapture{specialCapture} {}

InvalidDirection::InvalidDirection(std::string message): message{message} {}
void InvalidDirection::printMessage() const {std::cout << message << std::endl;};

std::vector<Position> Piece::allPosInDirection(Direction direction, Board* board) {
    std::vector<Position> nextPositionsInD;

    int dx = 1;
    int dy = 1;

    if (dist == INFINITE) {
        dx = 8;
        dy = 8;
    }

    int aim = 1;
    if (colour == BLACK) {
        aim *= -1;
    }

    if (direction == LEFT) {
        for (int d = 0; d < dx; d++) {
            int i = d * aim;
            if (0 < currPos.row || currPos.row >= 8 || currPos.col - i < 0 || currPos.col - i >= 8) break;
            if (board->getPieceAt(currPos.row, currPos.col - i) != nullptr) break;
        
            Position nextSpot = Position{currPos.row, currPos.col - i};
            nextPositionsInD.emplace_back(nextSpot);
        }
    } else if (direction == RIGHT) {
        for (int d = 0; d < dx; d++) {
            int i = d * aim;
            if (0 < currPos.row || currPos.row >= 8 || currPos.col + i < 0 || currPos.col + i >= 8) break;
            if (board->getPieceAt(currPos.row, currPos.col + i) != nullptr) break;
        
            Position nextSpot = Position{currPos.row, currPos.col + i};
            nextPositionsInD.emplace_back(nextSpot);
        }
    } else if (direction == UP) {
        for (int d = 0; d < dy; d++) {
            int i = d * aim;
            if (0 < currPos.row + i || currPos.row + i >= 8 || currPos.col < 0 || currPos.col >= 8) break;
            if (board->getPieceAt(currPos.row + i, currPos.col) != nullptr) break;
        
            Position nextSpot = Position{currPos.row + i, currPos.col};
            nextPositionsInD.emplace_back(nextSpot);
        }
    } else if (direction == DOWN) {
        for (int d = 0; d < dy; d++) {
            int i = d * aim;
            if (0 < currPos.row - i || currPos.row - i >= 8 || currPos.col < 0 || currPos.col >= 8) break;
            if (board->getPieceAt(currPos.row - i, currPos.col) != nullptr) break;

            Position nextSpot = Position{currPos.row - i, currPos.col};
            nextPositionsInD.emplace_back(nextSpot);
        }
    } else if (direction == LEFT_UP_DIAGONAL) {
        for (int d = 0; d < dy; d++) {
            int i = d * aim;
            if (0 < currPos.row + i || currPos.row + i >= 8 || currPos.col - i < 0 || currPos.col - i >= 8) break;
            if (board->getPieceAt(currPos.row + i, currPos.col - i) != nullptr) break;

            Position nextSpot = Position{currPos.row + i, currPos.col - i};
            nextPositionsInD.emplace_back(nextSpot);
        }
    } else if (direction == LEFT_DOWN_DIAGONAL) {
        for (int d = 0; d < dy; d++) {
            int i = d * aim;
            if (0 < currPos.row - i || currPos.row - i >= 8 || currPos.col - i < 0 || currPos.col - i >= 8) break;
            if (board->getPieceAt(currPos.row - i, currPos.col - i) != nullptr) break;
            
            Position nextSpot = Position{currPos.row - i, currPos.col - i};
            nextPositionsInD.emplace_back(nextSpot);
        }
    } else if (direction == RIGHT_UP_DIAGONAL) {
        for (int d = 0; d < dy; d++) {
            int i = d * aim;
            if (0 < currPos.row + i || currPos.row + i >= 8 || currPos.col + i < 0 || currPos.col + i >= 8) break;
            if (board->getPieceAt(currPos.row + i, currPos.col + i) != nullptr) break;

            Position nextSpot = Position{currPos.row + i, currPos.col + i};
            nextPositionsInD.emplace_back(nextSpot);
        }
    } else if (direction == RIGHT_DOWN_DIAGONAL) {
        for (int d = 0; d < dy; d++) {
            int i = d * aim;
            if (0 < currPos.row - i || currPos.row - i >= 8 || currPos.col + i < 0 || currPos.col + i >= 8) break;
            if (board->getPieceAt(currPos.row - i, currPos.col + i) != nullptr) break;

            Position nextSpot = Position{currPos.row - i, currPos.col + i};
            nextPositionsInD.emplace_back(nextSpot);
        }
    } else if (direction == KNIGHT_DOWN_LEFT) {
        if (0 <= currPos.row - 3 * aim && currPos.row - 3 * aim < 8 && currPos.col - aim >= 0 && currPos.col - aim < 8) {
            Position nextSpot = Position{currPos.row - 3 * aim, currPos.col - aim};
            nextPositionsInD.emplace_back(nextSpot);
        }
    } else if (direction == KNIGHT_DOWN_RIGHT) {
        if (0 <= currPos.row - 3 * aim && currPos.row - 3 * aim < 8 && currPos.col + aim >= 0 && currPos.col + aim < 8) {
            Position nextSpot = Position{currPos.row - 3 * aim, currPos.col + aim};
            nextPositionsInD.emplace_back(nextSpot);
        }
    } else if (direction == KNIGHT_UP_LEFT) {
        if (0 <= currPos.row + 3 * aim && currPos.row + 3 * aim < 8 && currPos.col - aim >= 0 && currPos.col - aim < 8) {
            Position nextSpot = Position{currPos.row + 3 * aim, currPos.col - aim};
            nextPositionsInD.emplace_back(nextSpot);
        }
    } else if (direction == KNIGHT_UP_RIGHT) {
        if (0 <= currPos.row + 3 * aim && currPos.row + 3 * aim < 8 && currPos.col + aim >= 0 && currPos.col + aim < 8) {
            Position nextSpot = Position{currPos.row + 3 * aim, currPos.col + aim};
            nextPositionsInD.emplace_back(nextSpot);
        }
    } else {
        throw InvalidDirection{"Invalid direction."};
    }

    return nextPositionsInD;
}

bool Piece::validateMove(Position newPos) {
    for (Position pos : nextPositions) {
        if (pos.row == newPos.row && pos.col == newPos.col) {
            return true;
        }
    }
    return false;
}

char getSymbol() {
    return symbol;
}

Position getPos() {
    return pos;
}
