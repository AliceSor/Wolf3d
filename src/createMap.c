/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createMap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 18:44:36 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/22 19:25:14 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static void     lvl0(t_data *d)
{
    int		x, y;
    int     i;

    i = 3;
    while (++i < 16)
    {
        d->map[2][i] = 1;
        d->map[15][i] = 1;
    }
    i = 2;
    while (++i < 15)
    {
        d->map[i][4] = 1;
        d->map[i][15] = 1;
    }
    d->map[10][15] = 0;
    d->map[3][5] = 3;
    d->map[3][14] = 3;
    d->map[14][5] = 3;
    d->map[14][14] = 3;
    d->map[8][10] = 4;
}
static void     lvl1(t_data *d)
{
    int     i;

    i = 3;
    while (++i < 16)
    {
        d->map[2][i] = 2;
        d->map[15][i] = 2;
    }
    i = 2;
    while (++i < 15)
    {
        d->map[i][4] = 2;
        d->map[i][15] = 2;
    }
    d->map[10][15] = 0;
    d->map[10][2] = 0;
    d->map[3][5] = 1;
    d->map[3][14] = 1;
    d->map[14][5] = 1;
    d->map[14][14] = 1;
    d->map[8][10] = 3;
}


void			createMap(t_data *d)
{
	int		x, y;

	y = -1;

        d->map = (int **) malloc(sizeof(int *) * 21);
        while (++y < 20)
            d->map[y] = (int *) malloc(sizeof(int) * 21);
        y = -1;
        x = -1;
        while (++y < 20) {
            x = -1;
            while (++x < 20)
                d->map[y][x] = 0;
        }
        y = -1;
        while (++y < 20) {
            d->map[y][0] = 1;
            d->map[y][19] = 1;
        }
        x = -1;
        while (++x < 20) {
            d->map[0][x] = 1;
            d->map[19][x] = 1;
        }
        y = -1;
        if (d->lvl == 0)
            lvl0(d);

        else
            lvl1(d);
        while (++y < 20) {
            x = -1;
            while (++x < 20)
                printf("%d", d->map[y][x]);
            printf("\n");
        }
}