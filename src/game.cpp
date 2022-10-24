#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(const std::size_t screen_width, const std::size_t screen_height, const float screenFactorX, const float screenFactorY)
    : ufo(screen_width, screen_height, screenFactorX, screenFactorY),
      engine(dev()),
      sfX(screenFactorX),
      sfY(screenFactorY)
      {
     
      Uint32 game_start = SDL_GetTicks();
      printf("screenFactorX: %f, screenFactorY: %f", sfX, sfY);
       // initialize the planets
      // Uranus:
      planets.emplace_back(std::make_unique <CelBody *> (new CelBody(screen_width, screen_height, screen_width, screen_height/10/sfY, sfX*screen_width/25,  sfX*6.0, 0., planetPaths[7], sfX*(game_start+500))));
      // Neptun:
      planets.emplace_back(std::make_unique <CelBody *> (new CelBody(screen_width, screen_height, screen_width, screen_height*15/100/sfY, sfX*screen_width/16,  sfX*3.5, 0., planetPaths[6], sfX*(game_start+12000))));
      // Jupiter:
      planets.emplace_back(std::make_unique <CelBody *> (new CelBody(screen_width, screen_height, screen_width, screen_height*15/100/sfY, sfX*screen_width/4,  sfX*5.0, 0., planetPaths[5], sfX*(game_start+20000))));
      // Saturn:
      planets.emplace_back(std::make_unique <CelBody *> (new CelBody(screen_width, screen_height, screen_width, screen_height*35/100/sfY, sfX*screen_width/4,  sfX*3.0, 0., planetPaths[4], sfX*(game_start+65000))));
      // Mars:
      planets.emplace_back(std::make_unique <CelBody *> (new CelBody(screen_width, screen_height, screen_width, sfY*screen_height*45/100/sfY, sfX*screen_width/7,  sfX*3.5, 0., planetPaths[3], sfX*(game_start+150000))));
      // Erde:
      planets.emplace_back(std::make_unique <CelBody *> (new CelBody(screen_width, screen_height, screen_width, sfY*screen_height*35/100/sfY, sfX*screen_width/9,  sfX*3.0, 0., planetPaths[2], sfX*(game_start+230000)))); 
      // Venus:
      planets.emplace_back(std::make_unique <CelBody *> (new CelBody(screen_width, screen_height, screen_width, sfY*screen_height*10/100/sfY, sfX*screen_width/10,  sfX*2.5, 0., planetPaths[1], sfX*(game_start+280000))));
      // Venus:
      planets.emplace_back(std::make_unique <CelBody *> (new CelBody(screen_width, screen_height, screen_width, sfY*screen_height*25/100/sfY, sfX*screen_width/10,  sfX*2.0, 0., planetPaths[0], sfX*(game_start+330000))));
      
      // set up the asteroids
      asteroids.emplace_back(std::make_unique <Asteroid *> (new Asteroid(screen_width, screen_height, screen_width, sfY*screen_height*25/100/sfY, sfX*15,  sfX*30.0, -sfY*6.0, asteroidPaths[0], sfX*(game_start+1000))));
      asteroids.emplace_back(std::make_unique <Asteroid *> (new Asteroid(screen_width, screen_height, screen_width, sfY*screen_height*25/100/sfY, sfX*18,  sfX*25.0, -sfY*7.0, asteroidPaths[1], sfX*(game_start+15000))));
      asteroids.emplace_back(std::make_unique <Asteroid *> (new Asteroid(screen_width, screen_height, screen_width, sfY*screen_height*25/100/sfY, sfX*15,  sfX*36.0, -sfY*7.0, asteroidPaths[2], sfX*(game_start+30000))));
      asteroids.emplace_back(std::make_unique <Asteroid *> (new Asteroid(screen_width, screen_height, screen_width, sfY*screen_height*25/100/sfY, sfX*30,  sfX*15.0, -sfY*7.0, asteroidPaths[3], sfX*(game_start+35000))));
      asteroids.emplace_back(std::make_unique <Asteroid *> (new Asteroid(screen_width, screen_height, screen_width, sfY*screen_height*25/100/sfY, sfX*25,  sfX*35.0, -sfY*9.0, asteroidPaths[4], sfX*(game_start+40000))));
      asteroids.emplace_back(std::make_unique <Asteroid *> (new Asteroid(screen_width, screen_height, screen_width, sfY*screen_height*25/100/sfY, sfX*15,  sfX*45.0, -sfY*9.0, asteroidPaths[4], sfX*(game_start+45000))));
      asteroids.emplace_back(std::make_unique <Asteroid *> (new Asteroid(screen_width, screen_height, screen_width, sfY*screen_height*25/100/sfY, sfX*20,  sfX*18.0, -sfY*9.0, asteroidPaths[4], sfX*(game_start+48000))));
      asteroids.emplace_back(std::make_unique <Asteroid *> (new Asteroid(screen_width, screen_height, screen_width, sfY*screen_height*25/100/sfY, sfX*16,  sfX*25.0, -sfY*9.0, asteroidPaths[4], sfX*(game_start+50000))));
      asteroids.emplace_back(std::make_unique <Asteroid *> (new Asteroid(screen_width, screen_height, screen_width, sfY*screen_height*25/100/sfY, sfX*18,  sfX*28.0, -sfY*9.0, asteroidPaths[4], sfX*(game_start+55000))));
      asteroids.emplace_back(std::make_unique <Asteroid *> (new Asteroid(screen_width, screen_height, screen_width, sfY*screen_height*25/100/sfY, sfX*25,  sfX*45.0, -sfY*9.0, asteroidPaths[4], sfX*(game_start+55100))));
      asteroids.emplace_back(std::make_unique <Asteroid *> (new Asteroid(screen_width, screen_height, screen_width, sfY*screen_height*25/100/sfY, sfX*18,  sfX*30.0, -sfY*9.0, asteroidPaths[4], sfX*(game_start+56000))));
     
      
      
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
    renderer.Render(ufo, planets, asteroids);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(ufo.energieCounter, ufo.hitCounter, frame_count);
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

  //scheck, whether it is time for a planet to show up
 	for (std::shared_ptr planet : planets) {
      if ((frame_start > (*(planet).get())->GetTimeOA() ) && !(*(planet).get())->_isOnStage && (*(planet).get())->_expectedOnStage) {
        
    	//printf("Time to appear frame_start: %u, time to appear %u \n", frame_start, (*(planet).get())->GetTimeOA());
        if (!(*(planet).get())->_isOnStage ) {
          //printf("planet is not yet on stage \n");
        	renderer.createTextureFromFile((*(planet).get())->filepath, 2);
          (*(planet).get())->_isOnStage = true;
        }
      }
    }

    //scheck, whether it is time for asteroids to show up
    for (std::shared_ptr asteroid : asteroids) {
        if ((frame_start > (*(asteroid).get())->GetTimeOA() ) && !(*(asteroid).get())->_isOnStage && (*(asteroid).get())->_expectedOnStage) {
        
    	//printf("Time to appear frame_start: %u, time to appear %u \n", frame_start, (*(planet).get())->GetTimeOA());
           if (!(*(asteroid).get())->_isOnStage ) {
          //printf("asteroid is not yet on stage \n");
        	   renderer.createTextureFromFile((*(asteroid).get())->filepath, 3);
             (*(asteroid).get())->_isOnStage = true;
           }
        }
    }
  
}

void Game::Update() {

  ufo.Update();
  for (std::shared_ptr planet : planets) {
  	(*(planet).get())->Update(ufo.rect_ufo);
  }
  for (std::shared_ptr asteroid : asteroids) {
  	(*(asteroid).get())->Update(ufo.rect_ufo, ufo.ufo_fire_rect, ufo.hitCounter, ufo.energieCounter, ufo.isFiring);
  }

  
}
