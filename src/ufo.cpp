#include "ufo.h"
#include <cmath>
#include <iostream>

std::vector<std::string> Ufo::normal_frame_files {
    "./images/Ufo_F1.bmp",
    "./images/Ufo_F2.bmp",
    "./images/Ufo_F3.bmp",
    "./images/Ufo_F4.bmp",
    "./images/Ufo_F5.bmp",
    "./images/Ufo_F6.bmp",
    "./images/Ufo_F7.bmp",
    "./images/Ufo_F8.bmp",
    "./images/Ufo_F9.bmp"
    };
  
std::vector<std::string> Ufo::firing_frame_files {
    "./images/Ufo_fire_f1.bmp",
    "./images/Ufo_fire_f2.bmp",
    "./images/Ufo_fire_f3.bmp",
    "./images/Ufo_fire_f4.bmp",
    "./images/Ufo_fire_f5.bmp",
    "./images/Ufo_fire_f6.bmp",
    "./images/Ufo_fire_f7.bmp",
    "./images/Ufo_fire_f8.bmp",
    "./images/Ufo_fire_f9.bmp"
    };

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
 
}



  // Check ifufo is destroyed.
  // TO DO



