#include "celestrial_body.h"

CelBody::~CelBody() {};


void CelBody::UpdatePosition(int ufo_x) {
  if (_isOnStage) {
    growing += 0.05;
    _vel_x += _velocity_x;
    _vel_y += _velocity_y;
    if (_vel_x > 1) {
      rect.x -= 1;
      _vel_x = 0;
    }
     if (_vel_y > 1) {
      rect.y -= 1;
      _vel_y = 0;
    }

    
    if ((growing - 1.0) > 0) {
      if (ufo_x < rect.x) {
       rect.w += 1;
       rect.h += 1;
      } else {
       rect.w -= 1;
       rect.h -= 1;
      }
      growing = 0;
    }
       //printf("UpdatePosition is called %s \n", filepath.c_str());
    if ( _screen_width < rect.x  || (rect.x+rect.w) < 0 ) {
      
     // printf("is !onStage %s %u screenwidth: %u\n", filepath.c_str(), rect.x, _screen_width);
      _expectedOnStage = false;
      _isOnStage = false;
    }
    if ( _screen_height < rect.y || rect.y < 0 ) {
      
      //printf("is !onStage %s %u screenheight: %u\n", filepath.c_str(), rect.y, _screen_height);
      _expectedOnStage = false;
      _isOnStage = false;
    } 
  }
}

