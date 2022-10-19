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
/*  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  } */

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
        
  const char *image_path = "./images/asteroid4_ergebnis.bmp";
  image = SDL_LoadBMP(image_path);
        


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
        
  // load the textures for the ufo normal appearance frames
  for (std::string image_path : Ufo::normal_frame_files) {
    image = SDL_LoadBMP(image_path.c_str());
    if (!image) {
    	printf("Failed to load image at %s: %s\n", image_path.c_str(), SDL_GetError());
    	return;
  	}
    
    	printf("Loaded surface image  %s\r\n", image_path.c_str());
    SDL_Texture * ufo_Frame = SDL_CreateTextureFromSurface(sdl_renderer, image);
    if (!ufo_Frame) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture ufo_Frame from surface %s: %s", image_path.c_str(), SDL_GetError());
        return;
    }
    
    	printf("Created texture  %s\r\n", image_path.c_str());
    SDL_FreeSurface(image);
    _normal_frames.emplace_back(std::make_unique<SDL_Texture *> (ufo_Frame));
 
  }
        
  // load the textures for the ufo firing appearance frames
  for (std::string image_path : Ufo::firing_frame_files) {
    image = SDL_LoadBMP(image_path.c_str());
    if (!image) {
    	printf("Failed to load image at %s: %s\n", image_path.c_str(), SDL_GetError());
    	return;
  	}
    
    	printf("Loaded surface image  %s\r\n", image_path.c_str());
    SDL_Texture * ufo_Frame = SDL_CreateTextureFromSurface(sdl_renderer, image);
    if (!ufo_Frame) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture ufo_Frame from surface %s: %s", image_path.c_str(), SDL_GetError());
        return;
    }
    
    	printf("Created texture  %s\r\n", image_path.c_str());
    SDL_FreeSurface(image);
    _firing_frames.emplace_back(std::make_unique<SDL_Texture *> (ufo_Frame));
 
  }


speed = 5;


/* Make sure to eventually release the surface resource */

        
        SDL_version linked;
        SDL_GetVersion(&linked);
SDL_Log("But we are linking against SDL version %u.%u.%u.\n",
       linked.major, linked.minor, linked.patch);
}

Renderer::~Renderer() {
  SDL_DestroyTexture(asteroid1);
 

  SDL_DestroyWindow(sdl_window);
  //SDL_Quit();
}

void Renderer::Render(Snake const snake, SDL_Point const &food, Ufo ufo) {
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
  
  lastUfoFrame++;
  if (lastUfoFrame == 9) 
    lastUfoFrame =0;

  int fireFrameCount = 9;
  if (!ufo.isFiring) {
    SDL_RenderCopy(sdl_renderer, *(_normal_frames).at(lastUfoFrame).get(), NULL, &ufo.rect_ufo);
    fireFrameCount = 9;
  } else {
    if (fireFrameCount-- >1) {
    	SDL_RenderCopy(sdl_renderer, *(_firing_frames).at(lastUfoFrame).get(), NULL, &ufo.rect_ufo);
    } else {
      ufo.isFiring = false;
    }
  }
 


    
  // test other geometrical forms end
  
  // Update Screen
  SDL_RenderPresent(sdl_renderer);
  
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
