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
  if (energieCounter <= 0)
    alive = false;
  if (hasFired) {
    energieCounter-= 2;
    hasFired=false;
  }
  UpdatePosition();

}

void Ufo::UpdatePosition() {
  // Ufo can only move in y-direction
  switch (direction) {
    case Direction::kUp:
      if ((rect_ufo.y - speed) > 0)
      	rect_ufo.y -= speed;
        energieCounter-= 3;
      break;

    case Direction::kDown:
      if (rect_ufo.y < ( _screen_height - speed - rect_ufo.h))
      	rect_ufo.y += speed;
        energieCounter-= 3;
      break;

 /*  case Direction::kLeft:
      if (rect_ufo.x > speed)
      	rect_ufo.x -= speed;
      break;

    case Direction::kRight:
      
      if (rect_ufo.x < ( _screen_width - speed - rect_ufo.w))
      	rect_ufo.x += speed;
      break; */
    
    case Direction::none:
      break;
      
  }
  direction = Direction::none;

  // compute the rect for the range of the ufo fire 
  ufo_fire_rect.x = rect_ufo.x + (rect_ufo.w/2);
  ufo_fire_rect.y = rect_ufo.y;
  ufo_fire_rect.w = rect_ufo.w;
  ufo_fire_rect.h = rect_ufo.h;
}



  // Check ifufo is destroyed.
  // TO DO



