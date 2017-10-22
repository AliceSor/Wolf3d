/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:58:28 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/22 19:38:57 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static double	castRay(t_data *data, double angle)
{
	double		dist, distHor, distVer;

	distHor = rayHorizontal(data, angle);
	distVer = rayVertical(data, angle);

	dist = (distVer < distHor) ? distVer : distVer;
	return (dist);
}

void			rayCasting(t_data *data)
{
	int		x;
	double		dist;
	double		angleCurrent;

	x = 0;
	
	angleCurrent = PLAYER->dir - PLAYER->fov / 2;
	while (x < WIDTH)
	{
		dist = castRay(data, angleCurrent);
		putColumn(data, x, dist);
		x++;
		angleCurrent += PLAYER->anglIncrement;
	}
}
