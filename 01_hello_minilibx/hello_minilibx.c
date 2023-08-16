#include "../minilibx-linux/mlx.h"

int main()
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "hello_minilibx");
	mlx_loop(mlx);
}
