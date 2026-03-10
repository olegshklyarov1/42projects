/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:30:00 by olshklya          #+#    #+#             */
/*   Updated: 2026/02/24 18:35:51 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	interpolate(int color1, int color2, double t)
{
	int	r;
	int	g;
	int	b;

	r = ((color1 >> 16) & 0xFF) + (int)((((color2 >> 16) & 0xFF)
				- ((color1 >> 16) & 0xFF)) * t);
	g = ((color1 >> 8) & 0xFF) + (int)((((color2 >> 8) & 0xFF)
				- ((color1 >> 8) & 0xFF)) * t);
	b = (color1 & 0xFF) + (int)(((color2 & 0xFF)
				- (color1 & 0xFF)) * t);
	return ((r << 16) | (g << 8) | b);
}

int	color_psychedelic(double t)
{
	int		colors[5];
	double	scaled;
	int		index;
	double	local_t;

	colors[0] = PSYCHE_MAGENTA;
	colors[1] = PSYCHE_PURPLE;
	colors[2] = PSYCHE_BLUE;
	colors[3] = PSYCHE_ORANGE;
	colors[4] = PSYCHE_YELLOW;
	scaled = t * 4.0;
	index = (int)scaled;
	local_t = scaled - index;
	if (index >= 4)
		return (colors[4]);
	return (interpolate(colors[index], colors[index + 1], local_t));
}

int	color_ocean(double t)
{
	int		colors[4];
	double	scaled;
	int		index;
	double	local_t;

	colors[0] = OCEAN_DEEP_BLUE;
	colors[1] = OCEAN_DEEP_TEAL;
	colors[2] = OCEAN_TEAL;
	colors[3] = OCEAN_LIGHT_AQUA;
	scaled = t * 3.0;
	index = (int)scaled;
	local_t = scaled - index;
	if (index >= 3)
		return (colors[3]);
	return (interpolate(colors[index], colors[index + 1], local_t));
}

int	color_fire(double t)
{
	int		colors[5];
	double	scaled;
	int		index;
	double	local_t;

	colors[0] = FIRE_BLACK;
	colors[1] = FIRE_DARK_RED;
	colors[2] = FIRE_CRIMSON;
	colors[3] = FIRE_ORANGE_RED;
	colors[4] = FIRE_GOLD;
	scaled = t * 4.0;
	index = (int)scaled;
	local_t = scaled - index;
	if (index >= 4)
		return (colors[4]);
	return (interpolate(colors[index], colors[index + 1], local_t));
}

int	color_matrix(double t)
{
	int		colors[4];
	double	scaled;
	int		index;
	double	local_t;

	colors[0] = MATRIX_BLACK;
	colors[1] = MATRIX_DARK_GREEN;
	colors[2] = MATRIX_GREEN;
	colors[3] = MATRIX_BRIGHT_GREEN;
	scaled = t * 3.0;
	index = (int)scaled;
	local_t = scaled - index;
	if (index >= 3)
		return (colors[3]);
	return (interpolate(colors[index], colors[index + 1], local_t));
}
