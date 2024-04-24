#include "../minilibx-linux/mlx.h"
#include "stdio.h"

#define WIN_WIDTH  800
#define WIN_HEIGHT 800

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win;
}		t_mlx;

void render(float factor, t_mlx *mlx);

int key_event(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win);
	else if (keycode == 119)
		mlx_clear_window(mlx->mlx_ptr, mlx->win);
	return (0);
}

int mouse_event(int keycode, t_mlx *mlx)
{
	static float factor = 1.0;
	if (keycode == 4)
	{
		factor += 0.1;
		render(factor, mlx);
	}
	else if (keycode == 5)
	{
		factor -= 0.1;
		render(factor, mlx);
	}
	return (0);
}

void render(float factor, t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win);
	for (int h = 0; h < WIN_HEIGHT; h++)
	{
		for (int w = 0; w < WIN_WIDTH; w++)
		{
			int x = w - (WIN_WIDTH / 2);
			int y = h - (WIN_HEIGHT / 2);
			if (x * x + y * y < (int)(10000 * factor))
				mlx_pixel_put(mlx->mlx_ptr, mlx->win, w, h, 0xFFFFFF);
		}
	}
}

int main( void )
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "key_handling");

	render(1.0, &mlx);	
	mlx_key_hook(mlx.win, key_event, &mlx);
	mlx_mouse_hook(mlx.win, mouse_event, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
