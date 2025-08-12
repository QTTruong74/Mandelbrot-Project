#ifndef MANDELBROT_DRAW_H
#define MANDELBROT_DRAW_H
#include <SDL2/SDL.h>

/** This is the context that is responsible for drawing the mandelbrot set */

/** This is the structure of viewport, which is the region of the complex plane that is currently being displayed*/
struct viewport {
    double min_x; /**< The minimum value of the x axes */
    double max_x; /**< The maximum value of the x axes */
    double min_y; /**< The minimum value of the y axes */
    double max_y; /**< The maximum value of the y axes */
    double center_x; /**< The center x-coorinate */
    double center_y; /**< The center y-coorinate */
    double zoom_factor; /**< The factor for zooming in and out */
    double move_factor; /**< The factor for moving up, down, to the left and right */
    int max_iterations; /**< The maximum number of iterations is performed to determine whether a given complex number is in the set */
};

typedef struct viewport view;

/**
 * This is the function that initializes the struct viewport.
 * 
 * @param viewport the pointer to the struct viewport.
*/
void viewport_init(view *viewport);

/**
 * This is the function that draws the mandelbrot set.
 * 
 * @param renderer the pointer to the struct SDL_Renderer.
 * 
 * @param viewport the pointer to the struct viewport.
*/
void mandelbrot_draw(SDL_Renderer *renderer, view *viewport);

#endif