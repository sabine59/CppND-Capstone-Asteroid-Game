
#include <vector>
#include <string>
#include <memory>
#include "SDL.h"

class CelBody {
 public:

  CelBody(int screen_width, int screen_height, int start_x, int start_y, int width, int height, float v_x, float v_y, std::string path, Uint32 timeOfAppearance)
      :_screen_width(screen_width), _screen_height(screen_height),  _velocity_x(v_x), _velocity_y(v_y), filepath(path), _timeOA(timeOfAppearance) {
        	rect.w = width;
            rect.h = height;
            rect.x = start_x;
            rect.y = start_y;
        }
  ~CelBody();
  bool _isOnStage = false;
  bool _expectedOnStage = true;
  SDL_Rect rect;
  std::string filepath;
  Uint32 GetTimeOA() { return _timeOA; }
  void Update(int xpos_ufo) { this->UpdatePosition(xpos_ufo); };
  
 private:
  void UpdatePosition(int xpos_ufo);
  Uint32 _timeOA;
  int _screen_width;
  int _screen_height;
  float _velocity_x;
  float _velocity_y;
  double growing=0;
};


