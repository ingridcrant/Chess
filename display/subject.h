#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "observer.h"

class Observer;

class Subject {
  std::vector<Observer*> observers;
 public:
  void attach(Observer *o);
  void detach(Observer *o);
  void notifyObservers();
  virtual Piece * getState(int col, int row) const = 0;
  virtual ~Subject() = default;
};

#endif
