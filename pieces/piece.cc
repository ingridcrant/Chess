#include "piece.h"
#include "iostream"

Piece::Piece(Colour colour, char symbol, Position pos, Distance dist, bool specialCapture):colour{colour}, symbol{symbol}, currPos{pos}, dist{dist}, specialCapture{specialCapture} {}

InvalidDirection::InvalidDirection(std::string message): message{message} {}
void InvalidDirection::printMessage() const {std::cout << message << std::endl;};

std::map<Position, MoveTypes> Piece::allPosInDirection(Direction direction, Board* board) {
    std::map<Position, MoveTypes> nextPositionsInD;

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
            const Position nextSpot = Position{currPos.row, currPos.col - i};

            if (0 > currPos.row || currPos.row >= 8 || currPos.col - i < 0 || currPos.col - i >= 8) break;
            if (board->getPieceAt(currPos.row, currPos.col - i) != nullptr) {
                nextPositionsInD[nextSpot] = CAPTURE;
                break;
            }
        
            nextPositionsInD[nextSpot] = MOVE;
        }
    } else if (direction == RIGHT) {
        for (int d = 0; d < dx; d++) {
            int i = d * aim;
            const Position nextSpot = Position{currPos.row, currPos.col + i};

            if (0 > currPos.row || currPos.row >= 8 || currPos.col + i < 0 || currPos.col + i >= 8) break;
            if (board->getPieceAt(currPos.row, currPos.col + i) != nullptr) {
                nextPositionsInD[nextSpot] = CAPTURE;
                break;
            }
        
            nextPositionsInD[nextSpot] = MOVE;
        }
    } else if (direction == UP) {
        for (int d = 0; d < dy; d++) {
            int i = d * aim;
            const Position nextSpot = Position{currPos.row + i, currPos.col};

            if (0 > currPos.row + i || currPos.row + i >= 8 || currPos.col < 0 || currPos.col >= 8) break;
            if (board->getPieceAt(currPos.row + i, currPos.col) != nullptr) {
                nextPositionsInD[nextSpot] = CAPTURE;
                break;
            }
        
            nextPositionsInD[nextSpot] = MOVE;
        }
    } else if (direction == PAWN_UP) {
        if (currPos.row + aim >= 0 && currPos.row + aim < board->getRows()) {
            if (board->getPieceAt(currPos.row + aim, currPos.col) == nullptr) {
            nextPositionsInD[Position{currPos.row + aim, currPos.col}] = MOVE;
            }
            if (0 <= currPos.col - 1 && currPos.col - 1 < board->getCols() && board->getPieceAt(currPos.row + aim, currPos.col - 1) != nullptr) {
                nextPositionsInD[Position{currPos.row + aim, currPos.col - 1}] = CAPTURE;
            }
            if (0 <= currPos.col + 1 && currPos.col + 1 < board->getCols() && board->getPieceAt(currPos.row + aim, currPos.col + 1) == nullptr) {
                nextPositionsInD[Position{currPos.row + aim, currPos.col + 1}] = CAPTURE;
            }
        }
    } else if (direction == DOWN) {
        for (int d = 0; d < dy; d++) {
            int i = d * aim;
            const Position nextSpot = Position{currPos.row - i, currPos.col};

            if (0 > currPos.row - i || currPos.row - i >= 8 || currPos.col < 0 || currPos.col >= 8) break;
            if (board->getPieceAt(currPos.row - i, currPos.col) != nullptr) {
                nextPositionsInD[nextSpot] = CAPTURE;
                break;
            }
            
            nextPositionsInD[nextSpot] = MOVE;
        }
    } else if (direction == LEFT_UP_DIAGONAL) {
        for (int d = 0; d < dy; d++) {
            int i = d * aim;
            const Position nextSpot = Position{currPos.row + i, currPos.col - i};

            if (0 > currPos.row + i || currPos.row + i >= 8 || currPos.col - i < 0 || currPos.col - i >= 8) break;
            if (board->getPieceAt(currPos.row + i, currPos.col - i) != nullptr) {
                nextPositionsInD[nextSpot] = CAPTURE;
                break;
            }

            nextPositionsInD[nextSpot] = MOVE;
        }
    } else if (direction == LEFT_DOWN_DIAGONAL) {
        for (int d = 0; d < dy; d++) {
            int i = d * aim;
            const Position nextSpot = Position{currPos.row - i, currPos.col - i};

            if (0 > currPos.row - i || currPos.row - i >= 8 || currPos.col - i < 0 || currPos.col - i >= 8) break;
            if (board->getPieceAt(currPos.row - i, currPos.col - i) != nullptr) {
                nextPositionsInD[nextSpot] = CAPTURE;
                break;
            }
            
            nextPositionsInD[nextSpot] = MOVE;
        }
    } else if (direction == RIGHT_UP_DIAGONAL) {
        for (int d = 0; d < dy; d++) {
            int i = d * aim;
            const Position nextSpot = Position{currPos.row + i, currPos.col + i};

            if (0 > currPos.row + i || currPos.row + i >= 8 || currPos.col + i < 0 || currPos.col + i >= 8) break;
            if (board->getPieceAt(currPos.row + i, currPos.col + i) != nullptr) {
                nextPositionsInD[nextSpot] = CAPTURE;
                break;
            }

            nextPositionsInD[nextSpot] = MOVE;
        }
    } else if (direction == RIGHT_DOWN_DIAGONAL) {
        for (int d = 0; d < dy; d++) {
            int i = d * aim;
            const Position nextSpot = Position{currPos.row - i, currPos.col + i};

            if (0 > currPos.row - i || currPos.row - i >= 8 || currPos.col + i < 0 || currPos.col + i >= 8) break;
            if (board->getPieceAt(currPos.row - i, currPos.col + i) != nullptr) {
                nextPositionsInD[nextSpot] = CAPTURE;
                break;
            }

            nextPositionsInD[nextSpot] = MOVE;
        }
    } else if (direction == KNIGHT_DOWN_LEFT) {
        if (0 <= currPos.row - 3 * aim && currPos.row - 3 * aim < 8 && currPos.col - aim >= 0 && currPos.col - aim < 8) {
            const Position nextSpot = Position{currPos.row - 3 * aim, currPos.col - aim};
            if (board->getPieceAt(currPos.row - 3 * aim, currPos.col - aim) != nullptr) {
                nextPositionsInD[nextSpot] = CAPTURE;
            } else {
                nextPositionsInD[nextSpot] = MOVE;
            }
        }
    } else if (direction == KNIGHT_DOWN_RIGHT) {
        if (0 <= currPos.row - 3 * aim && currPos.row - 3 * aim < 8 && currPos.col + aim >= 0 && currPos.col + aim < 8) {
            const Position nextSpot = Position{currPos.row - 3 * aim, currPos.col + aim};
            if (board->getPieceAt(currPos.row - 3 * aim, currPos.col + aim) != nullptr) {
                nextPositionsInD[nextSpot] = CAPTURE;
            } else {
                nextPositionsInD[nextSpot] = MOVE;
            }
        }
    } else if (direction == KNIGHT_UP_LEFT) {
        if (0 <= currPos.row + 3 * aim && currPos.row + 3 * aim < 8 && currPos.col - aim >= 0 && currPos.col - aim < 8) {
            const Position nextSpot = Position{currPos.row + 3 * aim, currPos.col - aim};
            if (board->getPieceAt(currPos.row + 3 * aim, currPos.col - aim) != nullptr) {
                nextPositionsInD[nextSpot] = CAPTURE;
            } else {
                nextPositionsInD[nextSpot] = MOVE;
            }
        }
    } else if (direction == KNIGHT_UP_RIGHT) {
        if (0 <= currPos.row + 3 * aim && currPos.row + 3 * aim < 8 && currPos.col + aim >= 0 && currPos.col + aim < 8) {
            const Position nextSpot = Position{currPos.row + 3 * aim, currPos.col + aim};
            if (board->getPieceAt(currPos.row + 3 * aim, currPos.col + aim) != nullptr) {
                nextPositionsInD[nextSpot] = CAPTURE;
            } else {
                nextPositionsInD[nextSpot] = MOVE;
            }
        }
    } else {
        throw InvalidDirection{"Invalid direction."};
    }

    return nextPositionsInD;
}

bool Piece::validateMove(Position newPos) {
    for (auto const pair : nextPositions) {
        if (pair.first.row == newPos.row && pair.first.col == newPos.col) {
            return true;
        }
    }
    return false;
}

char Piece::getSymbol() {
    return symbol;
}

Position Piece::getPos() {
    return currPos;
}

bool Piece::getSkipsTwo() { 
    return false;
}

Colour Piece::getColour() {
    return colour;
}

bool Piece::getFirstMove() {
    return firstMove;
}

bool Piece::getInCheck() {
    return false;
}

void Piece::setInCheck(bool val) {}

std::map<Position, MoveTypes> Piece::getNextPositions() {
    return nextPositions;
}
