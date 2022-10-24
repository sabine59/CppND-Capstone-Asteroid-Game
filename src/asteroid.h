#include <vector>
#include <string>
#include <memory>
#include "SDL.h"
#include "celestrial_body.h"

class Asteroid : public CelBody {
 public:

  Asteroid(int screen_width, int screen_height, float start_x, float start_y, float size, float v_x, float v_y, std::string path, Uint32 timeOfAppearance)
      : CelBody(screen_width, screen_height, start_x, start_y, size, v_x, v_y, path, timeOfAppearance) { }

  ~Asteroid();

  void Update(SDL_Rect ufo_rect) override { this->UpdatePosition1(ufo_rect); };
  bool isHit = false;

 private:
  void UpdatePosition1(SDL_Rect ufo_rect);

  float _vel_x=0;
  float _vel_y=0;


};