#pragma once

#include <stdint.h>

#include "SDL2/SDL.h"

namespace Screen {
    void initScreen();
    void exit();

    void update();
    void clear();
    void checkEvent();

    void setColor(const uint8_t r, const uint8_t g, const uint8_t b);
    void drawRects(const SDL_Rect* rects, const uint8_t count);

    uint8_t isRunning();
}