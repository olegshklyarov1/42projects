#include "fractol.h"


// Keypress Prototypes

int	close_handle(t_fractal *fractal)
{
		mlx_destroy_image(fractal->mlx_connection, 
						fractal->img.img_ptr);
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(EXIT_SUCCESS);
}

int key_handle(int keysym, t_fractal *fractal)
{
		if (keysym == XK_Escape)
				close_handle(fractal);
		else if (keysym == XK_Left)
				fractal->shift_x += (0.5 * fractal->zoom);
		else if (keysym == XK_Right)
				fractal->shift_x -= (0.5 * fractal->zoom);
		else if (keysym == XK_Up)
				fractal->shift_y -= (0.5 * fractal->zoom);
		else if (keysym == XK_Down)
				fractal->shift_y += (0.5 * fractal->zoom);
		else if (keysym == XK_d)
				fractal->iterations += 10;
		else if (keysym == XK_s)
				fractal->iterations -=10;
		fractal_render(fractal);
		return 0;
}

int	mouse_handle(int button, int x, int y, t_fractal *fractal)
{
		if (button == Button4)
		{
				fractal->zoom *= 0.95;
		}
		else if (button == Button5)
		{
				fractal->zoom *= 1.05;
		}
		fractal_render(fractal);
		return 0;
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
		fractal->julia_y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
		fractal_render(fractal);
	}
	return 0;
}
