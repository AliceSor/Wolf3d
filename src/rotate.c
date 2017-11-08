/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:54:54 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/30 21:23:06 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static void		a(t_data *d)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = d->dir_x;
	d->dir_x = d->dir_x * cos(-d->rot_speed) - d->dir_y * sin(-d->rot_speed);
	d->dir_y = old_dir_x * sin(-d->rot_speed) + d->dir_y * cos(-d->rot_speed);
	old_plane_x = d->plane_x;
	d->plane_x = d->plane_x * cos(-d->rot_speed) -\
	d->plane_y * sin(-d->rot_speed);
	d->plane_y = old_plane_x * sin(-d->rot_speed) +\
	d->plane_y * cos(-d->rot_speed);
	d->rot -= 2;
	if (d->rot < -2200)
		d->rot = -1200;
}

static void		b(t_data *d)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = d->dir_x;
	d->dir_x = d->dir_x * cos(d->rot_speed) - d->dir_y * sin(d->rot_speed);
	d->dir_y = old_dir_x * sin(d->rot_speed) + d->dir_y * cos(d->rot_speed);
	old_plane_x = d->plane_x;
	d->plane_x = d->plane_x * cos(d->rot_speed) -\
	d->plane_y * sin(d->rot_speed);
	d->plane_y = old_plane_x * sin(d->rot_speed) +\
	d->plane_y * cos(d->rot_speed);
	d->rot += 2;
	if (d->rot > 100)
		d->rot = -1200;
}

int				rotate(int x, int y, t_data *d)
{
	if (d->start == 1 && y != -10000000)
	{
		if ((x - d->mouse_x) > 0)
			a(d);
		else
			b(d);
		d->mouse_x = x;
		put_image(d);
	}
	return (0);
}
