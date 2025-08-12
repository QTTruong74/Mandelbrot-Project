#include <stdio.h>
#include "mandelbrot_draw.h"

void save_configuration(const view *viewport) {
    FILE *file = fopen("config.txt", "w");
    if (file != NULL) {
        fprintf(file, "min_x: %g\n", viewport->min_x);// %g specifier can automatically choose either %f or %e, which can handle the precision of floating-point numbers
        fprintf(file, "max_x: %g\n", viewport->max_x);
        fprintf(file, "min_y: %g\n", viewport->min_y);
        fprintf(file, "max_y: %g\n", viewport->max_y);
        fprintf(file, "center_x: %g\n", viewport->center_x);
        fprintf(file, "center_y: %g\n", viewport->center_y);
        fprintf(file, "zoom_factor: %g\n", viewport->zoom_factor);
        fprintf(file, "move_factor: %g\n", viewport->move_factor);
        fprintf(file, "max_iterations: %d\n", viewport->max_iterations);
        fclose(file);
    }
}

void restore_configuration(view *viewport) {
    FILE *file = fopen("config.txt", "r");
    if (file != NULL) {
        int result = fscanf(file, "min_x: %lf\n", &viewport->min_x);
        result += fscanf(file, "max_x: %lf\n", &viewport->max_x);
        result += fscanf(file, "min_y: %lf\n", &viewport->min_y);
        result += fscanf(file, "max_y: %lf\n", &viewport->max_y);
        result += fscanf(file, "center_x: %lf\n", &viewport->center_x);
        result += fscanf(file, "center_y: %lf\n", &viewport->center_y);
        result += fscanf(file, "zoom_factor: %lf\n", &viewport->zoom_factor);
        result += fscanf(file, "move_factor: %lf\n", &viewport->move_factor);
        result += fscanf(file, "max_iterations: %d\n", &viewport->max_iterations);

        if (result != 9) {// The variable "result" is used to check if all six values were successfully read
            fprintf(stderr, "Error!");
            return;
        }

        fclose(file);
    }
}
