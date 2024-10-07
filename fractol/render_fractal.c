#include "fractol.h"

/*put pixel in image buffer*/

static void pixel_put(int x, int y, t_img *img, int color)
{
		int	offset;

		offset = (y * img->line_len) + (x * (img->bpp / 8));
		*(unsigned int *) (img->pixels_ptr + offset) = color;
}

// Function of the Mandelbrot set: z = z^2 + c
// z init is (0, 0)
// c is the actual pixel/point

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}


static void	handle_pixel(int x, int y, t_fractal *fractal)
{
		t_complex	z;
		t_complex	c;
		int	i;
		int	color;
		
		i = 0;

		/*pixel coordinates and scaling with map function*/

		z.x = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
		z.y = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
		mandel_vs_julia(&z, &c, fractal);
		while (i < fractal->iterations)
		{
				z = sum_complex(square_complex(z), c);
				if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
				{
						color = map(i, COLOR_BLACK, COLOR_WHITE, 0, fractal->iterations);
						pixel_put(x, y, &fractal->img, color);
						return ;
				}
				i++;
		}
		pixel_put(x, y, &fractal->img, COLOR_ELECTRIC_BLUE);
}

void	fractal_render(t_fractal *fractal)
{
		int	x;
		int	y;

		y = -1;
		while (++y < HEIGHT)
		{
				x = -1;
				while (++x < WIDTH)
				{
						handle_pixel(x, y, fractal);
				}
		}
		mlx_put_image_to_window(fractal->mlx_connection, 
								fractal->mlx_window, 
								fractal->img.img_ptr,
								0, 0);
}
