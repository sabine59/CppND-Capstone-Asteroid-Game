#ifndef GAME_H
#define GAME_H

#include <random>
#include <memory>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "celestrial_body.h"
#include "ufo.h"

class Game {
 public:
  Game(const std::size_t screen_width, const std::size_t screen_height, std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  std::vector<std::unique_ptr<CelBody *>> planets;

 private:
  std::vector<std::string> planetPaths = {
    "Merkur.bmp", 
    "Venus.bmp", 
    "Erde.bmp", 
    "Mars.bmp", 
    "Saturn.bmp", 
    "Jupiter.bmp", 
    "Neptun.bmp", 
    "Uranus.bmp"
  };
  Ufo ufo;
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void Update();
};

#endif