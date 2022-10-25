#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{1000};
  constexpr std::size_t kScreenHeight{1000};
  //constexpr std::size_t kScreenWidth{1280};
  //constexpr std::size_t kScreenHeight{720};
  // All the movements are compured related to a screenw width of 1280
  // To keep the layout the same a screen factor is necessary
  // regarding the velocity, when another screen size is choosen


    // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
  static int display_in_use = 0; /* Only using first display */

  int i;
  SDL_DisplayMode current;
 // Get current display mode of all displays.
  for(i = 0; i < SDL_GetNumVideoDisplays(); ++i){

    int should_be_zero = SDL_GetCurrentDisplayMode(i, &current);

    if(should_be_zero != 0)
      // In case of error...
      SDL_Log("Could not get display mode for video display #%d: %s", i, SDL_GetError());

    else
      // On success, print the current display mode.
      SDL_Log("Display #%d: current display mode is %dx%dpx @ %dhz.", i, current.w, current.h, current.refresh_rate);

  }
  current.w = current.w/3;
  current.h = current.h/3;

  SDL_Log("Display : current resolution is %dx%dpx.", current.w, current.h);
  //current.w = 1000;
  //current.h = 1000;
  float screenFactorX = (float)current.w/1280.0; 
  float screenFactorY = (float)current.h/720.0; 
  Renderer renderer(current.w, current.h);
  Controller controller;
  Game game(current.w, current.h, screenFactorX, screenFactorY);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  //std::cout << "Score: " << game.GetScore() << "\n";
  SDL_Quit();
  return 0;
}