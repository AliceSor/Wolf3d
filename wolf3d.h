//
// Created by Alisa Soroka on 8/15/17.
//

#ifndef WOLF3D_H
# define WOLF3D_H
# define HEIGHT 900
# define WIDTH 1200
# define RAD 0.01745329251994

# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_ray_d
{
    int x;
    double pos_x;
    double pos_y;
    double dir_x;
    double dir_y;
    int map_x;
    int map_y;
    double side_d_x;
    double side_d_y;
    double delta_d_x ;
    double delta_d_y ;
    int step_x;
    int step_y;
}               t_ray_d;

typedef struct s_img
{
    void        *im;
    int         *imdata;
    int         ls;
}               t_img;

typedef struct s_xpm
{
    void        *xpm;
    int        *imdata;
    int         ls;
    int         width;
    int         height;
    t_img       *img;
}               t_xpm;

typedef struct s_mlx
{
	void		*win;
	void		*mlx;
	void		*im;
	int			*imdata;
	int			ls;
    t_xpm       *xpm;
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
    double moveSpeed;
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
int         rotate(int x, int y, t_data *data);
void			create_xpm(t_mlx *mlx, const char *file);

#endif
