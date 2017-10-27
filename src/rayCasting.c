/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:58:28 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/22 19:38:57 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static void     init_ray(t_data *data, int x, t_ray_d *rd)
{
    double cameraX = 2 * x / (double)(WIDTH) - 1; //x-coordinate in camera space
    rd->pos_x = data->posX;
    rd->pos_y = data->posY;
    rd->dir_x = data->dirX + data->planeX * cameraX;
    rd->dir_y = data->dirY + data->planeY * cameraX;
 rd->map_x = (int)rd->pos_x;
 rd->map_y = (int)rd->pos_y;
rd->delta_d_x = sqrt(1 + (rd->dir_y * rd->dir_y) / (rd->dir_x * rd->dir_x));
rd->delta_d_y = sqrt(1 + (rd->dir_x * rd->dir_x) / (rd->dir_y * rd->dir_y));
}


static void     calc_step(t_ray_d *rd)
{
    if (rd->dir_x < 0)
    {
        rd->step_x = -1;
        rd->side_d_x = (rd->pos_x - rd->map_x) * rd->delta_d_x;
    }
    else
    {
        rd->step_x = 1;
        rd->side_d_x = (rd->map_x + 1.0 - rd->pos_x) * rd->delta_d_x;
    }
    if (rd->dir_y < 0)
    {
        rd->step_y = -1;
        rd->side_d_y = (rd->pos_y - rd->map_y) * rd->delta_d_y;
    }
    else
    {
        rd->step_y = 1;
        rd->side_d_y = (rd->map_y + 1.0 - rd->pos_y) * rd->delta_d_y;
    }
}

static void     draw_column(t_data *data, t_ray_d *rd, double perpWallDist, int side)
{
    int lineHeight = (int)(HEIGHT / perpWallDist);

    int drawStart = (int)(-lineHeight / 2 + HEIGHT / 2);
    if(drawStart < 0)
        drawStart = 0;
    int drawEnd = (int)(lineHeight / 2 + HEIGHT / 2);
    if(drawEnd >= HEIGHT)
        drawEnd = (int)(HEIGHT - 1);
    int color;
    switch(data->map[rd->map_x][rd->map_y])
    {
        case 1:  color = 0xFF0000;  break; //red
        case 2:  color = 0x00FF00;  break; //green
        case 3:  color = 0x0000FF;   break; //blue
        case 4:  color = 0xFFFFFF;  break; //white
        default: color = 0xFF00FF; break; //yellow
    }

    if (side == 1)
    {
        color = color / 2;
    }
    for (int i = drawStart; i <= drawEnd; i++)
    {
        putPixel(rd->x, i, color, data->mlx);
    }
}

void			rayCasting(t_data *data)
{

    int side;
    double wall_dist;
    t_ray_d     *rd;
    int     hit;


    rd = (t_ray_d *)malloc(sizeof(t_ray_d) + 10);
    rd->x = 0;
    while (++rd->x < WIDTH)
    {
        init_ray(data, rd->x, rd) ;
        calc_step(rd);
        side = 0;
        hit = 0;
        while (hit == 0)
        {
            if (rd->side_d_x < rd->side_d_y)
            {
                rd->side_d_x += rd->delta_d_x;
                rd->map_x += rd->step_x;
                side = 0;
            }
            else
            {
                rd->side_d_y += rd->delta_d_y;
                rd->map_y += rd->step_y;
                side = 1;
            }
            if (data->map[rd->map_x][rd->map_y] > 0)
            {
                hit = 1;
            }
        }
        if (side == 0)
            wall_dist = (rd->map_x - rd->pos_x + (1 - rd->step_x) / 2) / rd->dir_x;
        else
            wall_dist = (rd->map_y - rd->pos_y + (1 - rd->step_y) / 2) / rd->dir_y;

        draw_column(data, rd, wall_dist, side);
    }
}