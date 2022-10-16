#include "renderer.h"
#include <iostream>
#include <string>


Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }
  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  } 
  //sdl_window_surface =  SDL_GetWindowSurface(sdl_window);
        
  const char *image_path = "./asteroid4_ergebnis.bmp";
  image = SDL_LoadBMP(image_path);
// load the textures
/* Let the user know if the file failed to load */
  if (!image) {
    printf("Failed to load image at %s: %s\n", image_path, SDL_GetError());
    return;
  }
    asteroid1 = SDL_CreateTextureFromSurface(sdl_renderer, image);
    if (!asteroid1) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create textureasteroid1 from surface: %s", SDL_GetError());
        return;
    }
  SDL_FreeSurface(image);

  image_path = "./Ufo_F1.bmp";
  image1_f1 = SDL_LoadBMP(image_path);
// load the textures
/* Let the user know if the file failed to load */
  if (!image1_f1) {
    printf("Failed to load image at %s: %s\n", image_path, SDL_GetError());
    return;
  }
    ufo_Frame1 = SDL_CreateTextureFromSurface(sdl_renderer, image1_f1);
    if (!ufo_Frame1) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture ufo_Frame1 from surface: %s", SDL_GetError());
        return;
    }
  SDL_FreeSurface(image1_f1);
        
  image_path = "./Ufo_F2.bmp";
  image1_f2 = SDL_LoadBMP(image_path);
// load the textures
/* Let the user know if the file failed to load */
  if (!image1_f2) {
    printf("Failed to load image at %s: %s\n", image_path, SDL_GetError());
    return;
  }
    ufo_Frame2 = SDL_CreateTextureFromSurface(sdl_renderer, image1_f2);
    if (!ufo_Frame2) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture ufo_Frame2 from surface: %s", SDL_GetError());
        return;
    }
  SDL_FreeSurface(image1_f2);
        
          image_path = "./Ufo_F3.bmp";
  image1_f3 = SDL_LoadBMP(image_path);
// load the textures
/* Let the user know if the file failed to load */
  if (!image1_f3) {
    printf("Failed to load image at %s: %s\n", image_path, SDL_GetError());
    return;
  }
    ufo_Frame3 = SDL_CreateTextureFromSurface(sdl_renderer, image1_f3);
    if (!ufo_Frame3) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture ufo_Frame3 from surface: %s", SDL_GetError());
        return;
    }
  SDL_FreeSurface(image1_f3);
        
          image_path = "./Ufo_F4.bmp";
  image1_f4 = SDL_LoadBMP(image_path);
// load the textures
/* Let the user know if the file failed to load */
  if (!image1_f4) {
    printf("Failed to load image at %s: %s\n", image_path, SDL_GetError());
    return;
  }
    ufo_Frame4 = SDL_CreateTextureFromSurface(sdl_renderer, image1_f4);
    if (!ufo_Frame4) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture ufo_Frame4 from surface: %s", SDL_GetError());
        return;
    }
  SDL_FreeSurface(image1_f4);
        
                  image_path = "./Ufo_F5.bmp";
  image1_f5 = SDL_LoadBMP(image_path);
// load the textures
/* Let the user know if the file failed to load */
  if (!image1_f5) {
    printf("Failed to load image at %s: %s\n", image_path, SDL_GetError());
    return;
  }
    ufo_Frame5 = SDL_CreateTextureFromSurface(sdl_renderer, image1_f5);
    if (!ufo_Frame5) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture ufo_Frame5 from surface: %s", SDL_GetError());
        return;
    }
  SDL_FreeSurface(image1_f5);
        
                  image_path = "./Ufo_F6.bmp";
  image1_f6 = SDL_LoadBMP(image_path);
// load the textures
/* Let the user know if the file failed to load */
  if (!image1_f6) {
    printf("Failed to load image at %s: %s\n", image_path, SDL_GetError());
    return;
  }
    ufo_Frame6 = SDL_CreateTextureFromSurface(sdl_renderer, image1_f6);
    if (!ufo_Frame6) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture ufo_Frame6 from surface: %s", SDL_GetError());
        return;
    }
  SDL_FreeSurface(image1_f6);
        
                  image_path = "./Ufo_F7.bmp";
  image1_f7 = SDL_LoadBMP(image_path);
// load the textures
/* Let the user know if the file failed to load */
  if (!image1_f7) {
    printf("Failed to load image at %s: %s\n", image_path, SDL_GetError());
    return;
  }
    ufo_Frame7 = SDL_CreateTextureFromSurface(sdl_renderer, image1_f7);
    if (!ufo_Frame7) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture ufo_Frame7 from surface: %s", SDL_GetError());
        return;
    }
  SDL_FreeSurface(image1_f7);
        
                  image_path = "./Ufo_F8.bmp";
  image1_f8 = SDL_LoadBMP(image_path);
