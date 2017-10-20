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

double			rayVertical(t_data *data, double angle)
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
	isObj = data->map[mapY][mapX];
	x += dirX * h;
	y += dirY * deltaY;
	deltaY = h * tan(beta);
	while (!isObj)
	{
		mapX += dirX;
		mapY += dirY;
		isObj = data->map[mapY][mapX];
		x += dirX * h;
		y += dirY * deltaY;
	}
	return (dist);
}

double			rayHorizontal(t_data *data, double angle)
{
	double		dist;
	double		x;
	double		y;
	double		aY;
	double		mapX;
	double		mapY;
	double		beta;
	double		dirX, dirY;
	double		deltaX;
	int		isObj;

	dist = 0;
//	dirX = findDirX(angle);
//	dirY = findDirY(angle);
//	beta = findBeta(angle);
	//aY = (dirX > 0) ? (x / h + 1) * h : (x / h) * h;
	deltaX = fabs((aY - y) * tan(beta));
	dist += deltaX;
	mapX += dirX;
	mapY += dirY;
	isObj = data->map[mapY][mapX];
	x += dirX * deltaX;
	y += dirY * h;
	deltaX = h * tan(beta);
	while (!isObj)
	{
		mapX += dirX;
		mapY += dirY;
		dist += deltaX;
		isObj = data->map[mapY][mapX];
		x += dirX * deltaX;
		y += dirY * h;
	}
	return (dist);
}
