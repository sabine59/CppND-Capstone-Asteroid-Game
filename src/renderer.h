#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "ufo.h"



class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food, Ufo const ufo);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  SDL_Surface *sdl_window_surface;
  SDL_Surface *image;
  SDL_Surface *image1_f1;
  SDL_Surface *image1_f2;
  SDL_Surface *image1_f3;
  SDL_Surface *image1_f4;
  SDL_Surface *image1_f5;
  SDL_Surface *image1_f6;
  SDL_Surface *image1_f7;
  SDL_Surface *image1_f8;
  SDL_Surface *image1_f9;
  SDL_Texture *asteroid1;
  SDL_Texture *ufo_Frame1;
  SDL_Texture *ufo_Frame2;
  SDL_Texture *ufo_Frame3;
  SDL_Texture *ufo_Frame4;
  SDL_Texture *ufo_Frame5;
  SDL_Texture *ufo_Frame6;
  SDL_Texture *ufo_Frame7;
  SDL_Texture *ufo_Frame8;
  SDL_Texture *ufo_Frame9;
  int speed;
  int lastUfoFrame = 9;
  
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif