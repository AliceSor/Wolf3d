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

static void		setDir(double angle, int *dirX, int *dirY)
{
	*dirY = (angle >= 0 && angle <= 180) ? 1 : -1;
	*dirX = (angle >= 90 && angle <= 270) - 1 : 1;
}

static doouble	findBetaHor(double angle)
{
	if (angle > 90 && angle <= 180)
		return (angle - 90);
	else if (angle > 180 && angle <= 270)
		return (270 - angle);
	else if (angle > 270 && angle <= 360)
		return (angle - 270);
	else
		return (90 - angle);
}

static doouble	findBetaVer(double angle)
{
	if (angle > 90 && angle <= 180)
		return (180 - angle);
	else if (angle > 180 && angle <= 270)
		return (angle - 180);
	else if (angle > 270 && angle <= 360)
		return (360 -angle);
	else
		return (angle);
}

double			rayVertical(t_data *data, double angle)
{
	double		dist;
	double		x;
	double		y;
	double		aX;
	double		mapX;
	double		mapY;
	double		beta;
	double		deltaY;
	int			dirX, dirY;
	int			isObj;

	dist = 0;
	setDir(angle, &dirX, &dirY);
	beta = findBetaVer(angle);
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
	setDir(angle, &dirX, &dirY);
	beta = findBetaHor(angle);
	aY = (dirX > 0) ? (x / h + 1) * h : (x / h) * h;
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
