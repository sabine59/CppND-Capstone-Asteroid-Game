#ifndef UFO_H
#define UFO_H

#include <vector>
#include <string>
#include <memory>
#include "SDL.h"

class Ufo {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight, none };

  Ufo(int screen_width, int screen_height)
      : _screen_width(screen_width), _screen_height(screen_height) {
        	rect_ufo.w = 164;
            rect_ufo.h = 70;
            rect_ufo.x = screen_width / 3;
            rect_ufo.y = screen_height / 2;
          
        }

  void Update();


  Direction direction = Direction::none;

  float speed{6.5f};

  bool alive{true};

  SDL_Rect rect_ufo;
  bool isFiring=false;

  static std::vector<std::string> normal_frame_files;
  static std::vector<std::string> firing_frame_files;

 private:
  void UpdatePosition();
  int _screen_width;
  int _screen_height;
};


#endif