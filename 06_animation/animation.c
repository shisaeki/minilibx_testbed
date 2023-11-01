#include "../minilibx-linux/mlx.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 800
#define IMG_WIDTH 400
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

typedef struct	s_update
{
	int	w;
	int	h;
	t_img	*img;
}		t_update;

int render_next_frame(void *update)
{
	update.w = 0;
	update.h = 0;
	while (h < IMG_HEIGHT)
	{
		w = 0;
		while (w < IMG_WIDTH)
		{
			if ((w - 200) * (w - 200) + (h - 200) * (h - 200) <= 40000)
				(update->img)->data[h * IMG_WIDTH + w] = 0xFF0000;
			w++;
		}
		h++;
	}
}

int main()
{
	t_mlx		mlx;
	t_img		img;
	int		W, h;
	t_update	update;
	

	mlx.mlx_ptr = mlx_init();
	mlx.win =mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "animation");
	img.img_ptr = mlx_new_image(mlx.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	update.img = &img;
	update.w = 0;
	update.h = 0;
	mlx_loop_hooks(mlx.mlx_ptr, render_next_frame, update);
	mlx_loop(mlx.mlx_ptr);
}
