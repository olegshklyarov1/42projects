/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:17:25 by olshklya          #+#    #+#             */
/*   Updated: 2026/02/24 18:50:38 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MESSAGE "Usage: ./fractol [mandelbrot|julia]"

# define WIDTH 800
# define HEIGHT 800

// Psychedelic color scheme
# define PSYCHE_MAGENTA 0xFF006E
# define PSYCHE_PURPLE 0x8338EC
# define PSYCHE_BLUE 0x3A86FF
# define PSYCHE_ORANGE 0xFB5607
# define PSYCHE_YELLOW 0xFFBE0B

// Ocean color scheme
# define OCEAN_DEEP_BLUE 0x001219
# define OCEAN_DEEP_TEAL 0x005F73
# define OCEAN_TEAL 0x0A9396
# define OCEAN_LIGHT_AQUA 0x94D2BD

// Fire color scheme
# define FIRE_BLACK 0x000000
# define FIRE_DARK_RED 0x1A0505
# define FIRE_CRIMSON 0x8B0000
# define FIRE_ORANGE_RED 0xFF4500
# define FIRE_GOLD 0xFFD700

// Matrix color scheme
# define MATRIX_BLACK 0x000000
# define MATRIX_DARK_GREEN 0x0D260D
# define MATRIX_GREEN 0x1B4D1B
# define MATRIX_BRIGHT_GREEN 0x00FF00

// Vaporwave color scheme
# define VAPOR_DEEP_PURPLE 0x2D1B69
# define VAPOR_HOT_PINK 0xFF006E
# define VAPOR_LIGHT_PINK 0xFF71CE
# define VAPOR_CYAN 0x01CDFE
# define VAPOR_LIGHT_PURPLE	12150783

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		color_scheme;
	int		julia_tracking;
}			t_fractal;

// Utils
int			ft_strncmp(char *str1, char *str2, int i);
void		ft_putstr_fd(char *s, int fd);
double		adob(char *s);
double		scale(double un, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

// Init
void		data_init(t_fractal *fractal);
void		events_init(t_fractal *fractal);
void		fractal_init(t_fractal *fractal);

// Render
void		fractal_render(t_fractal *fractal);

// Events
int			close_handle(t_fractal *fractal);
int			key_handle(int keysym, t_fractal *fractal);
int			mouse_handle(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);

// Colors
int			color_psychedelic(double t);
int			color_ocean(double t);
int			color_fire(double t);
int			color_matrix(double t);

#endif