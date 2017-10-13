//
// Created by Alisa Soroka on 8/15/17.
//

#ifndef WOLF3D_H
#define WOLF3D_H

typedef struct s_mlx
{
	void		*win;
	void		*mlx;
	void		*im;
	int			*imdata;
	int			ls;
}				t_mlx;

typedef struct s_player
{
 double			x;
 double			y;
 double			fov;
 double			dir;
 double			height;
}				t_player;

typedef struct s_data
{
	t_mlx		*mlx;
	t_player	*player;
	char		**map;
}				t_data;

t_mlx			*create_win(void);
void			create_image(t_mlx *mlx);
void			put_pixel(int i, int color, t_mlx *mlx);

#endif
