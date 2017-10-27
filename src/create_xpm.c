//
// Created by Alisa Soroka on 10/27/17.
//

#include "../wolf3d.h"

void			create_xpm(t_mlx *mlx, const char *file)
{
    int			bpss;
    int			endian;
    int         i;
    int         i_max;

    mlx->xpm = (t_xpm *)malloc(sizeof(t_xpm));
    if (file && *file)
    {
        mlx->xpm->xpm = mlx_xpm_file_to_image(mlx->mlx, "~/space.xpm", &(mlx->xpm->width), &(mlx->xpm->height));
        if (mlx->xpm->xpm)
            mlx->xpm->imdata = (int *) mlx_get_data_addr(mlx->xpm->xpm, &bpss, &mlx->xpm->ls, &endian);
    }

    write(1, "&", 1);
    mlx->xpm->img = (t_img *)malloc(sizeof(t_img));
    mlx->xpm->img->im = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
    mlx->xpm->img->imdata = (int *)mlx_get_data_addr(mlx->xpm->img->im, &bpss, &mlx->xpm->img->ls, &endian);

    i  = -1;
    i_max = mlx->xpm->width * mlx->xpm->height;
//    while (++i < i_max)
//    {
//        write(1, "*", 1);
//        mlx->xpm->img->imdata[i] = mlx->xpm->imdata[i];
//        printf("(%d", mlx->xpm->imdata[i]);
//    }
}