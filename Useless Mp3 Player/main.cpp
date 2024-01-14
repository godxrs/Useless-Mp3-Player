#include <SDL.h>
#include <stdio.h>
#include <cmath>
#include <time.h>
#include <cstdlib>
#include "window.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SQUARE_SIZE = 69;  // Adjust square size as needed
const int SQUARE_SPACING = 69 ;  // Spacing between squares (in pixels)
const int centerOffset = (SCREEN_WIDTH - 2 * SQUARE_SIZE - SQUARE_SPACING) / 2;

int randNumGen(int upper, int lower)	// function heading
{										// function body
    return (rand() % (upper - lower + 1)) + lower;
}

int main(int argc, char* argv[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    // Calculate center offsets
    int centerX = (SCREEN_WIDTH - 2 * SQUARE_SIZE - SQUARE_SPACING) / 2;
    int centerY = (SCREEN_HEIGHT - SQUARE_SIZE) / 2;  // Vertically center

    if (!initWindow(window, renderer, "Useless MP3", SCREEN_WIDTH, SCREEN_HEIGHT)) {
        return 1;
    }

    // Clear the renderer
   /* SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);*/
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw the squares, centered using standard SDL_Rect functions
    SDL_Rect square1Rect = { centerX, centerY, SQUARE_SIZE, SQUARE_SIZE };
    SDL_Rect square2Rect = { centerX + SQUARE_SIZE + SQUARE_SPACING, centerY, SQUARE_SIZE, SQUARE_SIZE };

    SDL_SetRenderDrawColor(renderer, 150, 0, 0, 255);  // Green
    SDL_RenderFillRect(renderer, &square1Rect);
    SDL_RenderFillRect(renderer, &square2Rect);

    SDL_RenderPresent(renderer);

    bool quit = false;
    SDL_Event event;

    while (!quit) {
        
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN){
                // Check if the click is within square1Rect
                int mouseX, mouseY, number;
                SDL_GetMouseState(&mouseX, &mouseY);
                SDL_Point mousePoint = { mouseX, mouseY };
                SDL_PointInRect(&mousePoint, &square1Rect);
                    // Move the square to a new position
                    number = randNumGen(100, 1);
                    square1Rect.x = (number % (SCREEN_WIDTH - SQUARE_SIZE));  // Random horizontal position
                    square1Rect.y = (number % (SCREEN_HEIGHT - SQUARE_SIZE)); // Random vertical position

            }

        }

    }
    closeWindow(window, renderer);
    return 0;
}
