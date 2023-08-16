#include <stdio.h>
#include <stdlib.h>
#include "../minilibx-linux/mlx.h"

#define WIN_WIDTH  800
#define WIN_HEIGHT 800

#define IMG_WIDTH  400
#define IMG_HEIGHT 400

#define KEY_ESC 65307
#define KEY_R   114
#define KEY_W	119

typedef struct	s_img
{
	void	*img_ptr;
	int	*data;
	int	size_l;
	int	bpp;
	int	endian;
}		t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win;
}		t_mlx;

int key_press(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		exit(0);
	printf("%d: Key Pressed\n", keycode);

	return (0);
}

int main()
{
	t_mlx		mlx;
	t_img		img;
	int	w, h;

	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "key_handling");
	mlx_key_hook(mlx.win, &key_press, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
