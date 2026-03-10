/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:59:40 by olshklya          #+#    #+#             */
/*   Updated: 2026/02/24 18:36:07 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_handle(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

static int	handle_special_keys(int keysym, t_fractal *fractal)
{
	if (keysym == XK_c)
		fractal->color_scheme = (fractal->color_scheme + 1) % 4;
	else if (keysym == XK_space && !ft_strncmp(fractal->name, "julia", 5))
		fractal->julia_tracking = !fractal->julia_tracking;
	else if (keysym == XK_d && !fractal->julia_tracking)
		fractal->iterations += 10;
	else if (keysym == XK_s && fractal->iterations > 10
		&& !fractal->julia_tracking)
		fractal->iterations -= 10;
	else
		return (0);
	return (1);
}

int	key_handle(int keysym, t_fractal *fractal)
{
	int	render;

	render = 1;
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
	else
		render = handle_special_keys(keysym, fractal);
	if (render)
		fractal_render(fractal);
	return (0);
}

int	mouse_handle(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_re;
	double	mouse_im;

	if (button == Button4 || button == Button5)
	{
		mouse_re = (scale(x, -2, +2, WIDTH) * fractal->zoom)
			+ fractal->shift_x;
		mouse_im = (scale(y, +2, -2, HEIGHT) * fractal->zoom)
			+ fractal->shift_y;
		if (button == Button4)
			fractal->zoom *= 0.95;
		else if (button == Button5)
			fractal->zoom *= 1.05;
		fractal->shift_x = mouse_re - (scale(x, -2, +2, WIDTH)
				* fractal->zoom);
		fractal->shift_y = mouse_im - (scale(y, +2, -2, HEIGHT)
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
	fractal->julia_x = scale(x, -2, +2, WIDTH);
	fractal->julia_y = scale(y, +2, -2, HEIGHT);
	tmp_iter = fractal->iterations;
	fractal->iterations = 42;
	fractal_render(fractal);
	fractal->iterations = tmp_iter;
	return (0);
}
