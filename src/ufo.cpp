#include "ufo.h"
#include <cmath>
#include <iostream>

void Ufo::Update() {
  SDL_Point prev_cell{
      static_cast<int>(rect_ufo.x),
      static_cast<int>(rect_ufo.y)};  // We first capture the ufo's cell before updating.
  UpdatePosition();

}

void Ufo::UpdatePosition() {
  switch (direction) {
    case Direction::kUp:
      if (rect_ufo.y > speed)
      	rect_ufo.y -= speed;
      break;

    case Direction::kDown:
      if (rect_ufo.y <( _screen_height - speed - rect_ufo.h))
      rect_ufo.y += speed;
      break;

    case Direction::kLeft:
      if (rect_ufo.x > speed)
      rect_ufo.x -= speed;
      break;

    case Direction::kRight:
      
      if (rect_ufo.x < ( _screen_width - speed - rect_ufo.w))
      rect_ufo.x += speed;
      break;
    
    case Direction::none:
      break;
      
  }
  direction = Direction::none;
  // Wrap the Ufo around to the beginning if going off of the screen.
 // x_pos = fmod(x_pos + grid_width, grid_width);
 // y_pos = fmod(y_pos + grid_height, grid_height);
}



  // Check ifufo is destroyed.
  // TO DO



