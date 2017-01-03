/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_draw_arrays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:31:42 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:32:20 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

static void	_draw_case(t_ftg_enum mode, t_ftg_int first, t_ftg_sizei count)
{
	if (mode == FTG_POINTS)
		ftg_draw_arrays_points(first, count);
	else if (mode == FTG_LINE_STRIP)
		ftg_draw_arrays_line_strip(first, count);
	else if (mode == FTG_LINES)
		ftg_draw_arrays_lines(first, count);
	else if (mode == FTG_TRIANGLES)
		ftg_draw_arrays_triangles(first, count);
	else if (mode == FTG_QUADS)
		ftg_draw_arrays_quads(first, count);
}

void		ftg_draw_arrays(t_ftg_enum mode, t_ftg_int first, t_ftg_sizei count)
{
	if (mode != FTG_POINTS && mode != FTG_LINE_STRIP && mode != FTG_LINE_LOOP && mode != FTG_LINES
		&& mode != FTG_TRIANGLE_STRIP && mode != FTG_TRIANGLE_FAN && mode != FTG_TRIANGLES
		&& mode != FTG_QUAD_STRIP && mode != FTG_QUADS && mode != FTG_POLYGONS)
	{
		g_ctx->errno = FTG_INVALID_ENUM;
		return ;
	}
	if (count < 0)
	{
		g_ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	if (!g_ctx->vertex_array)
		return ;
	if (!count)
		return;
	_draw_case(mode, first, count);
}
