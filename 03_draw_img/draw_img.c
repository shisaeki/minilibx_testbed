#include <stdio.h>
#include "../minilibx-linux/mlx.h"

#define WIN_WIDTH  800
#define WIN_HEIGHT 800

#define IMG_WIDTH  400
#define IMG_HEIGHT 400

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

int main(void)
{
	t_mlx	mlx;
	t_img	img;
	int	w, h;

	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "draw_img");
	img.img_ptr = mlx_new_image(mlx.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);

	w = 0;
	h = 0;
	while (h < IMG_HEIGHT)
	{
		w = 0;
		while(w < IMG_WIDTH)
		{
			if (w % 2)
				img.data[h * IMG_WIDTH + w] = 0xFFFFFF;
			else
				img.data[h * IMG_WIDTH + w] = 0xFF0000; 
			w++;
		}
		h++;
	}

	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, img.img_ptr, 200, 200);
	mlx_loop(mlx.mlx_ptr);

	return (0);
}
