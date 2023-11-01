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

typedef struct	s_vars
{
	t_mlx	mlx;
	t_img	img;
	int		color;
}			t_vars;

int draw_circle(t_vars *vars)
{
	int	w, h;
	
	h = 0;
	while (h < IMG_HEIGHT)
	{
		w = 0;
		while (w < IMG_WIDTH)
		{
			if ((w - 200) * (w - 200) + (h - 200) * (h - 200) <= 40000)
				vars->img.data[h * IMG_WIDTH + w] = vars->color;
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(vars->mlx.mlx_ptr, vars->mlx.win, vars->img.img_ptr, 200, 200);
	return (0);
}

int change_color(t_vars *vars)
{
	vars->color += 0X010101;
	if (vars->color > 0XFFFFFF)
		vars->color = 0;
	draw_circle(vars);
	return (0);
}

int main()
{
	t_vars	vars;
	

	vars.mlx.mlx_ptr = mlx_init();
	vars.mlx.win =mlx_new_window(vars.mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "animation");
	vars.img.img_ptr = mlx_new_image(vars.mlx.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	vars.img.data = (int *)mlx_get_data_addr(vars.img.img_ptr, &vars.img.bpp, &vars.img.size_l, &vars.img.endian);
	vars.color = 0XFF0000;
	
	mlx_loop_hook(vars.mlx.mlx_ptr, change_color, &vars);
	mlx_loop(vars.mlx.mlx_ptr);

	return (0);
}
