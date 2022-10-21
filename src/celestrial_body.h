
#include <vector>
#include <string>
#include <memory>
#include "SDL.h"

class CelBody {
 public:

  CelBody(int screen_width, int screen_height, int start_x, int start_y, int size, float v_x, float v_y, std::string path, Uint32 timeOfAppearance)
      :_screen_width(screen_width), _screen_height(screen_height),  _velocity_x(v_x), _velocity_y(v_y), filepath(path), _timeOA(timeOfAppearance) {
        	rect.w = size;
            rect.h = size;
            rect.x = start_x;
            rect.y = start_y;
        }
  ~CelBody();
  bool _isOnStage = false;
  bool _expectedOnStage = true;
  SDL_Rect rect;
  std::string filepath;
  Uint32 GetTimeOA() { return _timeOA; }
  void Update(SDL_Rect ufo_rect) { this->UpdatePosition(ufo_rect); };
  
 private:
  void UpdatePosition(SDL_Rect ufo_rect);
  Uint32 _timeOA;
  int _screen_width;
  int _screen_height;
  float _velocity_x;
  float _velocity_y;
  float _vel_x=0;
  float _vel_y=0;
  double growing=0;
};


