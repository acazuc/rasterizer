/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_draw_arrays_get_vec_texture_coord.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 13:31:01 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/21 13:41:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

static t_ftg_float	_get_val(t_ftg_int arr_pos)
{
	if (g_ctx->color_array_type == FTG_SHORT)
		return (((t_ftg_short*)g_ctx->texture_coord_array_pointer)[arr_pos] / (t_ftg_float)SHRT_MAX);
	else if (g_ctx->color_array_type == FTG_INT)
		return (((t_ftg_int*)g_ctx->texture_coord_array_pointer)[arr_pos] / (t_ftg_float)INT_MAX);
	else if (g_ctx->color_array_type == FTG_FLOAT)
		return (((t_ftg_float*)g_ctx->texture_coord_array_pointer)[arr_pos]);
	else if (g_ctx->color_array_type == FTG_DOUBLE)
		return (((t_ftg_double*)g_ctx->texture_coord_array_pointer)[arr_pos]);
	return (0);
}

void	ftg_draw_arrays_get_vec_texture_coord(t_vec4 *vec, t_ftg_int pos)
{
	t_ftg_int	arr_pos;

	arr_pos = pos * (g_ctx->texture_coord_array_size + g_ctx->texture_coord_array_stride);
	if (g_ctx->texture_coord_array_size == 1)
	{
		vec->u = ftg_minf(1, ftg_maxf(0, _get_val(arr_pos)));
		vec->v = 0;
	}
	else if (g_ctx->texture_coord_array_size >= 2)
	{
		vec->u = ftg_minf(1, ftg_maxf(0, _get_val(arr_pos)));
		vec->v = ftg_minf(1, ftg_maxf(0, _get_val(arr_pos + 1)));
	}
	else
	{
		vec->u = 0;
		vec->v = 0;
	}
}
