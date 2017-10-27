//
// Created by Alisa Soroka on 10/25/17.
//

#include "../wolf3d.h"

int         rotate(int x, int y, t_data *d)
{
    if ((x - d->mouse_x) > 0)
    {
        double oldDirX = d->dirX;
        d->dirX = d->dirX * cos(-d->rotSpeed) - d->dirY * sin(-d->rotSpeed);
        d->dirY = oldDirX * sin(-d->rotSpeed) + d->dirY * cos(-d->rotSpeed);
        double oldPlaneX = d->planeX;
        d->planeX = d->planeX * cos(-d->rotSpeed) - d->planeY * sin(-d->rotSpeed);
        d->planeY = oldPlaneX * sin(-d->rotSpeed) + d->planeY * cos(-d->rotSpeed);
    }
    else
    {
        double oldDirX = d->dirX;
        d->dirX = d->dirX * cos(d->rotSpeed) - d->dirY * sin(d->rotSpeed);
        d->dirY = oldDirX * sin(d->rotSpeed) + d->dirY * cos(d->rotSpeed);
        double oldPlaneX = d->planeX;
        d->planeX = d->planeX * cos(d->rotSpeed) - d->planeY * sin(d->rotSpeed);
        d->planeY = oldPlaneX * sin(d->rotSpeed) + d->planeY * cos(d->rotSpeed);
        d->mouse_x = x;
    }
    d->mouse_x = x;
    putImage(d);
    return (0);
}