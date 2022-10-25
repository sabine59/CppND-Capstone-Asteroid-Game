#ifndef GAME_H
#define GAME_H

#include <random>
#include <memory>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "ufo.h"

class Game {
 public:
  Game(const std::size_t screen_width, const std::size_t screen_height, const float screenFactorX, const float screenFactorY);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetSize() const;
  

 private:
  std::vector<std::string> planetPaths = {
    "./images/Merkur.bmp", 
    "./images/Venus.bmp", 
    "./images/Erde.bmp", 
    "./images/Mars.bmp", 
    "./images/Saturn.bmp", 
    "./images/Jupiter.bmp", 
    "./images/Neptun.bmp", 
    "./images/Uranus.bmp"
  };

    std::vector<std::string> asteroidPaths = {
    "./images/asteroid1.bmp", 
    "./images/asteroid2.bmp", 
    "./images/asteroid3.bmp", 
    "./images/asteroid4.bmp", 
    "./images/asteroid5.bmp", 
    "./images/asteroid6.bmp", 
    "./images/asteroid7.bmp", 
    "./images/asteroid8.bmp",
    "./images/asteroid9.bmp",
    "./images/asteroid10.bmp",
    "./images/asteroid12.bmp",
    "./images/fuelcann.bmp",
    "./images/zimtstern.bmp",
    "./images/java.bmp"
  };
 
  Ufo ufo;
  std::vector<std::shared_ptr<CelBody *>> planets;
  std::vector<std::shared_ptr<Asteroid *>> asteroids;
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  float sfX;
  float sfY;
  
  void CheckForAppearanceOnStage(Uint32 frame_start, Renderer &renderer);
  void Update();
};

#endif