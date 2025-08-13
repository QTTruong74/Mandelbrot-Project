Mandelbrot Project
====================

This project implements a graphical Mandelbrot set generator in C using SDL.

# Features:
1. Computes complex numbers (compute.c: map() and multiply_comp()).
2. Draws Mandelbrot set pixels with color mapping (mandelbrot_draw.c).
3. Supports zooming in/out and moving in all four directions (zoom.c).
4. Saves and restores view configuration to/from file (save_and_restore.c).
5. Handles SDL initialization, event loop, and rendering (mandelbrot.c).

# Controls:
1. Q / E  - Zoom in / out
2. W / S - Move up / down
3. A / D - Move left / right
4. X / Z  - Save / restore configuration
5. ESC - Exit program

# How to build and run the program:
1. Open Terminal and run make
2. Type in Terminal this command to run the program: ./build/release/mandelbrot

# Additional:
1. Test coverage implemented for compute.c and zoom.c.
2. Works on Ubuntu and macOS.