//
// Created by Alisa Soroka on 10/28/17.
//

#include "../wolf3d.h"

t_color up_wall(t_data *data)
{
    t_color r;

    if (data->lvl == 0)
    {
        r.r = 190;
        r.g = 108;
        r.b = 20;
    }
    return r;
}

t_color down_wall(t_data *data)
{
    t_color r;

    if (data->lvl == 0)
    {
        r.r = 189;
        r.g = 70;
        r.b = 26;
    }
    return r;
}

t_color right_wall(t_data *data)
{
    t_color r;

    if (data->lvl == 0)
    {
        r.r = 214;
        r.g = 100;
        r.b = 18;
    }
    return r;
}

t_color left_wall(t_data *data)
{
    t_color r;

    if (data->lvl == 0)
    {
        r.r = 250;
        r.g = 148;
        r.b = 30;
    }
    return r;
}