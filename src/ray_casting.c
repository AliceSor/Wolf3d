/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:43:32 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/30 20:13:46 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static void		init_ray(t_data *data, int x, t_ray_d *rd)
{
	double		camera_x;

	camera_x = 2 * x / (double)(WIDTH) - 1;
	rd->pos_x = data->pos_x;
	rd->pos_y = data->pos_y;
	rd->dir_x = data->dir_x + data->plane_x * camera_x;
	rd->dir_y = data->dir_y + data->plane_y * camera_x;
	rd->map_x = (int)rd->pos_x;
	rd->map_y = (int)rd->pos_y;
	rd->delta_d_x = sqrt(1 + (rd->dir_y * rd->dir_y) / (rd->dir_x * rd->dir_x));
	rd->delta_d_y = sqrt(1 + (rd->dir_x * rd->dir_x) / (rd->dir_y * rd->dir_y));
}

static void		calc_step(t_ray_d *rd)
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

static int		set_color(t_data *data, t_ray_d *rd, double wall_dist, int side)
{
	t_color		rgb;
	int			a;
	int			color;

	if (data->map[rd->map_x][rd->map_y] == 3)
		a = 0x88000000;
	else if (data->map[rd->map_x][rd->map_y] == 2)
		a = 0x22000000;
	else if (data->map[rd->map_x][rd->map_y] == 1)
		a = 0;
	else
		a = 0xFF000000;
	if (side == 0 && rd->dir_x > 0)
		rgb = up_wall(data);
	else if (side == 1 && rd->dir_y > 0)
		rgb = right_wall(data);
	else if (side == 0 && rd->step_x < 0)
		rgb = down_wall(data);
	else
		rgb = left_wall(data);
	set_color1(&rgb, wall_dist, side);
	color = integrate_color(rgb.r, rgb.g, rgb.b);
	color += a;
	return (color);
}

static void		draw_column(t_data *data, t_ray_d *rd\
		, double wall_dist, int side)
{
	int			i;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			color;

	i = -1;
	line_height = (int)(HEIGHT / wall_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	color = set_color(data, rd, wall_dist, side);
	while (++i <= draw_start)
		put_pixel(rd->x, i, 0x111111 + data->roof_a, data->mlx);
	i = draw_start - 1;
	while (++i <= draw_end)
		put_pixel(rd->x, i, color, data->mlx);
	i = draw_end - 1;
	while (++i <= HEIGHT)
		put_pixel(rd->x, i, 0x777788 + data->floor_a - ((HEIGHT - i)\
					/ 10 << 16) - ((HEIGHT - i)\
						/ 10 << 8) - ((HEIGHT - i) / 10), data->mlx);
}

void			ray_casting(t_data *data)
{
	int			side;
	double		wall_dist;
	t_ray_d		*rd;
	int			hit;

	rd = (t_ray_d *)malloc(sizeof(t_ray_d) + 10);
	rd->x = 0;
	while (++rd->x < WIDTH)
	{
		init_ray(data, rd->x, rd);
		calc_step(rd);
		side = 0;
		hit = 0;
		while (hit == 0 && rd->map_x < 22)
		{
			help_func2(rd, &side);
			if (data->map[rd->map_x][rd->map_y] > 0)
				hit = 1;
		}
		wall_dist = (side == 0) ? WALL1 : WALL2;
		draw_column(data, rd, wall_dist, side);
	}
}
