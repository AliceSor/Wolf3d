//
// Created by Alisa Soroka on 10/27/17.
//

#include "../wolf3d.h"

void        fill_skybox(t_mlx *mlx) {
    int i;
    int i_max;

    i = -1;
    i_max = mlx->xpm->width * mlx->xpm->height;
//    i_max = WIDTH * HEIGHT;
    if (mlx->xpm->img) {
        while (++i < i_max) {
//        write(1, "*", 1);
            mlx->xpm->img->imdata[i] = mlx->xpm->imdata[i];

//            mlx->imdata[i] = mlx->xpm->imdata[i];

//            (i < 20) ? printf("(%d)\n", mlx->xpm->imdata[i]) : i++;
        }
    }
}

void			create_xpm(t_mlx *mlx, const char *file) {
    int bpss;
    int endian;
    int i;
    int i_max;

    mlx->xpm = (t_xpm *) malloc(sizeof(t_xpm) + 1);
    if (file && *file && mlx->xpm) {
        mlx->xpm->xpm = mlx_xpm_file_to_image(mlx->mlx, "/nfs/2016/a/asoroka/Clion_projects/Wolf3d/skybox.xpm", &(mlx->xpm->width), &(mlx->xpm->height));
        if (mlx->xpm->xpm)
            mlx->xpm->imdata = (int *) mlx_get_data_addr(mlx->xpm->xpm, &bpss, &mlx->xpm->ls, &endian);
    }
    else
        write(1, "%", 1);

    write(1, "&", 1);
    mlx->xpm->img = (t_img *) malloc(sizeof(t_img) + 1);
    if (mlx->xpm->img)
    {
        mlx->xpm->img->im = mlx_new_image(mlx->mlx, mlx->xpm->width, mlx->xpm->height);
//        mlx->xpm->img->im = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
        mlx->xpm->img->imdata = (int *) mlx_get_data_addr(mlx->xpm->img->im, &bpss, &mlx->xpm->img->ls, &endian);

        fill_skybox(mlx);
    }
//    else
//        write(1, "%", 1);
}