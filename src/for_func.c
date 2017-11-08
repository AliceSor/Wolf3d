/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 20:37:10 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/30 21:48:47 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void		to_lvl1(t_data *d)
{
	d->lvl = 1;
	d->pos_y = 2;
	d->pos_x = 9;
	d->roof_a = 0xFF000000;
	d->rot = -1200;
	free(d->mlx->xpm);
	free(d->map);
	create_xpm(d->mlx, d->lvl);
	create_map(d);
}

void		to_lvl0(t_data *d)
{
	d->lvl = 0;
	d->pos_y = 2;
	d->pos_x = 9;
	d->rot = -1200;
	d->roof_a = 0;
	free(d->mlx->xpm);
	free(d->map);
	create_xpm(d->mlx, d->lvl);
	create_map(d);
}

void		set_color1(t_color *rgb, double wall_dist, int side)
{
	rgb->r = rgb->r - wall_dist * 10;
	rgb->g = rgb->g - wall_dist * 10;
	rgb->b = rgb->b - wall_dist * 10;
	if (side == 1)
	{
		rgb->r -= 30;
		rgb->g -= 30;
		rgb->b -= 30;
	}
}

void		help_func2(t_ray_d *rd, int *side)
{
	if (rd->side_d_x < rd->side_d_y)
	{
		rd->side_d_x += rd->delta_d_x;
		rd->map_x += rd->step_x;
		*side = 0;
	}
	else
	{
		rd->side_d_y += rd->delta_d_y;
		rd->map_y += rd->step_y;
		*side = 1;
	}
}
