/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 18:01:08 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/18 19:24:37 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static void		init(t_data *d)
{
	d = (t_data *)malloc(sizeof(t_data) + 10);

	if (d)
	{
		d->mlx = create_win();
		d->player = (t_player *)malloc(sizeof(t_player) + 10);
		// d->map = createMap();
		d->h = 64;
	}
}

int				main(void)
{
	int			isParse;
	t_data		*data;

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
	//
	//mlx_hook(data->mlx->win, 2, 5, buttons, rt);
	//mlx_hook(data->mlx->win, 17, 0, destroy, 0);
	mlx_loop(data->mlx->mlx);
	return (0);
}
