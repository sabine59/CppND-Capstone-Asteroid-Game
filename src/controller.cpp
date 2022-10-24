#include "controller.h"
#include <iostream>
#include "SDL.h"




void Controller::HandleInput(bool &running, Ufo &ufo) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_f:
          if (ufo.alive) {
             ufo.isFiring = true;
             ufo.hasFired = true;
          }
          break;
          
        case SDLK_UP:
          ufo.direction = Ufo::Direction::kUp;
          break;

        case SDLK_DOWN:
          ufo.direction = Ufo::Direction::kDown;
          break;

 /*       case SDLK_LEFT:
          ufo.direction = Ufo::Direction::kLeft;
          break;

        case SDLK_RIGHT:
          ufo.direction = Ufo::Direction::kRight;
          break; */
          
          
        default:
          break;
      }
    } else if (e.type == SDL_KEYUP) {
      switch (e.key.keysym.sym) {
        case SDLK_f:
          ufo.isFiring = false;
          break;
          
        case SDLK_UP:
          ufo.direction = Ufo::Direction::none;
          break;

        case SDLK_DOWN:
          ufo.direction = Ufo::Direction::none;
          break;

        case SDLK_LEFT:
          ufo.direction = Ufo::Direction::none;
          break;

        case SDLK_RIGHT:
          ufo.direction = Ufo::Direction::none;
          break;
          
        default:
          break;
      }
    }  
  }
}