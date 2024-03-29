#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height)
    : screen_width(screen_width),
      screen_height(screen_height)
{

  rect_b1.w = screen_width;
  rect_b1.h = screen_height;
  rect_b1.x = 0;
  rect_b1.y = 0;
  rect_b2.w = screen_width;
  rect_b2.h = screen_height;
  rect_b2.x = screen_width;
  rect_b2.y = 0;
  xpos_factor = 0;

  // Create Window
  sdl_window = SDL_CreateWindow("Asteroid Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window)
  {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }
  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer)
  {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // load the texture for the star background
  const char *image_path = "./images/bgstars_1.bmp";
  image = SDL_LoadBMP(image_path);
  if (!image)
  {
    printf("Failed to load image at %s: %s\n", image_path, SDL_GetError());
    return;
  }
  background = SDL_CreateTextureFromSurface(sdl_renderer, image);
  if (!background)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create textureasteroid1 from surface: %s", SDL_GetError());
    return;
  }
  SDL_FreeSurface(image);

  // load texture from home planet for the end of game
  image_path = "./images/home.bmp";
  image = SDL_LoadBMP(image_path);
  if (!image)
  {
    printf("Failed to load image at %s: %s\n", image_path, SDL_GetError());
    return;
  }
  home = SDL_CreateTextureFromSurface(sdl_renderer, image);
  if (!background)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create textureasteroid1 from surface: %s", SDL_GetError());
    return;
  }
  SDL_FreeSurface(image);
  // load the textures for the ufo normal appearance frames
  for (std::string image_path : Ufo::normal_frame_files)
  {
    createTextureFromFile(image_path, 0);
  }

  // load the textures for the ufo firing appearance frames
  for (std::string image_path : Ufo::firing_frame_files)
  {
    createTextureFromFile(image_path, 1);
  }

  /* Make sure to eventually release the surface resource */

  SDL_version linked;
  SDL_GetVersion(&linked);
  SDL_Log("But we are linking against SDL version %u.%u.%u.\n",
          linked.major, linked.minor, linked.patch);
}

Renderer::~Renderer()
{
  SDL_DestroyTexture(background);
  SDL_DestroyTexture(home);
  // Although the vector<unique_ptr> is destroyed automatically,
  // the SDL lib requires the destruction of the SDL_texture.
  // As the lib is not written in c++, there is no destructor,
  // which can be executed automatically with the destruction of the smartpointers.
  // So therefore here: destruct texture frames of the ufo
  while (_normal_frames.size() > 0)
  {
    SDL_DestroyTexture((SDL_Texture *)_normal_frames.back().get());
    _normal_frames.pop_back();
  }
  while (_firing_frames.size() != 0)
  {
    SDL_DestroyTexture((SDL_Texture *)_firing_frames.back().get());
    _firing_frames.pop_back();
  }
  // Desatruct textures of the remaining planets.
  while (_celBodyTextures.size() != 0)
  {
    SDL_DestroyTexture((SDL_Texture *)_celBodyTextures.back().get());
    _celBodyTextures.pop_back();
  }
  // Desatruct textures of the remaining asteroids.
  while (_asteroidTextures.size() != 0)
  {
    SDL_DestroyTexture((SDL_Texture *)_asteroidTextures.back().get());
    _asteroidTextures.pop_back();
  }
  SDL_DestroyWindow(sdl_window);
  // SDL_Quit();
}

void Renderer::createTextureFromFile(std::string path, int objectType)
{
  SDL_Surface *imageObject = SDL_LoadBMP(path.c_str());
  if (!imageObject)
  {
    printf("Failed to load image at %s: %s\n", path.c_str(), SDL_GetError());
    return;
  }

  // printf("Loaded surface image  %s\r\n", image_path.c_str());
  SDL_Texture *frame = SDL_CreateTextureFromSurface(sdl_renderer, imageObject);
  if (!frame)
  {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture ufo_Frame from surface %s: %s", path.c_str(), SDL_GetError());
    return;
  }

  // printf("Created texture  %s\r\n", image_path.c_str());
  SDL_FreeSurface(imageObject);
  if (objectType == 0)
    _normal_frames.emplace_back(std::make_unique<SDL_Texture *>(frame));
  else if (objectType == 1)
    _firing_frames.emplace_back(std::make_unique<SDL_Texture *>(frame));
  else if (objectType == 2)
  {
    _celBodyTextures.emplace_back(std::make_unique<SDL_Texture *>(frame));
    // printf("Texture from planet created \r\n");
  }
  else if (objectType == 3)
  {
    _asteroidTextures.emplace_back(std::make_unique<SDL_Texture *>(frame));
    // printf("Texture from asteroid created \r\n");
  }
}

