#include <vector>
#include <string>
#include <memory>
#include "SDL.h"
#include "celestrial_body.h"

class Asteroid : public CelBody {
 public:

  Asteroid(int screen_width, int screen_height, float start_x, float start_y, float size, float v_x, float v_y, std::string path, Uint32 timeOfAppearance)
      : CelBody(screen_width, screen_height, start_x, start_y, size, v_x, v_y, path, timeOfAppearance) {}

  ~Asteroid();

  bool isHit = false;

 private:
  void UpdatePosition(SDL_Rect ufo_rect);

  Uint32 _timeOA;
  int _screen_width;
  int _screen_height;
  float _velocity_x;
  float _velocity_y;
  float _vel_x=0;
  float _vel_y=0;


};