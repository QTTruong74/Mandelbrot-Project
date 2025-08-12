#include "mandelbrot_draw.h"

void zoom_in(view *viewport){
    viewport->min_x *= viewport->zoom_factor;
    viewport->max_x *= viewport->zoom_factor;
    viewport->min_y *= viewport->zoom_factor;
    viewport->max_y *= viewport->zoom_factor;
}

void zoom_out(view *viewport){
    viewport->min_x /= viewport->zoom_factor;
    viewport->max_x /= viewport->zoom_factor;
    viewport->min_y /= viewport->zoom_factor;
    viewport->max_y /= viewport->zoom_factor;
}

void move_left(view *viewport) {
    viewport->center_x -= viewport->move_factor * (viewport->max_x - viewport->min_x);
}

void move_right(view *viewport) {
    viewport->center_x += viewport->move_factor * (viewport->max_x - viewport->min_x);
}

void move_up(view *viewport) {
    viewport->center_y -= viewport->move_factor * (viewport->max_y - viewport->min_y);
}

void move_down(view *viewport) {
    viewport->center_y += viewport->move_factor * (viewport->max_y - viewport->min_y);
}