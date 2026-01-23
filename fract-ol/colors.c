/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:30:00 by olshklya          #+#    #+#             */
/*   Updated: 2026/01/16 23:53:05 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	interpolate(int color1, int color2, double t)
{
	int	r;
	int	g;
	int	b;
	int	r1;
	int	g1;
	int	b1;
	int	r2;
	int	g2;
	int	b2;

	r1 = (color1 >> 16) & 0xFF;
	g1 = (color1 >> 8) & 0xFF;
	b1 = color1 & 0xFF;
	r2 = (color2 >> 16) & 0xFF;
	g2 = (color2 >> 8) & 0xFF;
	b2 = color2 & 0xFF;
	r = r1 + (int)((r2 - r1) * t);
	g = g1 + (int)((g2 - g1) * t);
	b = b1 + (int)((b2 - b1) * t);
	return ((r << 16) | (g << 8) | b);
}

int	color_psychedelic(double t)
{
	int		colors[5];
	double	scaled;
	int		index;
	double	local_t;

	colors[0] = 0xFF006E;
	colors[1] = 0x8338EC;
	colors[2] = 0x3A86FF;
	colors[3] = 0xFB5607;
	colors[4] = 0xFFBE0B;
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

	colors[0] = 0x001219;  // Deep dark blue
	colors[1] = 0x005F73;  // Deep teal
	colors[2] = 0x0A9396;  // Teal
	colors[3] = 0x94D2BD;  // Light aqua
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

	colors[0] = 0x000000;  // Black
	colors[1] = 0x1A0505;  // Very dark red
	colors[2] = 0x8B0000;  // Dark red
	colors[3] = 0xFF4500;  // Orange red
	colors[4] = 0xFFD700;  // Gold/yellow
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

	colors[0] = 0x000000;  // Black
	colors[1] = 0x0D260D;  // Very dark green
	colors[2] = 0x1B4D1B;  // Dark green
	colors[3] = 0x00FF00;  // Bright green
	scaled = t * 3.0;
	index = (int)scaled;
	local_t = scaled - index;
	if (index >= 3)
		return (colors[3]);
	return (interpolate(colors[index], colors[index + 1], local_t));
}

int	color_vaporwave(double t)
{
	int		colors[5];
	double	scaled;
	int		index;
	double	local_t;

	colors[0] = 0x2D1B69;  // Deep purple
	colors[1] = 0xFF006E;  // Hot pink
	colors[2] = 0xFF71CE;  // Light pink
	colors[3] = 0x01CDFE;  // Cyan
	colors[4] = 0xB967FF;  // Light purple
	scaled = t * 4.0;
	index = (int)scaled;
	local_t = scaled - index;
	if (index >= 4)
		return (colors[4]);
	return (interpolate(colors[index], colors[index + 1], local_t));
}