#include "fractol.h"

// Scaling [0...799] to [-2...+2]

double map(double unscaled_num)
{
    double old_min = 0.0;
    double old_max = 799.0;
    double new_min = -2.0;
    double new_max = 2.0;
    
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}


// Sum Complex Numbers

t_complex	sum_complex(t_complex z1, t_complex z2)
{
		t_complex	result;

		result.x = z1.x + z2.x;
		result.y = z1.y + z2.y;
		return (result);
}

//Square Complex Numbers

t_complex	square_complex(t_complex z)
{
		t_complex	result;

		result.x = (z.x * z.x) - (z.y * z.y);
		result.y = 2 * z.x * z.y;
		return (result);
}
