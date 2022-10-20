#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <memory>
#include "SDL.h"
#include "ufo.h"
#include "celestrial_body.h"


class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void createTextureFromFile(std::string path);
  void Render(Ufo &ufo, std::vector<std::shared_ptr<CelBody *>> const &planets);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  SDL_Surface *sdl_window_surface;
  SDL_Surface *image;

  std::vector<std::unique_ptr<SDL_Texture *>> _normal_frames;
  std::vector<std::unique_ptr<SDL_Texture *>> _firing_frames;
  std::vector<std::unique_ptr<SDL_Texture *>> _celBodyTextures {};
  SDL_Texture *asteroid1;

  int speed;
  int lastUfoFrame = 8;
  
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif