//
// Created by Alisa Soroka on 8/15/17.
//

#ifndef WOLF3D_H
# define WOLF3D_H
# define HEIGHT 800
# define WIDTH 1000
# define RAD 0.01745329251994
# define PLAYER data->player

# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>

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
 int			mapX;
 int			mapY;
 double			fov;
 double			dir;
 double			anglIncrement;
 double			height;
 double			tanVertFOV;
}				t_player;

typedef struct	s_data
{
	t_mlx		*mlx;
	t_player	*player;
	int			**map;
	double		h;
}				t_data;

t_mlx			*create_win(void);
void			create_image(t_mlx *mlx);
void			putPixel(int x, int y, int color, t_mlx *mlx);
void			rayCasting(t_data *data);
void			putColum(t_data *data, double dist);
void			putColumn(t_data *data, int x, double dist);
int				parseMap(t_data *data);
double			rayHorizontal(t_data *data, double angle);
double			rayVertical(t_data *data, double angle);
void				createMap(t_data *d);

#endif
