/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integrate_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:49:44 by asoroka           #+#    #+#             */
/*   Updated: 2017/07/21 18:49:45 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int				integrate_color(double r, double g, double b, double a)
{
	int			res;

//	r = (r / 100) * 255;
//	g = (g / 100) * 255;
//	b = (b / 100) * 255;
//	r = (r < 255) ? r : 255;
//	g = (g < 255) ? g : 255;
//	b = (b < 255) ? b : 255;
	res = ((int)r << 16) + ((int)g << 8) + (int)b + (int)a;
	return (res);
}
