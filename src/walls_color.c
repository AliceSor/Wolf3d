/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:51:32 by asoroka           #+#    #+#             */
/*   Updated: 2017/10/30 19:54:39 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

t_color			up_wall(t_data *data)
{
	t_color		r;

	r.r = 0;
	r.g = 0;
	r.b = 0;
	if (data->for_subject == 1)
	{
		r.r = 255;
		r.g = 0;
		r.b = 0;
	}
	else if (data->lvl == 0)
	{
		r.r = 0;
		r.g = 59;
		r.b = 128;
	}
	else if (data->lvl == 1)
	{
		r.r = 96;
		r.g = 11;
		r.b = 46;
	}
	return (r);
}

t_color			down_wall(t_data *data)
{
	t_color		r;

	r.r = 0;
	r.g = 0;
	r.b = 0;
	if (data->for_subject == 1)
	{
		r.g = 255;
		r.r = 0;
		r.b = 0;
	}
	else if (data->lvl == 0)
	{
		r.r = 6;
		r.g = 84;
		r.b = 147;
	}
	else if (data->lvl == 1)
	{
		r.r = 74;
		r.g = 30;
		r.b = 113;
	}
	return (r);
}

t_color			right_wall(t_data *data)
{
	t_color		r;

	r.r = 0;
	r.g = 0;
	r.b = 0;
	if (data->for_subject == 1)
	{
		r.b = 255;
		r.g = 0;
		r.r = 0;
	}
	else if (data->lvl == 0)
	{
		r.r = 2;
		r.g = 51;
		r.b = 103;
	}
	else if (data->lvl == 1)
	{
		r.r = 23;
		r.g = 21;
		r.b = 103;
	}
	return (r);
}

t_color			left_wall(t_data *data)
{
	t_color		r;

	r.r = 0;
	r.g = 0;
	r.b = 0;
	if (data->for_subject == 1)
	{
		r.r = 0;
		r.g = 150;
		r.b = 150;
	}
	else if (data->lvl == 0)
	{
		r.r = 5;
		r.g = 109;
		r.b = 198;
	}
	else if (data->lvl == 1)
	{
		r.r = 40;
		r.g = 17;
		r.b = 63;
	}
	return (r);
}
