#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(const std::size_t screen_width, const std::size_t screen_height,std::size_t grid_width, std::size_t grid_height)
    : ufo(screen_width, screen_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
      for ( unsigned int i = 0; i<planetPaths.size() ; i++) {
        planets.emplace_back(std::make_unique <CelBody *> (new CelBody(screen_width, screen_height -200, 100., 100., -20., 20., planetPaths[i], 4000)));
      }
    /*  planets["Merkur.bmp"] = 34000;
      planets["Venus.bmp"] =30000;
      planets["Erde.bmp"] = 26000;
      planets["Mars.bmp"] = 22000;
      planets["Saturn.bmp"] = 16000;
      planets["Jupiter.bmp"] =13000;
      planets["Neptun.bmp"] = 8000;
      planets["Uranus.bmp"] = 4000; */
      }

void Game::Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, ufo);
    Update();
    renderer.Render(ufo);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}


void Game::Update() {

  ufo.Update();
  
}

int Game::GetScore() const { return score; }