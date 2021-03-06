/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:46:44 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/30 18:46:48 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

static void		make_img_transparent(t_mlx *mlx)
{
	int			i;
	int			i_max;

	i = -1;
	i_max = WIDTH * HEIGHT;
	while (++i < i_max)
	{
		mlx->imdata[i] = 0xFFFFFFFF;
	}
}

void			create_image(t_mlx *mlx)
{
	int			bpss;
	int			endian;

	mlx->im = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->imdata = (int *)mlx_get_data_addr(mlx->im, &bpss, &mlx->ls, &endian);
	make_img_transparent(mlx);
}
