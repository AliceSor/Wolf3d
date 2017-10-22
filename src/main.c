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
		d->h  = 64;
		create_image(d->mlx);
		d->player = (t_player *)malloc(sizeof(t_player) + 10);
		d->player->mapX = 2;
 		d->player->mapY = 7;
 		d->player->x = d->player->mapX * d->h + 6;
 		d->player->y = d->player->mapY * d->h + 6;
 		d->player->fov = 60;
 		d->player->dir = 45;
 		d->player->anglIncrement = WIDTH / d->player->fov;
 		d->player->tanVertFOV = 1.732050807568877;
 		
		createMap(d);
		write(1, "*", 1);
		int i = (d->map)[0][0];
		printf("here%d", i);
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
	//mlx_hook(data->mlx->win, 2, 5, buttons, rt);
	//mlx_hook(data->mlx->win, 17, 0, destroy, 0);
	mlx_loop(data->mlx->mlx);
	return (0);
}
