/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 18:01:08 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/22 19:48:37 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static void		init(t_data *d)
{
	if (d)
	{
		d->mlx = create_win();
		d->h  = 1;
		create_image(d->mlx);
        d->posX = 22;
        d->posY = 12;
        d->dirX = -1;
        d->dirY = 0;
        d->planeX = 0;
        d->planeY = 0.66;
        d->moveSpeed = 1;
        d->rotSpeed = 5 * RAD;
        d->mouse_x = 0;
        createMap(d);
	}
}

int				main(void)
{
//	int			isParse;
	t_data		*data;

	data = (t_data *)malloc(sizeof(t_data) + 10);
	init(data);
	//
	//isParse = parseMap(data);
	//
	//if (isParse == -1)
	//{
	//	errorMessage();
	//	return (0);
	//}
	//
	rayCasting(data); //finished
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->im, -1, -1);
	//
	mlx_hook(data->mlx->win, 2, 5, buttons, data);
	mlx_hook(data->mlx->win, 17, 0, destroy, 0);
    mlx_mouse_hook(data->mlx->win, rotate, data);
//    mlx_hook(data->mlx->win, 6, 0, rotate, data);
	mlx_loop(data->mlx->mlx);
	return (0);
}

