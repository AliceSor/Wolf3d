#include "../wolf3d.h"

void		putColumn(t_data *data, int x, double dist)
{
	double	h;
	int		minY;
	int		maxY;
	
	h = dist / data->tanVertFOV;
	minY = (int)(HEIGHT / 2 - h);
	maxY = (int)(HEIGHT / 2 + h);
	while (maxY >= minY)
	{
		put_pixel((data->mlx->ls * maxY / 4 + x), 0xFFFFFF, data->mlx);
		maxY--;
	}
}