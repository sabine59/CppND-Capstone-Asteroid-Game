#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <memory>
#include "SDL.h"
#include "ufo.h"
#include "asteroid.h"


class Renderer
{
public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();

  void createTextureFromFile(std::string path, int objectType);
  void Render(Ufo &ufo, std::vector<std::shared_ptr<CelBody *>> &planets, std::vector<std::shared_ptr<Asteroid *>> &asteroids, bool gameOver);
  void UpdateWindowTitle(int energie, int hits, int fps, bool gameOver);

private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  SDL_Surface *sdl_window_surface;
  SDL_Surface *image;

  std::vector<std::unique_ptr<SDL_Texture *>> _normal_frames;
  std::vector<std::unique_ptr<SDL_Texture *>> _firing_frames;
  std::vector<std::unique_ptr<SDL_Texture *>> _celBodyTextures{};
  std::vector<std::unique_ptr<SDL_Texture *>> _asteroidTextures{};
  SDL_Texture *background;
  SDL_Texture * home;
  SDL_Rect rect_b1;
  SDL_Rect rect_b2;
  int xpos_factor;
  int speed;
  int lastUfoFrame = 8;

  const std::size_t screen_width;
  const std::size_t screen_height;
};

#endif