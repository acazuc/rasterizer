/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_rast_line_draws.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:25:30 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:25:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_rast_line_draw_top(t_vec4 *start, t_vec4 *dif)
{
	t_vec4	tmp;
	double	iter;
	double	fac;

	iter = 0;
	while (iter <= dif->y)
	{
		fac = iter / dif->y;
		vec4_mul(&tmp, dif, fac);
		vec4_add(&tmp, &tmp, start);
		ftg_rast_pixel_put(&tmp);
		++iter;
	}
}

void	ftg_rast_line_draw_bottom(t_vec4 *start, t_vec4 *dif)
{
	t_vec4	tmp;
	double	iter;
	double	fac;

	iter = 0;
	while (iter >= dif->y)
	{
		fac = iter / dif->y;
		vec4_mul(&tmp, dif, fac);
		vec4_add(&tmp, &tmp, start);
		ftg_rast_pixel_put(&tmp);
		--iter;
	}
}

void	ftg_rast_line_draw_right(t_vec4 *start, t_vec4 *dif)
{
	t_vec4	tmp;
	double	iter;
	double	fac;

	iter = 0;
	while (iter <= dif->x)
	{
		fac = iter / dif->x;
		vec4_mul(&tmp, dif, fac);
		vec4_add(&tmp, &tmp, start);
		ftg_rast_pixel_put(&tmp);
		++iter;
	}
}

void	ftg_rast_line_draw_left(t_vec4 *start, t_vec4 *dif)
{
	t_vec4	tmp;
	double	iter;
	double	fac;

	iter = 0;
	while (iter >= dif->x)
	{
		fac = iter / dif->x;
		vec4_mul(&tmp, dif, fac);
		vec4_add(&tmp, &tmp, start);
		ftg_rast_pixel_put(&tmp);
		--iter;
	}
}
