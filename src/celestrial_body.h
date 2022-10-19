
#include <vector>
#include <string>
#include <memory>
#include "SDL.h"

class CelBody {
 public:

  CelBody(float start_x, float start_y, float width, float height, float v_x, float v_y, std::string path, Uint32 timeOfAppearance)
      : _velocity_x(v_x), _velocity_y(v_y), filepath(path.c_str()), _timeOA(timeOfAppearance) {
        	rect.w = width;
            rect.h = height;
            rect.x = start_x;
            rect.y = start_y;
        }
  ~CelBody();
  
  SDL_Rect rect;
  std::string filepath;


 private:
  void UpdatePosition();
  Uint32 _timeOA;
  bool _isOnStage = false;
  int _screen_width;
  int _screen_height;
  float _velocity_x;
  float _velocity_y;
};

