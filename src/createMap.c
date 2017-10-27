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
	d->map = (int **)malloc(sizeof(int *) * 21);
	while (++y < 20)
		d->map[y] = (int *)malloc(sizeof(int) * 21);
	// d->map[y] = NULL;
	y = -1;
	x = -1;
	while (++y < 20)
	{
		x = -1;
		while (++x < 20)
			d->map[y][x] = 0;
	}
	y = -1;
	while (++y < 20)
	{
		d->map[y][0] = 1;
		d->map[y][19] = 1;
	}
	x = -1;
	while (++x < 20)
	{
		d->map[0][x] = 1;
		d->map[19][x] = 1;
	}
	y = -1;
	while (++y < 20)
	{
		x = -1;
		while (++x < 20)
			printf("%d",d->map[y][x]);
		printf("\n");
	}

//	d->map[33][20] = 2;
//	d->map[33][21] = 3;
//	d->map[33][22] = 4;
//	d->map[33][23] = 1;
//	return (map);
}
// 