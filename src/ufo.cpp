#include "ufo.h"
#include <cmath>
#include <iostream>

void Ufo::Update() {
  SDL_Point prev_cell{
      static_cast<int>(x_pos),
      static_cast<int>(
          y_pos)};  // We first capture the head's cell before updating.
  UpdatePosition();

}

void Ufo::UpdatePosition() {
  switch (direction) {
    case Direction::kUp:
      y_pos -= speed;
      break;

    case Direction::kDown:
      y_pos += speed;
      break;

    case Direction::kLeft:
      x_pos -= speed;
      break;

    case Direction::kRight:
      x_pos += speed;
      break;
  }

  // Wrap the Ufo around to the beginning if going off of the screen.
  x_pos = fmod(x_pos + grid_width, grid_width);
  y_pos = fmod(y_pos + grid_height, grid_height);
}



  // Check ifufo is destroyed.
  // TO DO



