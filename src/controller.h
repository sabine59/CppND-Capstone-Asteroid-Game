#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ufo.h"

class Controller {
 public:
  void HandleInput(bool &running, Ufo &ufo) const;

 private:
};

#endif