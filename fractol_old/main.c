#include "fractol.h"
#include "minilibx-linux/mlx.h"
/***Julia And Mandelbrot****
 
  -Infinite Zoom
  -Able to take command line args to shape Julia, x y coordinates
  -ESC Closes the program
  -Click on the X window, closes the process, free leaks */



/* TWO PROMPTS
 
 * ./fractal mandelbrot
 * ./fractal julia <real> <imaginary>
 
 */


int	main(int argc, char **argv)
{
		t_fractal	fractal;
				
		if (2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10)
				|| 4 == argc && !ft_strncmp(argv[1], "julia", 5))
		{
				fractal.name = argv[1];
				if(!ft_strncmp(fractal.name, "julia", 5))
				{
						fractal.julia_x = adob(argv[2]);
						fractal.julia_y = adob(argv[3]);
				}
				fractal_init(&fractal);       //Pass by reference to the struct 
				fractal_render(&fractal);
				mlx_loop(fractal.mlx_connection); //Loop Event that handles inputs
		}
		else
		{
				putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
				exit(EXIT_FAILURE);
		}

}
