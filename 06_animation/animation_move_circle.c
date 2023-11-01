#include "../minilibx-linux/mlx.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 800
#define IMG_WIDTH 100
#define IMG_HEIGHT 100

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
	int	center_x;
	int	center_y;
	int	vel_x;
	int	vel_y;
}		t_vars;

int	draw_circle(t_vars *vars)
{
	int	w, h;

	h = 0;
	while(h < IMG_HEIGHT)
	{
		w = 0;
		while (w < IMG_WIDTH)
		{
			if ((w - 50) * (w - 50) + (h - 50) * (h - 50) <= 2500)
				vars->img.data[h * IMG_WIDTH + w] = 0XFFFFFF;
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(vars->mlx.mlx_ptr, vars->mlx.win, vars->img.img_ptr, vars->center_x, vars->center_y);
	return (0);
}

int	move_circle(t_vars *vars)
{
	vars->center_x += vars->vel_x;
	vars->center_y += vars->vel_y;
	if (vars->center_x < 0 || vars->center_x > WIN_WIDTH)
		vars->vel_x *= -1;
	if (vars->center_y < 0 || vars->center_y > WIN_HEIGHT)
		vars->vel_y *= -1;
	return (0);
}

int main()
{
	t_vars vars;

	vars.mlx.mlx_ptr = mlx_init();
	vars.mlx.win = mlx_new_window(vars.mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "animation_move_circle");
	vars.img.img_ptr = mlx_new_image(vars.mlx.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	vars.img.data = (int *)mlx_get_data_addr(vars.img.img_ptr, &vars.img.bpp, &vars.img.size_l, &vars.img.endian);
	vars.center_x = 400;
	vars.center_y = 400;
	vars.vel_x = 1;
	vars.vel_y = 1;

	mlx_loop_hook(vars.mlx.mlx_ptr, move_circle, &vars);
	mlx_loop(vars.mlx.mlx_ptr);

	return (0);
}


