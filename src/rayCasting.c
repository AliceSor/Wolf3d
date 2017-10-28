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

static int set_color(t_data *data, t_ray_d *rd, double wall_dist, int side)
{
    t_color     rgb;
    int         a;
    int         color;

    color = 0;
    a = 0;
    if (data->map[rd->map_x][rd->map_y] == 3)
        a = 0x88000000;
    if (data->map[rd->map_x][rd->map_y] == 2)
        a = 0x44000000;
    if (data->map[rd->map_x][rd->map_y] == 1)
        a = 0;

    if (side == 0 && rd->dir_x > 0)
        rgb = up_wall(data);
    else if (side == 1 && rd->dir_y > 0)
        rgb = right_wall(data);
    else if (side == 0 && rd->step_x < 0)
        rgb = down_wall(data);
    else
        rgb = left_wall(data);

    color = integrate_color(rgb.r, rgb.g, rgb.b, 0);
    color += a;
    return color;
}

static void     draw_column(t_data *data, t_ray_d *rd, double wall_dist, int side)
{
    int         i;

    int lineHeight;
    int drawStart;
    int drawEnd;
    int color;

    i = -1;
    lineHeight = (int)(HEIGHT / wall_dist);

    drawStart = -lineHeight / 2 + HEIGHT / 2;
    if(drawStart < 0)
        drawStart = 0;
    drawEnd = lineHeight / 2 + HEIGHT / 2;
    if(drawEnd >= HEIGHT)
        drawEnd = HEIGHT - 1;
    color = set_color(data, rd, wall_dist, side);

    if (side == 1)
    {
        color = color / 2;
    }
    i = drawStart;
    for (i = drawStart; i <= drawEnd; i++)
    {
        putPixel(rd->x, i, color, data->mlx);
    }
    i = drawEnd;
    for (i = drawEnd; i<= HEIGHT; i++)
    {
        putPixel(rd->x, i, 0x44CCBBAA, data->mlx);
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