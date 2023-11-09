#ifndef UFO_H
#define UFO_H

#include <vector>
#include <string>
#include <memory>
#include "SDL.h"

class Ufo
{
public:
    // enum class Direction { kUp, kDown, kLeft, kRight, none };
    enum class Direction
    {
        kUp,
        kDown,
        none
    };
    Ufo(int screen_width, int screen_height, const float screenFactorX, const float screenFactorY)
        : _screen_width(screen_width), _screen_height(screen_height)
    {
        rect_ufo.w = (int)164.0 * screenFactorX;
        rect_ufo.h = (int)70.0 * screenFactorX;
        rect_ufo.x = screen_width / 3;
        rect_ufo.y = screen_height / 2;
    }

    void Update();

    Direction direction = Direction::none;

    bool alive{true};
    float speed{6.5f};
    SDL_Rect rect_ufo;
    SDL_Rect ufo_fire_rect;
    ;
    bool isFiring = false;
    bool hasFired = false;
    int hitCounter = 0;
    int energieCounter = 100;
    static std::vector<std::string> normal_frame_files;
    static std::vector<std::string> firing_frame_files;

private:
    void UpdatePosition();
    int _screen_width;
    int _screen_height;
};

#endif