#ifndef GRAPH_H
#define GRAPH_H

#include "observer.h"
#include "game.h"
#include "window.h"
#include <vector>
#include <memory>

class GraphicalObserver : public Observer {
    std::shared_ptr<Game> subject;
    std::unique_ptr<Xwindow> window;
    std::vector<std::vector<char>> stateOfBoard;
    int rows, cols;

    int getColour(char c, int row, int col) const;
    void drawPiece(char c, int x, int y);

    public:
        GraphicalObserver(std::shared_ptr<Game> subject, std::unique_ptr<Xwindow> w, int rows, int cols);
        void notify() override;
        ~GraphicalObserver();
};


#endif


