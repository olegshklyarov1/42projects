/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:55:33 by olshklya          #+#    #+#             */
/*   Updated: 2026/02/24 18:36:49 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static int	mandelbrot_calc(t_complex c, t_fractal *fractal)
{
	int		i;
	double	x;
	double	y;
	double	tmp;

	i = 0;
	x = 0.0;
	y = 0.0;
	while (i < fractal->iterations && (x * x + y * y) <= fractal->escape_value)
	{
		tmp = x * x - y * y + c.x;
		y = 2.0 * x * y + c.y;
		x = tmp;
		i++;
	}
	return (i);
}

static int	julia_calc(t_complex z, t_fractal *fractal)
{
	int			i;
	t_complex	c;
	double		tmp;

	i = 0;
	c.x = fractal->julia_x;
	c.y = fractal->julia_y;
	while (i < fractal->iterations)
	{
		tmp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2.0 * z.x * z.y + c.y;
		z.x = tmp;
		if ((z.x * z.x + z.y * z.y) > fractal->escape_value)
			return (i);
		i++;
	}
	return (i);
}

static int	get_color(int i, t_fractal *fractal)
{
	double	t;

	if (i == fractal->iterations)
		return (0x000000);
	t = (double)i / (double)fractal->iterations;
	if (fractal->color_scheme == 1)
		return (color_ocean(t));
	else if (fractal->color_scheme == 2)
		return (color_fire(t));
	else if (fractal->color_scheme == 3)
		return (color_psychedelic(t));
	else
		return (color_matrix(t));
}

void	fractal_render(t_fractal *fractal)
{
	int			x;
	int			y;
	t_complex	z;
	int			color;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			z.x = (scale(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
			z.y = (scale(y, +2, -2, HEIGHT) * fractal->zoom)
				+ fractal->shift_y;
			if (!ft_strncmp(fractal->name, "julia", 5))
				color = get_color(julia_calc(z, fractal), fractal);
			else
				color = get_color(mandelbrot_calc(z, fractal), fractal);
			pixel_put(x, y, &fractal->img, color);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
