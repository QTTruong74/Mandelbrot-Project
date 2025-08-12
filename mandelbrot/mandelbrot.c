#include <SDL2/SDL.h>
#include <stddef.h>
#include <stdlib.h>
#include "compute.h"
#include "mandelbrot_draw.h"
#include "zoom.h"
#include "save_and_restore.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
    SDL_RenderSetLogicalSize(renderer, WIDTH, HEIGHT);

    view viewport;
    viewport_init(&viewport);

    while (1) {
        SDL_RenderPresent(renderer);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return 0;
            }
            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        return 0;
                    case SDLK_q: // Zoom in
                        viewport.max_iterations += 20;
                        zoom_in(&viewport);
                        break;
                    case SDLK_e: // Zoom out
                        viewport.max_iterations -= 10;
                        zoom_out(&viewport);
                        break;
                    case SDLK_a: // Move to the left
                        viewport.max_iterations += 20;
                        move_left(&viewport);
                        break;
                    case SDLK_d: // Move to the right
                        viewport.max_iterations += 20;
                        move_right(&viewport);
                        break;
                    case SDLK_w: // Move up
                        viewport.max_iterations += 20;
                        move_up(&viewport);
                        break;
                    case SDLK_s: // Move down
                        viewport.max_iterations += 20;
                        move_down(&viewport);
                        break;
                    case SDLK_x: // Save configuration
                        save_configuration(&viewport);
                        break;
                    case SDLK_z: // Restore configuration
                        restore_configuration(&viewport);
                        break;
                }
            }
        }
        mandelbrot_draw(renderer, &viewport);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
