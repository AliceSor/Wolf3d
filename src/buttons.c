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
        mlx_put_image_to_window(d->mlx->mlx, d->mlx->win, d->mlx->xpm->img->im, -1, -1);
        mlx_put_image_to_window(d->mlx->mlx, d->mlx->win, d->mlx->im, 0, 0);
    }
}

int					destroy(void)
{
	exit(0);
}

int					buttons(int keycode, t_data *d)
{
	if (keycode == 49)
		d->h +=10;
	if (keycode == 126 || keycode == 13)
	{
		if(d->map[(int)(d->posX + d->dirX * d->moveSpeed)][(int)d->posY] == 0)
			d->posX += d->dirX * d->moveSpeed;
		if(d->map[(int)(d->posX)][(int)(d->posY + d->dirY * d->moveSpeed)] == 0)
			d->posY += d->dirY * d->moveSpeed;
	}
	//move backwards if no wall behind you
	if (keycode == 125 || keycode == 1)
	{
		if(d->map[(int)(d->posX - d->dirX * d->moveSpeed)][(int)d->posY] == 0)
			d->posX -= d->dirX * d->moveSpeed;
		if(d->map[(int)(d->posX)][(int)(d->posY - d->dirY * d->moveSpeed)] == 0)
			d->posY -= d->dirY * d->moveSpeed;
	}
	//rotate to the right
	if (keycode == 124)
	{
		//both camera direction and camera plane must be rotated
        if(d->map[(int)(d->posX - d->dirX * d->moveSpeed)][(int)d->posY] == 0)
            d->posX -= d->dirX * d->moveSpeed;
        if(d->map[(int)(d->posX)][(int)(d->posY - d->dirY * d->moveSpeed)] == 0)
            d->posY -= d->dirY * d->moveSpeed;
	}
	//rotate to the left
	if (keycode == 123)
	{
		//both camera direction and camera plane must be rotated
        if(d->map[(int)(d->posX - d->dirX * d->moveSpeed)][(int)d->posY] == 0)
            d->posX -= d->dirX * d->moveSpeed;
        if(d->map[(int)(d->posX)][(int)(d->posY - d->dirY * d->moveSpeed)] == 0)
            d->posY -= d->dirY * d->moveSpeed;
	}
	if (keycode == 53)
		exit(0);
	putImage(d);
	return (0);
}
