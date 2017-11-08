/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:13:36 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/30 19:13:39 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void				put_image(t_data *d)
{
	if (d->mlx)
	{
		mlx_clear_window(d->mlx->mlx, d->mlx->win);
		mlx_destroy_image(d->mlx->mlx, d->mlx->im);
		create_image(d->mlx);
		ray_casting(d);
		mlx_put_image_to_window(d->mlx->mlx, d->mlx->win, d->mlx->xpm->img->im\
			, d->rot, -100);
		mlx_put_image_to_window(d->mlx->mlx, d->mlx->win, d->mlx->im, -1, -1);
	}
}

int					destroy(void)
{
	exit(0);
}

static void			move_y(int keycode, t_data *d)
{
	if (keycode == 126 || keycode == 13)
	{
		if (d->map[(int)(d->pos_x + d->dir_x *\
			d->move_speed)][(int)d->pos_y] == 0)
			d->pos_x += d->dir_x * d->move_speed;
		if (d->map[(int)(d->pos_x)][(int)(d->pos_y + d->dir_y\
			* d->move_speed)] == 0)
			d->pos_y += d->dir_y * d->move_speed;
	}
	if (keycode == 125 || keycode == 1)
	{
		if (d->map[(int)(d->pos_x - d->dir_x *\
			d->move_speed)][(int)d->pos_y] == 0)
			d->pos_x -= d->dir_x * d->move_speed;
		if (d->map[(int)(d->pos_x)][(int)(d->pos_y - d->dir_y\
			* d->move_speed)] == 0)
			d->pos_y -= d->dir_y * d->move_speed;
	}
}

int					buttons(int keycode, t_data *d)
{
	if (keycode == 36)
		d->start = 1;
	if (d->start > 0)
	{
		if (keycode == 49)
			d->for_subject = (d->for_subject > 0) ? 0 : 1;
		if (d->lvl == 0 && keycode == 19)
		{
			to_lvl1(d);
		}
		if (d->lvl == 1 && keycode == 18)
		{
			to_lvl0(d);
		}
		move_y(keycode, d);
	}
	if (keycode == 53)
		exit(0);
	put_image(d);
	return (0);
}
