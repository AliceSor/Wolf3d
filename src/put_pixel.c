/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 21:37:32 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/30 21:37:40 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void			put_pixel(int x, int y, int color, t_mlx *mlx)
{
	int			i;

	i = mlx->ls * y / 4 + x;
	if (i < WIDTH * HEIGHT && i > 0)
		mlx->imdata[i] = color;
}