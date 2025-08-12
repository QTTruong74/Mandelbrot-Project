#ifndef COMPUTE_H
#define COMPUTE_H

#define WIDTH 800
#define HEIGHT 800

/** This is the context that contains the calculation of the mandelbrot set*/

/** This is the structure of the complex number */
struct complex {
    double a; /**< The x-coordinate or the real part of the complex number */
    double b; /**< The y-coordinate or the imaginary part of the complex number */
    double a_init; /**< The initialized real part of the commplex number */
    double b_init; /**< The initialized imaginary part of the commplex number */
    double a_new; /**< The real part of the complex number after multiplication is done*/
    double b_new; /**< The imaginary part of the complex number after multiplication is done*/
};

typedef struct complex comp;

struct viewport;

typedef struct viewport view;

/**
 * This is the function that maps a value from one range to another.
 * 
 * @param value the input value that will be mapped to a new range.
 * 
 * @param in_min the minimum value of the input range.
 * 
 * @param in_max the maximum value of the input range.
 * 
 * @param out_min the minimum value of the output range.
 * 
 * @param out_max the maximum value of the output range.
 */
double map(double value, double in_min, double in_max, double out_min, double out_max);

/**
 * This is the function that calculates the formular z_n = (z_n-1)^2 + c of the mandelbrot set
 * 
 * and it is also resposible for checking if one point belongs to the mandelbrot set or not.
 * 
 * @param current the pointer to the struct complex.
 * 
 * @param viewport the pointer to the struct viewport.
*/
int multiply_comp(comp *current, view *viewport);

#endif