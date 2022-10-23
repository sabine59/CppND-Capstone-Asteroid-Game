#include "asteroid.h"

Asteroid::~Asteroid() { CelBody::~CelBody(); };


void Asteroid::UpdatePosition1(SDL_Rect ufo_rect) {
  if (_isOnStage) {
    //printf("Update Position Asteroid \n");
    _vel_x += _velocity_x;
    _vel_y += _velocity_y;
    if (_vel_x > 10) {
      rect.x -= 1;
      _vel_x = 0;
    }
     if (_vel_y > 10) {
      printf("Update Position Asteroid \n");
      rect.y -= 1;
      _vel_y = 0;
    }

 
       //printf("UpdatePosition is called %s \n", filepath.c_str());
    if ( _screen_width < rect.x  || (rect.x+rect.w) < 0 ) {
      
     // printf("is !onStage %s %u screenwidth: %u\n", filepath.c_str(), rect.x, _screen_width);
      _expectedOnStage = false;
      _isOnStage = false;
    }
    if ( _screen_height < rect.y || (rect.y+rect.h) < 0 ) {
      
      //printf("is !onStage %s %u screenheight: %u\n", filepath.c_str(), rect.y, _screen_height);
      _expectedOnStage = false;
      _isOnStage = false;
    } 
  }
}