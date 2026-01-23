/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:17:25 by olshklya          #+#    #+#             */
/*   Updated: 2026/01/16 23:59:12 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx/mlx.h"

#define ERROR_MESSAGE "Please Enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"


#define WIDTH 800
#define HEIGHT 800

#define COLOR_RED      0xFF0000
#define COLOR_GREEN    0x00FF00
#define COLOR_BLUE     0x0000FF
#define COLOR_BLACK    0x000000
#define COLOR_WHITE    0xFFFFFF
#define COLOR_YELLOW   0xFFFF00
#define COLOR_CYAN     0x00FFFF
#define COLOR_MAGENTA  0xFF00FF
#define COLOR_GRAY     0x808080

#define COLOR_NEON_PINK     0xFF6EC7
#define COLOR_ELECTRIC_BLUE 0x7DF9FF
#define COLOR_LIME_GREEN    0x32CD32
#define COLOR_VIVID_VIOLET  0x9F00FF
#define COLOR_TURQUOISE     0x40E0D0
#define COLOR_HOT_PINK      0xFF69B4
#define COLOR_SUNSET_ORANGE 0xFD5E53
#define COLOR_RADIANT_YELLOW 0xF7E300
#define COLOR_ACID_GREEN    0xB0BF1A
#define COLOR_CANDY_PURPLE  0xE400FF

typedef struct	s_complex
{
	double	x; //real
	double	y; //imaginary
}				t_complex;

typedef struct s_img
{
	void	*img_ptr;		//pointer to image struct
	char	*pixels_ptr;	//points to the pixels
	int	bpp; 				// bits per pixel (32)
	int	endian;
	int	line_len;
}				t_img;

typedef struct	s_fractal
{
	char	*name;
	void	*mlx_connection; //mlx_init()
	void	*mlx_window;     //mlx_new_window()
	t_img	img;
	double	escape_value;
	int	iterations;
	double shift_x;
	double shift_y;
	double zoom;
	double julia_x;
	double julia_y;
	int	color_scheme;
	int julia_tracking;
}				t_fractal;

//Utils
int	ft_strncmp(char *str1, char *str2, int i);
void ft_putstr_fd (char *s, int fd);
double adob(char *s);
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

//Init
void	data_init(t_fractal *fractal);
void	fractal_init(t_fractal *fractal);

//Render
void	fractal_render(t_fractal *fractal);

//Events
int	close_handle(t_fractal *fractal);
int key_handle(int keysym, t_fractal *fractal);
int	mouse_handle(int button, int x, int y, t_fractal *fractal);
int	julia_track(int x, int y, t_fractal *fractal);

//colors
int	color_psychedelic(double t);
int	color_ocean(double t);
int	color_fire(double t);
int	color_matrix(double t);
int	color_vaporwave(double t);

#endif