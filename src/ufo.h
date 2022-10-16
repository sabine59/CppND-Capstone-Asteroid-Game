#ifndef UFO_H
#define UFO_H

#include <vector>
#include "SDL.h"

class Ufo {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Ufo(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        x_pos(grid_width / 2),
        y_pos(grid_height / 2) {}

  void Update();

  void Fire();

  Direction direction = Direction::kUp;

  float speed{0.1f};

  bool alive{true};
  float x_pos;
  float y_pos;
  std::vector<SDL_Point> _frames;

 private:
  void UpdatePosition();

  int grid_width;
  int grid_height;
};

#endif