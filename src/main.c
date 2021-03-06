/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:40:46 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/30 22:23:22 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static void		init(t_data *d)
{
	if (d)
	{
		d->lvl = 0;
		d->mlx = create_win();
		create_image(d->mlx);
		create_start_screen(d->mlx);
		create_xpm(d->mlx, d->lvl);
		d->pos_x = 9;
		d->pos_y = 2;
		d->dir_x = -1;
		d->dir_y = 0;
		d->plane_x = 0;
		d->plane_y = 0.66;
		d->move_speed = 0.5;
		d->rot_speed = 4 * RAD;
		d->mouse_x = 0;
		d->rot = -1200;
		d->start = 0;
		d->roof_a = 0;
		d->floor_a = 0;
		create_map(d);
		d->for_subject = 0;
	}
}

int				main(void)
{
	t_data		*data;

	data = (t_data *)malloc(sizeof(t_data) + 10);
	init(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win\
			, data->mlx->start->img->im, -1, -1);
	mlx_hook(data->mlx->win, 2, 5, buttons, data);
	mlx_hook(data->mlx->win, 17, 0, destroy, 0);
	mlx_hook(data->mlx->win, 6, 0, rotate, data);
	mlx_loop(data->mlx->mlx);
	return (0);
}
