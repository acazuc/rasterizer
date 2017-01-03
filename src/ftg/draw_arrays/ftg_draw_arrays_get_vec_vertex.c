/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_draw_arrays_get_vec_vertex.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:30:39 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:31:18 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

static t_ftg_double	_get_val(t_ftg_int arr_pos)
{
	if (g_ctx->vertex_array_type == FTG_SHORT)
		return (((t_ftg_short*)g_ctx->vertex_array_pointer)[arr_pos]);
	else if (g_ctx->vertex_array_type == FTG_INT)
		return (((t_ftg_int*)g_ctx->vertex_array_pointer)[arr_pos]);
	else if (g_ctx->vertex_array_type == FTG_FLOAT)
		return (((t_ftg_float*)g_ctx->vertex_array_pointer)[arr_pos]);
	else if (g_ctx->vertex_array_type == FTG_DOUBLE)
		return (((t_ftg_double*)g_ctx->vertex_array_pointer)[arr_pos]);
	return (0);
}

void	ftg_draw_arrays_get_vec_vertex(t_vec4 *vec, t_ftg_int pos)
{
	t_ftg_int	arr_pos;

	arr_pos = pos * (g_ctx->vertex_array_size + g_ctx->vertex_array_stride);
	if (g_ctx->vertex_array_size == 2)
	{
		vec->x = _get_val(arr_pos);
		vec->y = _get_val(arr_pos + 1);
		vec->z = 0;
		vec->w = 1;
	}
	else if (g_ctx->vertex_array_size == 3)
	{
		vec->x = _get_val(arr_pos);
		vec->y = _get_val(arr_pos + 1);
		vec->z = _get_val(arr_pos + 2);
		vec->w = 1;
	}
	else if (g_ctx->vertex_array_size == 4)
	{
		vec->x = _get_val(arr_pos);
		vec->y = _get_val(arr_pos + 1);
		vec->z = _get_val(arr_pos + 2);
		vec->w = _get_val(arr_pos + 3);
	}
	else
		ft_memset(vec, 0, sizeof(*vec));
}
