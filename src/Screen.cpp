#include "Screen.h"

#include <iostream>

#include "SDL2/SDL_video.h"
#include "SDL2/SDL_render.h"

SDL_Window* window;
SDL_Renderer* renderer;
uint8_t running;

void Screen::initScreen() {
    //Make screen running
    running = 1;

    //Init video
    SDL_Init(SDL_INIT_VIDEO);

    //Create a window, centered to middle of screen, with size of 640x480
    window = SDL_CreateWindow("TEST!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    //Create a renderer, to the window, with hardware acceleration, vsync and rendering to texture
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
}

void Screen::exit() {
    //Destroy renderer and window and quit SDL
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    //Free window and renderer
    free(window);
    free(renderer);
}

void Screen::clear() {
    //Clear renderer with black
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

void Screen::update() {
    //Update screen with renderer
    SDL_RenderPresent(renderer);

    //Check and handle event
    checkEvent();
}

void Screen::setColor(const uint8_t r, const uint8_t g, const uint8_t b) {
    SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
}

void Screen::drawRects(const SDL_Rect* rects, const uint8_t count) {
    SDL_RenderDrawRects(renderer, rects, count);
}

void Screen::checkEvent() {
    //Create event and poll it
    SDL_Event e;
    SDL_PollEvent(&e);

    switch(e.type) {
    case SDL_WINDOWEVENT:
        //Is event a window event
        switch(e.window.event) {
        case SDL_WINDOWEVENT_CLOSE:
            running = 0;
            break;

        default:
            break;
        }

        break;
    default:
        break;
    }
}

uint8_t Screen::isRunning() {
    return running;
}