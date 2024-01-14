#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>

bool initWindow(SDL_Window*& window, SDL_Renderer*& renderer, const char* title, int width, int height);
void closeWindow(SDL_Window*& window, SDL_Renderer*& renderer);

#endif