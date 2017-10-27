//
// Created by Alisa Soroka on 10/27/17.
//

#include "../wolf3d.h"

void			create_xpm(t_mlx *mlx, char *file)
{
    int			bpss;
    int			endian;

    mlx->xpm = (t_xpm *)malloc(sizeof(t_xpm));
    if (file && *file)
    {
        mlx->xpm->xpm = mlx_xpm_file_to_image(mlx->mlx, "space.xpm", &(mlx->xpm->width), &(mlx->xpm->height));
        if (mlx->xpm->xpm)
            mlx->xpm->imdata = (int *) mlx_get_data_addr(mlx->xpm->xpm, &bpss, &mlx->xpm->ls, &endian);
    }

    mlx->im = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
    mlx->imdata = (int *)mlx_get_data_addr(mlx->im, &bpss, &mlx->ls, &endian);
}