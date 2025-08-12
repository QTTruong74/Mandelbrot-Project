#ifndef ZOOM_H
#define ZOOM_H

/** This is the context that contains all of the logical game state */

struct viewport;

typedef struct viewport view;

/**
 * These are the functions that are responsible for zooming in, out,
 * 
 * moving to the left, right and moving up, down.
 * 
 * @param viewport the pointer to the struct viewport.
 */
void zoom_in(view *viewport);

void zoom_out(view *viewport);

void move_left(view *viewport);

void move_right(view *viewport);

void move_up(view *viewport);

void move_down(view *viewport);

#endif