#include <vector>
#include <string>
#include <memory>
#include "SDL.h"
#include "celestrial_body.h"

class Asteroid : public CelBody {
 public:

  Asteroid(int screen_width, int screen_height, float start_x, float start_y, float size, float v_x, float v_y, std::string path, Uint32 timeOfAppearance)
      : CelBody(screen_width, screen_height, start_x, start_y, size, v_x, v_y, path, timeOfAppearance) 
  { 
     _start_x = start_x;
     _start_y = start_y;
     if (path.compare("./images/fuelcann.bmp") == 0) {
      energieBonus = 100;
     } else if (path.compare("./images/zimtstern.bmp") == 0)  {
      energieBonus = 30;
     } else if (path.compare("./images/java.bmp") == 0)  {
       energieBonus = 50;
     } else {
      energieBonus = 0;
     }
  }

  ~Asteroid();

  void Update(Ufo &ufo) override { this->UpdatePosition1(ufo); }
  void ReInit(float sfY, int randy)
  {
      _vel_x = 0;
      _vel_y = 0;
      isHit = false;
      alive = true;
      _hadNoIntersection = true;
      wasAlreadyOnStage = false;
      rect.x = (int) _start_x;
      rect.y =  sfY * _screen_height * randy / 100;
       printf("asteroid reinit rext.x: %d, rect.y %d \n", rect.x, rect.y);
  }
  //void Update(SDL_Rect ufo_rect, SDL_Rect ufo_fire_rect, int &hitCounter, int &enegieCounter, bool ufo_isFiring)  { this->UpdatePosition1(ufo_rect, ufo_fire_rect, hitCounter, enegieCounter, ufo_isFiring); };
  bool isHit = false;
  bool alive = true;
  bool wasAlreadyOnStage = false;
  int energieBonus = 0;
  
 private:
  //void UpdatePosition1(SDL_Rect ufo_rect, SDL_Rect ufo_fire_rect, int &hitCounter, int &enegieCounter, bool ufo_isFiring);

  void UpdatePosition1(Ufo &ufo);

  float _vel_x=0;
  float _vel_y=0;
  float _start_x;
  float _start_y;
  bool _hadNoIntersection=true;

};