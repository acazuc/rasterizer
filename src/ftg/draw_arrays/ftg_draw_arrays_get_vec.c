/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_draw_arrays_get_vec.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:32:21 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:32:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_draw_arrays_get_vec(t_vec4 *vec, t_ftg_int pos)
{
	ftg_draw_arrays_get_vec_vertex(vec, pos);
	if (g_ctx->color_array)
	{
		ftg_draw_arrays_get_vec_color(vec, pos);
	}
	else
	{
		vec->color.red = 1;
		vec->color.green = 1;
		vec->color.blue = 1;
		vec->color.alpha = 1;
	}
	vec->u = 1;
	vec->v = 1;
}
