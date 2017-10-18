/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findRay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:52:54 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/18 21:07:52 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

double			rayHorizontal(t_data *data, double angle)
{
	double		dist;
	double		x;
	double		y;
	double		aX;
	double		mapX;
	double		mapY;
	double		beta;
	double		dirX, dirY;
	double		deltaY;
	int			isObj;

	dist = 0;
//	dirX = findDirX(angle);
//	dirY = findDirY(angle);
//	beta = findBeta(angle);
	aX = (dirX > 0) ? (x / h + 1) * h : (x / h) * h;
	deltaY = fabs((aX - x) * tan(beta));
	dist += deltaY;
	mapX += dirX;
	mapY += dirY;
	//isObj = checkMap(data, mapX, mapY);
	x += dirX * h;
	y += dirY * deltaY;
	deltaY = h * tan(beta);
	while (!isObj)
	{
		mapX += dirX;
		mapY += dirY;
		//isObj = checkMap(data, mapX, mapY);
		x += dirX * h;
		y += dirY * deltaY;
	}
	return (dist);
}

double			rayVertical(t_data *data, double angle);
