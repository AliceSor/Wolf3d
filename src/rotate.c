//
// Created by Alisa Soroka on 10/25/17.
//

#include "../wolf3d.h"

int         rotate(int x, int y, t_data *d)
{
    if (d->start == 1)
    {
        if ((x - d->mouse_x) > 0)
        {
            double oldDirX = d->dirX;
            d->dirX = d->dirX * cos(-d->rot_speed) - d->dirY * sin(-d->rot_speed);
            d->dirY = oldDirX * sin(-d->rot_speed) + d->dirY * cos(-d->rot_speed);
            double oldPlaneX = d->planeX;
            d->planeX = d->planeX * cos(-d->rot_speed) - d->planeY * sin(-d->rot_speed);
            d->planeY = oldPlaneX * sin(-d->rot_speed) + d->planeY * cos(-d->rot_speed);
            d->rot -= 5;
            if (d->rot < -2200)
                d->rot = -1200;

        }
        else
        {
            double oldDirX = d->dirX;
            d->dirX = d->dirX * cos(d->rot_speed) - d->dirY * sin(d->rot_speed);
            d->dirY = oldDirX * sin(d->rot_speed) + d->dirY * cos(d->rot_speed);
            double oldPlaneX = d->planeX;
            d->planeX = d->planeX * cos(d->rot_speed) - d->planeY * sin(d->rot_speed);
            d->planeY = oldPlaneX * sin(d->rot_speed) + d->planeY * cos(d->rot_speed);
            d->mouse_x = x;
            d->rot += 5;
            if (d->rot > 100)
                d->rot = -1200;
        }
        d->mouse_x = x;
        putImage(d);
    }
    return (0);
}