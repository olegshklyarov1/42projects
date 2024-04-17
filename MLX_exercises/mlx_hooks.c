#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <X11/keysymdef.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_HEIGHT   400
#define WINDOW_WIDTH    400

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
}               t_data;

int button_press(int button, int x, int y, t_data *data)
{
    if (button == 1)
        printf("Left mouse button pressed at (%d, %d)!\n", x, y);
    if (button == 3)
        printf("Right mouse button pressed at (%d, %d)!\n", x, y);
    return (0);
}

int handle_input(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        printf("The %d key (ESC) has been pressed, the program stops\n\n", keysym);
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(1);
    }
    printf("the %d key has been pressed\n\n", keysym);
    return (0);
}

int main ()
{
    t_data  data;

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_HEIGHT, WINDOW_WIDTH, "MLX Window");

    /*MLX Hooks*/

    mlx_hook(data.win_ptr, ButtonPress, ButtonPressMask, &button_press, &data); /*Mouse Hook*/
    mlx_key_hook(data.win_ptr, handle_input, &data); /*keyboard hook*/
    mlx_loop(data.mlx_ptr);
    return (0);
}