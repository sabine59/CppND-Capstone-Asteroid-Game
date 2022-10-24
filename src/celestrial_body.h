
#include <vector>
#include <string>
#include <memory>
#include "SDL.h"

class CelBody {
 public:

  CelBody(int screen_width, int screen_height, float start_x, float start_y, float size, float v_x, float v_y, std::string path, Uint32 timeOfAppearance)
      :_screen_width(screen_width), _screen_height(screen_height),  _velocity_x(v_x), _velocity_y(v_y), filepath(path), _timeOA(timeOfAppearance) {
            printf(" planet size: %u, startx: %u, starty: %u", (int) size, (int) start_x, (int) start_y);
        	rect.w = (int) size;
            rect.h = (int) size;
            rect.x = (int) start_x;
            rect.y = (int) start_y;
            _growing_rect_y = (int) start_y;
        }
  ~CelBody();
  int _screen_width;
  int _screen_height;
  float _velocity_x;
  float _velocity_y;
  bool _isOnStage = false;
  bool _expectedOnStage = true;
  SDL_Rect rect;
  std::string filepath;
  Uint32 GetTimeOA() { return _timeOA; }
  virtual void Update(SDL_Rect ufo_rect) { this->UpdatePosition(ufo_rect); };
  
 private:
  void UpdatePosition(SDL_Rect ufo_rect);
  Uint32 _timeOA;
  float _vel_x=0;
  float _vel_y=0;
  int _growing_rect_y;
  double _growing=0;
  int _growing_count=0;
};


