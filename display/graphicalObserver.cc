#include "graphicalObserver.h"
#include <iostream>

int GraphicalObserver::getColour(char c, int row, int col) const { 
    if (c == '_' || (row + col) % 2 == 0) return Xwindow::Blue;
    else return Xwindow::White;
}

GraphicalObserver::GraphicalObserver(std::shared_ptr<Game> subject, std::unique_ptr<Xwindow> w, int rows, int cols): subject{subject}, window{std::move(w)}, rows{rows}, cols{cols} {
    subject->attach(this);
    
    // intiialize stateOfBoard with
    std::vector<char> rowOne = {'_', ' ', '_', ' ', '_', ' ', '_', ' '};
    std::vector<char> rowTwo = {' ', '_', ' ', '_', ' ', '_', ' ', '_'};
    std::vector<char> rowThree = {'_', ' ', '_', ' ', '_', ' ', '_', ' '};
    std::vector<char> rowFour = {' ', '_', ' ', '_', ' ', '_', ' ', '_'};
    std::vector<char> rowFive = {'_', ' ', '_', ' ', '_', ' ', '_', ' '};
    std::vector<char> rowSix = {' ', '_', ' ', '_', ' ', '_', ' ', '_'};
    std::vector<char> rowSeven = {'_', ' ', '_', ' ', '_', ' ', '_', ' '};
    std::vector<char> rowEight = {' ', '_', ' ', '_', ' ', '_', ' ', '_'};
    stateOfBoard.push_back(rowOne);
    stateOfBoard.push_back(rowTwo);
    stateOfBoard.push_back(rowThree);
    stateOfBoard.push_back(rowFour);
    stateOfBoard.push_back(rowFive);
    stateOfBoard.push_back(rowSix);
    stateOfBoard.push_back(rowSeven);
    stateOfBoard.push_back(rowEight);

    //draw empty board
    for (int row = rows - 1; row >= 0; row--) {
        for (int col = 0; col < cols; col++) {
            char state = subject->getState(row,  col);
            int colour = GraphicalObserver::getColour(state, row, col);
            //draw square
            window->fillRectangle((800-((col + 1) * 100)), row * 100, 100, 100, colour);
        }
    }
}


void GraphicalObserver::drawPiece(char c, int x, int y) {
    if (c != '_' && c != ' ') {
        window->drawString(x + 50, y + 50, std::string{c});
    } else {
        window->drawString(x + 50, y + 50, "");
    }
}


void GraphicalObserver::notify() {
    for (int row = rows - 1; row >= 0; row--) {
        for (int col = 0; col < cols; col++) {

            //if cell has changed state, redraw
            char state = subject->getState(row,  col);
            if (stateOfBoard[row][col] != state) {
                stateOfBoard[row][col] = state;

                int colour = GraphicalObserver::getColour(state, row, col);
                //draw square
                window->fillRectangle(col * 100, 800-((row + 1) * 100), 100, 100, colour);

                //if there is a piece, add it
                GraphicalObserver::drawPiece(state, col * 100, 800-((row + 1) * 100));

            }
        }
    }
    
}

GraphicalObserver::~GraphicalObserver() {
    subject->detach(this);
}



