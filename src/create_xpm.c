//
// Created by Alisa Soroka on 10/27/17.
//

#include "../wolf3d.h"


static void        fill_screen(t_mlx *mlx) {
    int i;
    int i_max;

    i = -1;
    i_max = mlx->start->width * mlx->start->height;
    if (mlx->start->img) {
        while (++i < i_max) {
            mlx->start->img->imdata[i] = mlx->start->imdata[i];
        }
    }
}

void			create_start_screen(t_mlx *mlx) {
    int bpss;
    int endian;
    char *file;


    file = "/nfs/2016/a/asoroka/Clion_projects/Wolf3d/src/xpm/42.xpm";
    mlx->start = (t_xpm *) malloc(sizeof(t_xpm) + 1);
    if (mlx->start) {
        mlx->start->xpm = mlx_xpm_file_to_image(mlx->mlx, file, &(mlx->start->width), &(mlx->start->height));
        if (mlx->start->xpm) {
            mlx->start->imdata = (int *) mlx_get_data_addr(mlx->start->xpm, &bpss, &mlx->start->ls, &endian);
            mlx->start->img = (t_img *) malloc(sizeof(t_img) + 1);
            if (mlx->start->img) {
                mlx->start->img->im = mlx_new_image(mlx->mlx, mlx->start->width, mlx->start->height);
                mlx->start->img->imdata = (int *) mlx_get_data_addr(mlx->start->img->im, &bpss, &mlx->start->img->ls,
                                                                  &endian);
                fill_screen(mlx);
            }
        }
        else
        {
            write(1, "error image\n", 12);
            exit(1);
        }
    }
}


void        fill_skybox(t_mlx *mlx) {
    int i;
    int i_max;

    i = -1;
    i_max = mlx->xpm->width * mlx->xpm->height;
    if (mlx->xpm->img) {
        while (++i < i_max) {
            mlx->xpm->img->imdata[i] = mlx->xpm->imdata[i];
        }
    }
}

void			create_xpm(t_mlx *mlx, int lvl) {
    int bpss;
    int endian;
    char *file;

    if (lvl == 0)
        file = "/nfs/2016/a/asoroka/Clion_projects/Wolf3d/src/xpm/space3_2560x1600.XPM";
    else
        file = "/nfs/2016/a/asoroka/Clion_projects/Wolf3d/src/xpm/space2_3000x1500.XPM";
    mlx->xpm = (t_xpm *) malloc(sizeof(t_xpm) + 1);
    if (mlx->xpm) {
        mlx->xpm->xpm = mlx_xpm_file_to_image(mlx->mlx, file, &(mlx->xpm->width), &(mlx->xpm->height));
        if (mlx->xpm->xpm) {
            mlx->xpm->imdata = (int *) mlx_get_data_addr(mlx->xpm->xpm, &bpss, &mlx->xpm->ls, &endian);
            mlx->xpm->img = (t_img *) malloc(sizeof(t_img) + 1);
            if (mlx->xpm->img) {
                mlx->xpm->img->im = mlx_new_image(mlx->mlx, mlx->xpm->width, mlx->xpm->height);
                mlx->xpm->img->imdata = (int *) mlx_get_data_addr(mlx->xpm->img->im, &bpss, &mlx->xpm->img->ls,
                                                                  &endian);
                fill_skybox(mlx);
            }
        }
        else
        {
            write(1, "error image\n", 12);
            exit(1);
        }
    }
}