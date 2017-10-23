/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findRay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:52:54 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/22 19:31:20 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

//static void		setDir(double angle, int *dirX, int *dirY)
//{
//	*dirY = (angle >= 0 && angle <= 180) ? 1 : -1;
//	*dirX = (angle >= 90 && angle <= 270) ? - 1 : 1;
//}
//
//static double	findBetaHor(double angle)
//{
//	if (angle > 90 && angle <= 180)
//		return ((angle - 90) * RAD);
//	else if (angle > 180 && angle <= 270)
//		return ((270 - angle) * RAD);
//	else if (angle > 270 && angle <= 360)
//		return ((angle - 270) * RAD);
//	else
//		return ((90 - angle) * RAD);
//}
//
//static double	findBetaVer(double angle)
//{
//	if (angle > 90 && angle <= 180)
//		return ((180 - angle) * RAD);
//	else if (angle > 180 && angle <= 270)
//		return ((angle - 180) * RAD);
//	else if (angle > 270 && angle <= 360)
//		return ((360 -angle) * RAD);
//	else
//		return (angle * RAD);
//}
//
//double			rayVertical(t_data *data, double angle)
//{
//	double		dist;
//	double		x;
//	double		y;
//	double		aX;
//	int		mapX;
//	int		mapY;
//	double		beta;
//	double		deltaY;
//	int			dirX, dirY;
//	int			isObj;
//	int			**map;
//
//	x = data->player->x;
//	y = data->player->y;
//	mapX = data->player->mapX;
//	mapY = data->player->mapY;
//
//	map = data->map;
//	double h = data->h;
//	dist = 0;
//	setDir(angle, &dirX, &dirY);
//	beta = findBetaVer(angle);
//	aX = (dirX > 0) ? (x / h + 1) * h : (x / h) * h;
//	deltaY = fabs((aX - x) * tan(beta));
//	dist += deltaY;
//	mapX += dirX;
//	mapY += dirY;
//	isObj = data->map[mapY][mapX];
//	x += dirX * h;
//	y += dirY * deltaY;
//	deltaY = h * tan(beta);
//	int i = 0;
//	while (isObj == 0 && ++i < 100)
//	{
//		mapX += dirX;
//		mapY += dirY;
//		isObj = data->map[mapY][mapX];
//		x += dirX * h;
//		y += dirY * deltaY;
//	}
//	dist = dist/sin(beta);
//	return (dist);
//}
//
//double			rayHorizontal(t_data *data, double angle)
//{
//	double		dist;
//	double		x;
//	double		y;
//	double		aY;
//	int		mapX;
//	int		mapY;
//	double		beta;
//	int			dirX, dirY;
//	double		deltaX;
//	int		isObj;
//	int		**map;
//
//	x = data->player->x;
//	y = data->player->y;
//	mapX = data->player->mapX;
//
//	mapY = data->player->mapY;
//
//	map = data->map;
//
//	double h = data->h;
//	dist = 0;
//	setDir(angle, &dirX, &dirY);
//	beta = findBetaHor(angle);
//	aY = (dirX > 0) ? (x / h + 1) * h : (x / h) * h;
//	deltaX = fabs((aY - y) * tan(beta));
//	dist += deltaX;
//	mapX += dirX;
//	mapY += dirY;
//	isObj = data->map[mapY][mapX];
//
//	 // printf("%f%f", mapX, mapY);
//	x += dirX * deltaX;
//	y += dirY * h;
//	deltaX = h * tan(beta);
//	int i = 0;
//	while (isObj == 0 && ++i < 100)
//	{
//		mapX += dirX;
//		mapY += dirY;
//		dist += deltaX;
//		isObj = data->map[mapY][mapX];
//		x += dirX * deltaX;
//		y += dirY * h;
//	}
//	dist = dist/sin(beta);
//	return (dist);
//}