#include "TileEdit.h"
#include "Screen.h"

#include "SDL2/SDL.h"

const SDL_Rect r[] = {{8, 8 + (64 + 8) * 0, 64, 64}, 
                      {8, 8 + (64 + 8) * 1, 64, 64}, 
                      {8, 8 + (64 + 8) * 2, 64, 64}};

void TileEdit::start() {
    Screen::initScreen();

    while(Screen::isRunning()) {
        Screen::clear();

        //Draw a line from one corner to the other
        Screen::setColor(0xFF, 0x00, 0x00);
        Screen::drawRects(r, 3);

        Screen::update();
    }

    Screen::exit();
}