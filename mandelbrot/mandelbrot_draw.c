#include <SDL2/SDL.h>
#include "mandelbrot_draw.h"
#include "compute.h"

void viewport_init(view *viewport) {
    viewport->min_x = -2.0;
    viewport->max_x = 2.0;
    viewport->min_y = -2.0;
    viewport->max_y = 2.0;
    viewport->center_x = 0;
    viewport->center_y = 0;
    viewport->zoom_factor = 0.9;
    viewport->move_factor = 0.2;
    viewport->max_iterations = 200;
}

void mandelbrot_draw(SDL_Renderer *renderer, view *viewport) {
    comp *current = (struct complex*)malloc(sizeof(struct complex));
    if(current == NULL){
        fprintf(stderr, "Memory allocation failure.\n"); // Handle memory allocation failure
        return;
    }
    // Adjust the range of x and y based on the desired region
    for (int x = 0; x < WIDTH; x++) { // x is a
        for (int y = 0; y < HEIGHT; y++) { // y is b

            current->a = viewport->center_x + map(x, 0, WIDTH, viewport->min_x, viewport->max_x);
            current->b = viewport->center_y + map(y, 0, HEIGHT, viewport->min_y, viewport->max_y);

            int n = multiply_comp(current, viewport);
            int bright = map(n, 0, viewport->max_iterations, 0, 255);

            if (n == viewport->max_iterations || bright < 20) {
                bright = 0;
            }

            int green = map(bright * bright, 0, 6502, 0, 255);
            int blue = bright;
            int red = map(sqrt(bright), 0, 255, 0, 255);
            SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
    free(current);
}
