#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "ufo.h"

class Controller {
 public:
  void HandleInput(bool &running, Snake &snake, Ufo &ufo) const;

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif