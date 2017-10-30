/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:51:12 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/22 14:16:19 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void				putImage(t_data *d)
{
    if (d->mlx)
    {
        mlx_clear_window(d->mlx->mlx, d->mlx->win);
        mlx_destroy_image(d->mlx->mlx, d->mlx->im);
        create_image(d->mlx);
        rayCasting(d);
        mlx_put_image_to_window(d->mlx->mlx, d->mlx->win, d->mlx->xpm->img->im, d->rot, -100);
        mlx_put_image_to_window(d->mlx->mlx, d->mlx->win, d->mlx->im, -1, -1);
    }
}

int					destroy(void)
{
	exit(0);
}

int					buttons(int keycode, t_data *d)
{

    if (keycode == 36)
        d->start = 1;
if (d->start > 0)
{
    if (keycode == 126 || keycode == 13)
    {
        if(d->map[(int)(d->posX + d->dirX * d->move_speed)][(int)d->posY] == 0)
            d->posX += d->dirX * d->move_speed;
        if(d->map[(int)(d->posX)][(int)(d->posY + d->dirY * d->move_speed)] == 0)
            d->posY += d->dirY * d->move_speed;
    }
    if (keycode == 125 || keycode == 1)
    {
        if(d->map[(int)(d->posX - d->dirX * d->move_speed)][(int)d->posY] == 0)
            d->posX -= d->dirX * d->move_speed;
        if(d->map[(int)(d->posX)][(int)(d->posY - d->dirY * d->move_speed)] == 0)
            d->posY -= d->dirY * d->move_speed;
    }

    if (keycode == 124 || keycode == 2)
    {
        if(d->map[(int)(d->posX - 2 * d->dirX * d->move_speed)][(int)d->posY] == 0)
            d->posX -= 2 * d->dirX * d->move_speed;
        if(d->map[(int)(d->posX)][(int)(d->posY + d->dirY * d->move_speed)] == 0)
            d->posY += d->dirY * d->move_speed;

    }

    if (keycode == 123 || keycode == 0)
    {
        if(d->map[(int)(d->posX + d->dirX * d->move_speed)][(int)d->posY] == 0)
            d->posX += d->dirX * d->move_speed;
        if(d->map[(int)(d->posX)][(int)(d->posY - 2 * d->dirY * d->move_speed)] == 0)
            d->posY -= 2 * d->dirY * d->move_speed;
    }
    if (keycode == 49)
        d->for_subject = (d->for_subject > 0) ? 0 : 1;
    if (d->lvl == 0 && keycode == 19)
    {
        d->lvl = 1;
        d->posY = 2;
        d->posX = 9;
        d->roof_a = 0xFF000000;
        d->rot = -1200;
        create_xpm(d->mlx, d->lvl);
        createMap(d);
    }
    if (d->lvl == 1 && keycode == 18)
    {
        d->lvl = 0;
        d->posY = 2;
        d->posX = 9;
        d->rot = -1200;
        d->roof_a = 0;
        create_xpm(d->mlx, d->lvl);
        createMap(d);
    }
}
	if (keycode == 53)
		exit(0);
	putImage(d);
	return (0);
}
