#include "celestrial_body.h"

CelBody::~CelBody(){};

void CelBody::UpdatePosition(Ufo &ufo)
{
  if (_isOnStage)
  {
    _growing += 0.0003 * rect.w; // grows dependent of the bodies size
    // The members of the rect are int variables. The rect comes from the SDL lib.
    // To get a higher resolution for the velocity _vel_x, _vel_y are used.
    _vel_x += _velocity_x;
    _vel_y += _velocity_y;

    if (_vel_x > 10)
    {
      rect.x -= 1;
      _vel_x = 0;
    }

    if (_vel_y > 10)
    {
      rect.y -= 1;
      _vel_y = 0;
    }
    else if (_vel_y < -10)
    {
      rect.y += 1;
      _vel_y = 0;
    }

    if (_growing > 1)
    {
      if ((ufo.rect_ufo.x + ufo.rect_ufo.w) < rect.x)
      {
        // the body grows, until the x-pos + width of the ufo is reached.
        rect.w += 1;
        rect.h += 1;
        _growing_count++;
        if (_growing_count == 1)
        {
          _growing_rect_y -= 1;
          if (_growing_rect_y < 0)
          {
            rect.y = 0; // the body isn't any more displayed, if the y-position is outside the screen
          }
        }
      }
      else if (ufo.rect_ufo.x > (rect.x + (rect.w)))
      {
        // after the ufo has left the x-pos+width of the body the body shrinks again.
        rect.w -= 1;
        rect.h -= 1;
        _growing_count++;
        if (_growing_count == 2)
        {
          _growing_rect_y += 1;
          if (_growing_rect_y >= 0)
          {
            rect.y = _growing_rect_y; // the body isn't any more displayed, if the y-position is outside the screen
          }
        }
      }
      _growing = 0;
    }
    // printf("UpdatePosition is called %s \n", filepath.c_str());
    if (_screen_width < rect.x || (rect.x + rect.w) < 0)
    {

      // printf("is !onStage %s %u screenwidth: %u\n", filepath.c_str(), rect.x, _screen_width);
      _expectedOnStage = false;
      _isOnStage = false;
    }
    if (_screen_height < rect.y || (rect.y + rect.h) < 0)
    {

      // printf("is !onStage %s %u screenheight: %u\n", filepath.c_str(), rect.y, _screen_height);
      _expectedOnStage = false;
      _isOnStage = false;
    }
  }
}
