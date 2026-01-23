/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:59:40 by olshklya          #+#    #+#             */
/*   Updated: 2026/01/17 00:40:13 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handle(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handle(int keysym, t_fractal *fractal)
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
	{
		if (fractal->julia_tracking)
			return (0);
		fractal->iterations += 10;
	}
	else if (keysym == XK_s && fractal->iterations > 10)\
	{
		if (fractal->julia_tracking)
			return (0);
		fractal->iterations -= 10;
	}
	else if (keysym == XK_c)
		fractal->color_scheme = (fractal->color_scheme + 1) % 5;
	else if (keysym == XK_space)  // Toggle Julia tracking
	{
		if (!ft_strncmp(fractal->name, "julia", 5))
			fractal->julia_tracking = !fractal->julia_tracking;
		return (0);
	}
	else
		return (0);
	fractal_render(fractal);
	return (0);
}

int	mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;

	if (button == Button4 || button == Button5)
	{
		mouse_re = (map(x, -2, +2, 0, WIDTH) * fractal->zoom) 
					+ fractal->shift_x;
		mouse_im = (map(y, +2, -2, 0, HEIGHT) * fractal->zoom) 
					+ fractal->shift_y;
		if (button == Button4)
			fractal->zoom *= 0.95;
		else if (button == Button5)
			fractal->zoom *= 1.05;
		fractal->shift_x = mouse_re - (map(x, -2, +2, 0, WIDTH) 
										* fractal->zoom);
		fractal->shift_y = mouse_im - (map(y, +2, -2, 0, HEIGHT) 
										* fractal->zoom);
		fractal_render(fractal);
	}
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	static int	last_x = -1;
	static int	last_y = -1;
	int			tmp_iter;
	
	if (!fractal->name || ft_strncmp(fractal->name, "julia", 5) != 0)
		return (0);
	if (!fractal->julia_tracking)
		return (0);
	if (abs(x - last_x) < 5 && abs(y - last_y) < 5)
		return (0);
	last_x = x;
	last_y = y;
	fractal->julia_x = map(x, -2, +2, 0, WIDTH);
	fractal->julia_y = map(y, +2, -2, 0, HEIGHT);
	tmp_iter = fractal->iterations;
	fractal->iterations = 15;
	fractal_render(fractal);
	fractal->iterations = tmp_iter;
	return (0);
}