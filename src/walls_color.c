//
// Created by Alisa Soroka on 10/28/17.
//

#include "../wolf3d.h"

t_color up_wall(t_data *data)
{
    t_color r;

    if (data->lvl == 0)
    {
        r.r = 218;
        r.g = 165;
        r.b = 32;
    }
    else if (data->lvl == 1)
    {
        r.r = 65;
        r.g = 105;
        r.b = 225;
    }
    return r;
}

t_color down_wall(t_data *data)
{
    t_color r;

    if (data->lvl == 0)
    {
        r.r = 244;
        r.g = 164;
        r.b = 96;
    }
    else if (data->lvl == 1)
    {
        r.r = 65;
        r.g = 105;
        r.b = 225;
    }
    return r;
}

t_color right_wall(t_data *data)
{
    t_color r;

    if (data->lvl == 0)
    {
        r.r = 255;
        r.g = 222;
        r.b = 273;
    }
    else if (data->lvl == 1)
    {
        r.r = 65;
        r.g = 105;
        r.b = 225;
    }
    return r;
}

t_color left_wall(t_data *data)
{
    t_color r;

    if (data->lvl == 0)
    {
        r.r = 188;
        r.g = 143;
        r.b = 143;
    }
    else if (data->lvl == 1)
    {
        r.r = 65;
        r.g = 105;
        r.b = 225;
    }
    return r;
}