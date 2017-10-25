//
// Created by Alisa Soroka on 10/25/17.
//

#include "../wolf3d.h"

int         rotate(int keycode, int x, int y, t_data *d)
{
//    if (y > -1 && keycode > -100 && abs(x) > (d->mouse_x))
//    {
    printf("%d\n", x);
//        double oldDirX = d->dirX;
//        d->dirX = d->dirX * cos(-d->rotSpeed) - d->dirY * sin(-d->rotSpeed);
//        d->dirY = oldDirX * sin(-d->rotSpeed) + d->dirY * cos(-d->rotSpeed);
//        double oldPlaneX = d->planeX;
//        d->planeX = d->planeX * cos(-d->rotSpeed) - d->planeY * sin(-d->rotSpeed);
//        d->planeY = oldPlaneX * sin(-d->rotSpeed) + d->planeY * cos(-d->rotSpeed);
//        d->mouse_x = x;
//    }
//    else
//    {
//        double oldDirX = d->dirX;
//        d->dirX = d->dirX * cos(d->rotSpeed) - d->dirY * sin(d->rotSpeed);
//        d->dirY = oldDirX * sin(d->rotSpeed) + d->dirY * cos(d->rotSpeed);
//        double oldPlaneX = d->planeX;
//        d->planeX = d->planeX * cos(d->rotSpeed) - d->planeY * sin(d->rotSpeed);
//        d->planeY = oldPlaneX * sin(d->rotSpeed) + d->planeY * cos(d->rotSpeed);
//        d->mouse_x = x;
//    }
    putImage(d);
}