#include <stdio.h>
#include "../minilibx-linux/mlx.h"

#define WIN_WIDTH  800
#define WIN_HEIGHT 800

#define IMG_WIDTH  400
#define IMG_HEIGHT 400

//typedef struct	s_img
//{
//	void	*img_ptr;
//	int	*data;
//	int	size_l;
//	int	bpp;
//	int	endian;
//}		t_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win;
}		t_mlx;

int main(void)
{
	t_mlx	*mlx;

	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "draw_img");

	mlx_loop(mlx->mlx_ptr);

	return (0);
}
