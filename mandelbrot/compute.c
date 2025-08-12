#include <math.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "compute.h"
#include "mandelbrot_draw.h"

double map(double value, double in_min, double in_max, double out_min, double out_max){
    return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int multiply_comp(comp *current, view *viewport) {
    comp *result = (struct complex*)malloc(sizeof(struct complex));
    if(result == NULL){
        fprintf(stderr, "Memory allocation failure.\n"); // handle memory allocation failure
        return EXIT_FAILURE;
        }
    
    result->a_init = current->a;
    result->b_init = current->b;

    result->a = result->a_init;
    result->b = result->b_init;

    int n = 0;
    for(int i = 0; i < viewport->max_iterations; i++) {
        result->a_new = result->a * result->a - result->b * result->b;
        result->b_new = 2.0 * result->a * result->b;

        result->a = result->a_new + result->a_init;
        result->b = result->b_new + result->b_init;

        if (sqrt((result->a * result->a) + (result->b * result->b)) > 2) {
            break;
        }
        n++; // n is used to keep track of the iterations
    }

    free(result);  // Free the allocated memory for result
    return n;      // Point is in the Mandelbrot set
}
