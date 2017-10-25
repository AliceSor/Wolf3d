//
// Created by Alisa Soroka on 8/15/17.
//

#ifndef WOLF3D_H
# define WOLF3D_H
# define HEIGHT 400
# define WIDTH 600
# define RAD 0.01745329251994

# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_xpm
{
    void        *xpm;
    int        *imdata;
    int         ls;
}               t_xpm;

typedef struct s_mlx
{
	void		*win;
	void		*mlx;
	void		*im;
	int			*imdata;
	int			ls;
}				t_mlx;

typedef struct	s_data
{
	t_mlx		*mlx;
	int			**map;
	double		h;
    double      posX;
    double      posY;  //x and y start position
    double dirX;
    double dirY; //initial direction vector
    double planeX;
    double planeY;
    int moveSpeed;
    double rotSpeed;
    int         mouse_x;
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
int					buttons(int keycode, t_data *data);
void				putImage(t_data *data);
int					destroy(void);
int         rotate(int keycode, int x, int y, t_data *data);

#endif
