/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:58:28 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/18 19:26:23 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void			rayCasting(t_data *data)
{
	double		x;
	double		dist;
	double		angleCurrent;

	angleCurrent = data->dir - fov / 2;
	while (x < WIDTH)
	{
		//dist = castRay(data, angleCurrent);
		//putColumn(data, dist);
		x++;
		angleCurrent += data->anglInc;
	}
}
