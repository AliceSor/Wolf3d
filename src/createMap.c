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
#include <stdio.h>


void			createMap(t_data *d)
{
	int		x, y;

	y = -1;
	d->map = (int **)malloc(sizeof(int *) * 11);
	while (++y < 10)
		d->map[y] = (int *)malloc(sizeof(int) * 11);
	d->map[y] = NULL;
	y = -1;
	x = -1;
	while (++y < 10)
	{
		x = -1;
		while (++x < 10)
			d->map[y][x] = 0;
	}
	y = -1;
	while (++y < 10)
	{
		d->map[y][0] = 1;
		d->map[y][9] = 1;
	}
	x = -1;
	while (++x < 10)
	{
		d->map[0][x] = 1;
		d->map[9][x] = 1;
	}
	y = -1;
	x = -1;
	while (++y < 10)
	{
		x = -1;
		while (++x < 10)
			printf("%d",d->map[y][x]);
		printf("\n");
	}
//	return (map);
}
// 