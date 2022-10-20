#include "celestrial_body.h"

CelBody::~CelBody() {};


void CelBody::UpdatePosition(int ufo_x) {
  if (_isOnStage) {
    growing += 0.1;
    rect.x -= _velocity_x;
    rect.y += _velocity_y;
    
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
       printf("UpdatePosition is called %s \n", filepath.c_str());
    if ( _screen_width < rect.x  || (rect.x+rect.w) < 0 ) {
      
      printf("is !onStage %s %u screenwidth: %u\n", filepath.c_str(), rect.x, _screen_width);
      _expectedOnStage = false;
      _isOnStage = false;
    }
    if ( _screen_height < rect.y || rect.y < 0 ) {
      
      printf("is !onStage %s %u screenheight: %u\n", filepath.c_str(), rect.y, _screen_height);
      _expectedOnStage = false;
      _isOnStage = false;
    } 
  }
}

