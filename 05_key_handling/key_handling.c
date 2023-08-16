#include <stdio.h>
#include <stdlib.h>
#include "../minilibx-linux/mlx.h"

#define WIN_WIDTH  800
#define WIN_HEIGHT 800

#define KEY_ESC 53

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win;
}		t_mlx;

int key_press(int keycode, t_mlx *mlx)
{
	printf("Key Pressed");
	return (0);
}

int main()
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "key_handling");

	mlx_key_hook(mlx.win, &key_press, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
