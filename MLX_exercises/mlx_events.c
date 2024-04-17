#include "mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>

#define MLX_ERROR       1
#define WINDOW_WIDTH    400
#define WINDOW_HEIGHT   400

typedef struct  s_mlx_data
{
    void	*mlx_ptr;
    void	*win_ptr;
}				t_mlx_data;


/*HANDLER FUNCTION
  Every time the key is pressed, calls the function*/

  int   handle_input(int keysym, t_mlx_data *data)
  {
    if (keysym == XK_Escape)
    {
      printf("The %d key (ESC) has been pressed\n\n", keysym);
      mlx_destroy_window(data->mlx_ptr, data->win_ptr);
      mlx_destroy_display(data->mlx_ptr);
      free(data->mlx_ptr);
      exit(1);
    }
    printf("the %d key has been pressed\n\n", keysym);
    return (0);
  }

int   main(void)
{
  t_mlx_data	data;

  data.mlx_ptr = mlx_init();
  if (data.mlx_ptr == NULL)
    return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window !");
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return(MLX_ERROR);
	}

  /*HOOKS, Hooking into event, when pressed a key, handle_input() is triggered*/

  mlx_key_hook(data.win_ptr, handle_input, &data);
  mlx_loop(data.mlx_ptr);
}