#ifndef SAVE_AND_RESTORE_H
#define SAVE_AND_RESTORE_H

/** This is the context that is responsible for saving and restoring the configuration */


struct viewport;

typedef struct viewport view;

/**
 * This is the function that saves the configuration.
 * 
 * @param viewport the pointer to the struct viewport.
*/
void save_configuration(const view *viewport);

/**
 * This is the function that loads or restores the configuration.
 * 
 * @param viewport the pointer to the struct viewport.
*/
void restore_configuration(view *viewport);

#endif