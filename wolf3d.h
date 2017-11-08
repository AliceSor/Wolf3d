/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 21:50:45 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/30 22:11:15 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define HEIGHT 750
# define WIDTH 1200
# define RAD 0.01745329251994
# define GET_ADR (int *)mlx_get_data_addr
# define WALL1 (rd->map_x - rd->pos_x + (1 - rd->step_x) / 2) / rd->dir_x
# define WALL2 (rd->map_y - rd->pos_y + (1 - rd->step_y) / 2) / rd->dir_y
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_color
{
	double			r;
	double			b;
	double			g;
}					t_color;

typedef struct		s_ray_d
{
	int				x;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	double			side_d_x;
	double			side_d_y;
	double			delta_d_x;
	double			delta_d_y;
	int				step_x;
	int				step_y;
}					t_ray_d;

typedef struct		s_img
{
	void			*im;
	int				*imdata;
	int				ls;
}					t_img;

typedef struct		s_xpm
{
	void			*xpm;
	int				*imdata;
	int				ls;
	int				width;
	int				height;
	t_img			*img;
}					t_xpm;

typedef struct		s_mlx
{
	void			*win;
	void			*mlx;
	void			*im;
	int				*imdata;
	int				ls;
	t_xpm			*xpm;
	t_xpm			*lvl0;
	t_xpm			*lvl1;
	t_xpm			*lvl2;
	t_xpm			*start;
}					t_mlx;

typedef struct		s_data
{
	t_mlx			*mlx;
	int				**map;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
	int				mouse_x;
	int				lvl;
	int				start;
	int				rot;
	int				floor_a;
	int				roof_a;
	int				for_subject;
}					t_data;

t_mlx				*create_win(void);
void				create_image(t_mlx *mlx);
void				put_pixel(int x, int y, int color, t_mlx *mlx);
void				ray_casting(t_data *data);
void				create_map(t_data *d);
int					buttons(int keycode, t_data *data);
void				put_image(t_data *data);
int					destroy(void);
int					rotate(int x, int y, t_data *data);
void				create_xpm(t_mlx *mlx, int lvl);
void				create_start_screen(t_mlx *mlx);
void				fill_skybox(t_mlx *mlx);
t_color				left_wall(t_data *data);
t_color				right_wall(t_data *data);
t_color				down_wall(t_data *data);
t_color				up_wall(t_data *data);
int					integrate_color(double r, double g, double b);
void				to_lvl1(t_data *d);
void				to_lvl0(t_data *d);
void				set_color1(t_color *rbg, double wall_dist, int side);
void				help_func2(t_ray_d *rd, int *side);

#endif
