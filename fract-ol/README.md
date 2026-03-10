*This project has been created as part of the 42 curriculum by olshklya.*

# fract-ol

## Description

**fract-ol** is a fractal visualization program that renders beautiful mathematical sets in real-time. The project explores complex numbers, optimization techniques, and computer graphics using the MiniLibX library.

The program generates fractals through iterative mathematical formulas, where each pixel's color represents how quickly the calculation diverges to infinity. Users can explore infinite detail through zooming and navigate different regions of the fractal space.

### Implemented Fractals

- **Mandelbrot Set**: The iconic fractal defined by z = z² + c
- **Julia Set**: Variations of the Mandelbrot set with different complex parameters

## Instructions

### Compilation
```bash
make
```

### Usage

**Mandelbrot:**
```bash
./fractol mandelbrot
```

**Julia:**
```bash
./fractol julia <value_1> <value_2>
```

### Controls

- **Mouse Wheel**: Zoom in/out
- **Arrow Keys**: Navigate the fractal
- **ESC**: Exit program
- **C**: Change color pallette

### Requirements

- MiniLibX library
- X11 (Linux) or compatible graphics library

## Features

- Real-time rendering and navigation
- Smooth zooming with mouse wheel
- Multiple color palettes
- Infinite zoom capability (limited by floating-point precision)
- Optimized iteration algorithms for smooth performance

## Resources

### Fractal Mathematics
- [Mandelbrot Set - Wikipedia](https://en.wikipedia.org/wiki/Mandelbrot_set) - Mathematical definition and properties
- [Julia Set - Wikipedia](https://en.wikipedia.org/wiki/Julia_set) - Julia set variations
- [Complex Numbers Introduction](https://www.mathsisfun.com/numbers/complex-numbers.html) - Understanding complex plane mathematics

### Graphics Programming
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx) - Graphics library reference
- [Pixel-by-Pixel Rendering](https://lodev.org/cgtutor/randomnoise.html) - Techniques for efficient rendering

### AI Usage

**Tasks where AI was used:**
- **Debugging Graphics/Rendering**: Used AI to troubleshoot MiniLibX window management, pixel manipulation issues, and rendering optimization
- **Color Palette Algorithms**: Consulted AI for color mapping techniques and gradient generation algorithms

**Parts completed independently:**
- Fractal mathematical implementations
- Complex number calculations
- Zoom and navigation system
- Overall program architecture and event handling
