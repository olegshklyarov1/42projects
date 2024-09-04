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

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
		t_complex	z;
		t_complex	c;
		int	i;
		int	color;
		
		i = 0;

		z.x = 0.0;  //first iteration
		z.y = 0.0;

		/*pixel coordinates and scaling with map function*/

		c.x = map(x, -2, +2, 0, WIDTH);
		c.y = map(y, +2, -2, 0, HEIGHT);

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
		pixel_put(x, y, &fractal->img, COLOR_CANDY_PURPLE);
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
