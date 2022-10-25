#include "asteroid.h"

Asteroid::~Asteroid() { CelBody::~CelBody(); };

void Asteroid::UpdatePosition1(Ufo &ufo)
{
  if (_isOnStage)
  {
    // The members of the rect are int variables. The rect comes from the SDL lib.
    // To get a higher resolution for the velocity _vel_x, _vel_y are used.

    // printf("UpdatePosition is called %s \n", filepath.c_str());
    _vel_x += _velocity_x;
    _vel_y += _velocity_y;

     if (_vel_x > 50)
    {
      rect.x -= 5;
      _vel_x = 0;
    }
    else if (_vel_x > 40)
    {
      rect.x -= 4;
      _vel_x = 0;
    }
    else if (_vel_x > 30)
    {
      rect.x -= 3;
      _vel_x = 0;
    }
    if (_vel_x > 20)
    {
      rect.x -= 2;
      _vel_x = 0;
    }
    else if (_vel_x > 10)
    {
      rect.x -= 1;
      _vel_x = 0;
    }

    if (_vel_y > 50)
    {
      rect.y -= 5;
      _vel_y = 0;
    }
    else if (_vel_y > 40)
    {
      rect.y -= 4;
      _vel_y = 0;
    }
    else if (_vel_y > 30)
    {
      rect.y -= 3;
      _vel_y = 0;
    }
    else if (_vel_y > 20)
    {
      rect.y -= 2;
      _vel_y = 0;
    }
    else if (_vel_y > 10)
    {
      rect.y -= 1;
      _vel_y = 0;
    }
    else if (_vel_y < -50)
    {
      rect.y += 5;
      _vel_y = 0;
    }
    else if (_vel_y < -40)
    {
      rect.y += 4;
      _vel_y = 0;
    }
    else if (_vel_y < -30)
    {
      rect.y += 3;
      _vel_y = 0;
    }
    else if (_vel_y < -20)
    {
      rect.y += 2;
      _vel_y = 0;
    }
    else if (_vel_y < -10)
    {
      rect.y += 1;
      _vel_y = 0;
    }

    if (ufo.isFiring)
    {
      if ((SDL_HasIntersection(&rect, &ufo.ufo_fire_rect) == SDL_TRUE) && (alive==true))
      {
        alive = false; // asteroid was destoyed by ufo fire
        ufo.energieCounter = ufo.energieCounter + energieBonus;
      }
    }

    if (SDL_HasIntersection(&rect, &ufo.rect_ufo) == SDL_TRUE && (alive == true))
    {
      if (_hadNoIntersection)
      {
        ufo.hitCounter++;
        ufo.energieCounter -= 5;
        _hadNoIntersection = false;
      }
    }
    // printf("UpdatePosition is called %s \n", filepath.c_str());
    if (_screen_width < rect.x || (rect.x + rect.w) < 0)
    {

      // printf("is !onStage %s \n", filepath.c_str());
      _expectedOnStage = false;
      wasAlreadyOnStage = true;
      _isOnStage = false;
    }
    if (_screen_height < rect.y || (rect.y + rect.h) < 0)
    {

      // printf("is !onStage %s \n", filepath.c_str());
      _expectedOnStage = false;
       wasAlreadyOnStage = true;
      _isOnStage = false;
    }
  }
}