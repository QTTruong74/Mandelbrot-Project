# Mandelbrot Set Visualizer

This project implements an interactive **Mandelbrot set generator** in C using SDL2.  
The Mandelbrot set is a famous fractal defined by iterating the formula:

$$
z_{n+1} = z_n^2 + c, \quad z_0 = 0
$$

where `c` is a complex number.  
If the magnitude of `z` stays below 2 forever, the point `c` belongs to the set (displayed in black).  
Otherwise, the point is outside the set and is color-coded based on how quickly it diverges.

## Features
- Graphical rendering of the Mandelbrot set for a chosen viewport.
- Interactive **zoom in** and **zoom out**.
- Ability to **save** and **restore** the current view configuration.
- Efficient calculation and color mapping based on divergence speed.

## Controls
- **Zoom in/out** – Explore deeper regions of the fractal.
- **Save/restore** – Store and reload interesting views.
- **Exit** – Close the program.

This program demonstrates both the beauty of fractals and core C programming techniques such as:
- Complex number iteration
- Graphical rendering with SDL2
- User interaction and event handling
- File I/O for configuration storage
