#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(const std::size_t screen_width, const std::size_t screen_height,std::size_t grid_width, std::size_t grid_height)
    : ufo(screen_width, screen_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
      // initialize the planets
      Uint32 game_start = SDL_GetTicks();
   
      // Uranus:
      planets.emplace_back(std::make_unique <CelBody *> (new CelBody(screen_width, screen_height, screen_width, screen_height/10, screen_width/25,  6.0, 0., planetPaths[7], game_start+500)));
      // Neptun:
      planets.emplace_back(std::make_unique <CelBody *> (new CelBody(screen_width, screen_height, screen_width, screen_height*15/100, screen_width/16,  3.0, 0., planetPaths[6], game_start+10000)));
        
      // Jupiter:
      planets.emplace_back(std::make_unique <CelBody *> (new CelBody(screen_width, screen_height, screen_width, screen_height*15/100, screen_width/4,  4.0, 0., planetPaths[5], game_start+20000)));
      // Saturn:
      planets.emplace_back(std::make_unique <CelBody *> (new CelBody(screen_width, screen_height, screen_width, screen_height*35/100, screen_width/4,  3.0, 0., planetPaths[4], game_start+55000)));
      // Mars:
      planets.emplace_back(std::make_unique <CelBody *> (new CelBody(screen_width, screen_height, screen_width, screen_height*45/100, screen_width/6,  3.0, 0., planetPaths[3], game_start+130000)));
        
      // Erde:
      planets.emplace_back(std::make_unique <CelBody *> (new CelBody(screen_width, screen_height, screen_width, screen_height*35/100, screen_width/9,  2.5, 0., planetPaths[2], game_start+180000)));
        
      // Venus:
      planets.emplace_back(std::make_unique <CelBody *> (new CelBody(screen_width, screen_height, screen_width, screen_height*10/100, screen_width/10,  2.5, 0., planetPaths[1], game_start+230000)));
        
      // Venus:
      planets.emplace_back(std::make_unique <CelBody *> (new CelBody(screen_width, screen_height, screen_width, screen_height*25/100, screen_width/10,  2.0, 0., planetPaths[0], game_start+280000)));
  
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
  Uint32 game_start = title_timestamp;;
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();
    // check, which of the objects have to be on stage now
    CheckForAppearanceOnStage(frame_start, renderer);
    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, ufo);
    Update();
    renderer.Render(ufo,planets);

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


void Game::CheckForAppearanceOnStage(Uint32 frame_start, Renderer &renderer) {

 	for (std::shared_ptr planet : planets) {
      
    	
      if ((frame_start > (*(planet).get())->GetTimeOA() ) && !(*(planet).get())->_isOnStage && (*(planet).get())->_expectedOnStage) {
        
    	//printf("Time to appear frame_start: %u, time to appear %u \n", frame_start, (*(planet).get())->GetTimeOA());
        if (!(*(planet).get())->_isOnStage ) {
          //printf("is not yet on stage \n");
        	(*(planet).get())->_isOnStage = true;
        	renderer.createTextureFromFile((*(planet).get())->filepath);
        }
      }
    }
  
}

void Game::Update() {

  ufo.Update();
  for (std::shared_ptr planet : planets) {
  	(*(planet).get())->Update(ufo.rect_ufo);
  }

  
}

int Game::GetScore() const { return score; }