// load the textures
/* Let the user know if the file failed to load */
  if (!image1_f8) {
    printf("Failed to load image at %s: %s\n", image_path, SDL_GetError());
    return;
  }
    ufo_Frame8 = SDL_CreateTextureFromSurface(sdl_renderer, image1_f8);
    if (!ufo_Frame8) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture ufo_Frame8 from surface: %s", SDL_GetError());
        return;
    }
  SDL_FreeSurface(image1_f8);
        
                  image_path = "./Ufo_F9.bmp";
  image1_f9 = SDL_LoadBMP(image_path);
// load the textures
/* Let the user know if the file failed to load */
  if (!image1_f9) {
    printf("Failed to load image at %s: %s\n", image_path, SDL_GetError());
    return;
  }
    ufo_Frame9 = SDL_CreateTextureFromSurface(sdl_renderer, image1_f9);
    if (!ufo_Frame9) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture ufo_Frame9 from surface: %s", SDL_GetError());
        return;
    }
  SDL_FreeSurface(image1_f9);
speed = 5;


/* Make sure to eventually release the surface resource */

        
        SDL_version linked;
        SDL_GetVersion(&linked);
SDL_Log("But we are linking against SDL version %u.%u.%u.\n",
       linked.major, linked.minor, linked.patch);
}

Renderer::~Renderer() {
  SDL_DestroyTexture(asteroid1);
  SDL_DestroyTexture(ufo_Frame1);
   SDL_DestroyTexture(ufo_Frame2);
   SDL_DestroyTexture(ufo_Frame3);
   SDL_DestroyTexture(ufo_Frame4);
   SDL_DestroyTexture(ufo_Frame5);
   SDL_DestroyTexture(ufo_Frame6);
   SDL_DestroyTexture(ufo_Frame7);
   SDL_DestroyTexture(ufo_Frame8);
   SDL_DestroyTexture(ufo_Frame9);
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Snake const snake, SDL_Point const &food, Ufo const ufo) {
  SDL_Rect block;
  SDL_Rect block1;
  SDL_Rect block2;


  
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;
  
  block1.w = screen_width / grid_width*3;
  block1.h = screen_height / grid_height/3;

  block2.w = screen_width / grid_width/3;
  block2.h = screen_height / grid_height*3;
  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  for (SDL_Point const &point : snake.body) {
    block.x = point.x * block.w;
    block.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block);
  }

  // Render snake's head
  block1.x = static_cast<int>(snake.head_x)* block.w;
  block1.y = static_cast<int>(snake.head_y) * block.h;
  
  block2.x = block1.x+block.w;
  block2.y = block1.y -(block.w);
  if (snake.alive) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block1);
  SDL_RenderFillRect(sdl_renderer, &block2);

  // test other geometrical forms start
        SDL_Rect rect;
        rect.w = 64;
        rect.h = 64;
  //speed = speed+5;
  rect.x = block.x +speed;
  rect.y = speed;
  SDL_RenderCopy(sdl_renderer, asteroid1, NULL, &rect);
         SDL_Rect rect_ufo;
        rect.w = 164;
        rect.h = 70;
  //speed = speed+5;
  rect.x = ufo.x_pos;
  rect.y = ufo.y_pos;
  switch (lastUfoFrame) {
    case 9:
       SDL_RenderCopy(sdl_renderer,ufo_Frame1, NULL, &rect);
      lastUfoFrame = 1;
      break;
         case 1:
       SDL_RenderCopy(sdl_renderer,ufo_Frame2, NULL, &rect);
      lastUfoFrame = 2;
      break;
         case 2:
       SDL_RenderCopy(sdl_renderer,ufo_Frame3, NULL, &rect);
      lastUfoFrame = 3;
      break;
         case 3:
       SDL_RenderCopy(sdl_renderer,ufo_Frame4, NULL, &rect);
      lastUfoFrame = 4;
      break;
      
               case 4:
       SDL_RenderCopy(sdl_renderer,ufo_Frame5, NULL, &rect);
      lastUfoFrame = 5;
      break;
      
               case 5:
       SDL_RenderCopy(sdl_renderer,ufo_Frame6, NULL, &rect);
      lastUfoFrame = 6;
      break;
      
               case 6:
       SDL_RenderCopy(sdl_renderer,ufo_Frame7, NULL, &rect);
      lastUfoFrame = 7;
      break;
      
               case 7:
       SDL_RenderCopy(sdl_renderer,ufo_Frame8, NULL, &rect);
      lastUfoFrame = 8;
      break;
      
               case 8:
       SDL_RenderCopy(sdl_renderer,ufo_Frame9, NULL, &rect);
      lastUfoFrame = 9;
      break;
  }


    
  // test other geometrical forms end
  
  // Update Screen
  SDL_RenderPresent(sdl_renderer);
  
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
