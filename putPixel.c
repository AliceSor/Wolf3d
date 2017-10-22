#include "../wolf3d.h"

void			putPixel(int x, int y, int color, t_mlx *mlx)
{
	int			i;
	i = mlx->ls * y / 4 + x;
	if (i < WIDTH * HEIGHT && i > 0)
		mlx->imdata[i] = color;
}