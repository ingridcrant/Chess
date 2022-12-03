#ifndef TEXT_H
#define TEXT_H

#include "observer.h"
#include "game.h"
#include <memory>

class TextObserver : public Observer {
    std::shared_ptr<Game> subject;
    int rows;
    int cols;

    public:
    TextObserver(std::shared_ptr<Game> subject, int rows, int cols);
    void notify() override;
    ~TextObserver();
};


#endif