void Renderer::Render(Ufo &ufo, std::vector<std::shared_ptr<CelBody *>> &planets, std::vector<std::shared_ptr<Asteroid *>> &asteroids, bool gameOver)
{

  // Clear screen
  // SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);
  if (!gameOver)
  {
    // Render the background. The texture is horizontally scrolled in an endless loop.
    xpos_factor++;
    if (xpos_factor >= 9)
    {
      rect_b1.x--;
      if (rect_b1.x + screen_width <= 0)
        rect_b1.x = screen_width - 1;
      rect_b2.x--;
      if (rect_b2.x + screen_width <= 0)
        rect_b2.x = screen_width - 1;
      xpos_factor = 0;
    }
    SDL_RenderCopy(sdl_renderer, background, NULL, &rect_b1);
    SDL_RenderCopy(sdl_renderer, background, NULL, &rect_b2);

    // render planets
    if (!_celBodyTextures.empty())
    {
      // printf("_celBody not empty \n");

      for (unsigned int i = _celBodyTextures.size(); i > 0; i--)
      {
        if (*(_celBodyTextures).at(i - 1).get() && (*(planets).at(i - 1).get())->_isOnStage)
        {
          SDL_RenderCopy(sdl_renderer, *(_celBodyTextures).at(i - 1).get(), NULL, &(*(planets).at(i - 1).get())->rect);
          // printf("render planet %u \n", i-1);
        }
        else
        {
          // Destroy the planet and its texture as soon as it has left the stage
          planets.erase(planets.begin() + (i - 1));
          // printf("erase planet %u \n", i-1);
          SDL_DestroyTexture(*(_celBodyTextures).at(i - 1).get());
          _celBodyTextures.erase(_celBodyTextures.begin() + (i - 1));
          break;
        }
      }
    }

    // render the asteroids
    if (!_asteroidTextures.empty())
    {
      // printf("_celBody not empty \n");

      for (unsigned int i = _asteroidTextures.size(); i > 0; i--)
      {
        if (*(_asteroidTextures).at(i - 1).get() && (*(asteroids).at(i - 1).get())->_isOnStage)
        {

          if ((*(asteroids).at(i - 1).get())->alive)
            // SDL_SetTextureColorMod(*(_asteroidTextures).at(i - 1).get(), 0xc0, 0x00, 0x00);
            SDL_RenderCopy(sdl_renderer, *(_asteroidTextures).at(i - 1).get(), NULL, &(*(asteroids).at(i - 1).get())->rect);
        }
        /*     else
            {
              // Destroy the asteroids and itheir texture as soon as it has left the stage
              asteroids.erase(asteroids.begin() + (i - 1));
              // printf("erase planet %u \n", i-1);
              SDL_DestroyTexture(*(_asteroidTextures).at(i - 1).get());
              _asteroidTextures.erase(_asteroidTextures.begin() + (i - 1));
              break;
            } */
      }
    }
  }
  else
  {
    // game over -> show the alien's home planet
    SDL_Rect home_rect;
    home_rect.x = 0;
    home_rect.y = 0;
    home_rect.w = screen_width;
    home_rect.h = screen_height;
    SDL_RenderCopy(sdl_renderer, home, NULL, &home_rect);
  }

  // render ufo frames
  lastUfoFrame++;
  if (lastUfoFrame == 9)
    lastUfoFrame = 0;

  int fireFrameCount = 9;
  if (!ufo.isFiring)
  {
    if (!ufo.alive)
      SDL_SetTextureColorMod(*(_normal_frames).at(lastUfoFrame).get(), 0xc0, 0x00, 0x00);

    SDL_RenderCopy(sdl_renderer, *(_normal_frames).at(lastUfoFrame).get(), NULL, &ufo.rect_ufo);
    fireFrameCount = 9;
  }
  else
  {
    if (fireFrameCount-- > 1)
    {
      SDL_RenderCopy(sdl_renderer, *(_firing_frames).at(lastUfoFrame).get(), NULL, &ufo.rect_ufo);
    }
    else
    {
      ufo.isFiring = false;
    }
  }
  // Draw the fire rect to see its range
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderDrawRect(sdl_renderer, &ufo.ufo_fire_rect);
  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int energie, int hits, int fps, bool gameOver)
{
  if (!gameOver)
  {
    if (energie > 0)
    {
      std::string title{"Ufo Energie: " + std::to_string(energie) + " , Ufo Hits: " + std::to_string(hits) + " , FPS: " + std::to_string(fps)};
      SDL_SetWindowTitle(sdl_window, title.c_str());
    }
    else
    {
      std::string title{" GAME OVER! YOU HAVE LOST! Ufo energie: " + std::to_string(energie) + " , FPS: " + std::to_string(fps)};
      SDL_SetWindowTitle(sdl_window, title.c_str());
    }
  }
  else
  {
    if (energie > 0)
    {
      std::string title{"GAME OVER! YOU HAVE WON! Ufo Energie: " + std::to_string(energie) + " , Ufo Hits: " + std::to_string(hits) + " , FPS: " + std::to_string(fps)};
      SDL_SetWindowTitle(sdl_window, title.c_str());
    }
    else
    {
      std::string title{" GAME OVER! YOU HAVE LOST! Ufo energie: " + std::to_string(energie) + " , FPS: " + std::to_string(fps)};
      SDL_SetWindowTitle(sdl_window, title.c_str());
    }
  }
}
