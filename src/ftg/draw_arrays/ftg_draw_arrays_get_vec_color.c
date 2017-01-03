/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_draw_arrays_get_vec_color.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:32:31 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:37:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

static t_ftg_float	_get_val(t_ftg_int arr_pos)
{
	if (g_ctx->color_array_type == FTG_BYTE)
		return (((t_ftg_byte*)g_ctx->color_array_pointer)[arr_pos] / (t_ftg_float)CHAR_MAX);
	else if (g_ctx->color_array_type == FTG_UNSIGNED_BYTE)
		return (((t_ftg_ubyte*)g_ctx->color_array_pointer)[arr_pos] / (t_ftg_float)UCHAR_MAX);
	else if (g_ctx->color_array_type == FTG_SHORT)
		return (((t_ftg_short*)g_ctx->color_array_pointer)[arr_pos] / (t_ftg_float)SHRT_MAX);
	else if (g_ctx->color_array_type == FTG_UNSIGNED_SHORT)
	 	return (((t_ftg_ushort*)g_ctx->color_array_pointer)[arr_pos] / (t_ftg_float)USHRT_MAX);
	else if (g_ctx->color_array_type == FTG_INT)
		return (((t_ftg_int*)g_ctx->color_array_pointer)[arr_pos] / (t_ftg_float)INT_MAX);
	else if (g_ctx->color_array_type == FTG_UNSIGNED_INT)
		return (((t_ftg_uint*)g_ctx->color_array_pointer)[arr_pos] / (t_ftg_float)UINT_MAX);
	else if (g_ctx->color_array_type == FTG_FLOAT)
		return (((t_ftg_float*)g_ctx->color_array_pointer)[arr_pos]);
	else if (g_ctx->color_array_type == FTG_DOUBLE)
		return (((t_ftg_double*)g_ctx->color_array_pointer)[arr_pos]);
	return (0);
}

void	ftg_draw_arrays_get_vec_color(t_vec4 *vec, t_ftg_int pos)
{
	t_ftg_int	arr_pos;

	arr_pos = pos * (g_ctx->color_array_size + g_ctx->color_array_stride);
	if (g_ctx->color_array_size == 3)
	{
		vec->color.red = ftg_minf(1, ftg_maxf(0, _get_val(arr_pos)));
		vec->color.green = ftg_minf(1, ftg_maxf(0, _get_val(arr_pos + 1)));
		vec->color.blue = ftg_minf(1, ftg_maxf(0, _get_val(arr_pos + 2)));
		vec->color.alpha = 1;
	}
	else if (g_ctx->color_array_size == 4)
	{
		vec->color.red = ftg_minf(1, ftg_maxf(0, _get_val(arr_pos)));
		vec->color.green = ftg_minf(1, ftg_maxf(0, _get_val(arr_pos + 1)));
		vec->color.blue = ftg_minf(1, ftg_maxf(0, _get_val(arr_pos + 2)));
		vec->color.alpha = ftg_minf(1, ftg_maxf(0, _get_val(arr_pos + 3)));
	}
	else
	{
		ft_memset(&vec->color, 0, sizeof(vec->color));
	}
}
