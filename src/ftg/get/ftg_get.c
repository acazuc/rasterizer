/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:01:46 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:29:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

t_ftg_boolean	ftg_get(t_ftg_enum pname, void **data, t_ftg_enum *format, t_ftg_uint *length)
{
	if (pname == FTG_MATRIX_MODE)
	{
		*data = &g_ctx->matrix_mode;
		*format = FTG_INT;
		*length = 1;
	}
	else if (pname == FTG_MODELVIEW_MATRIX)
	{
		*data = g_ctx->matrix_modelview.value;
		*format = FTG_DOUBLE;
		*length = 16;
	}
	else if (pname == FTG_PROJECTION_MATRIX)
	{
		*data = g_ctx->matrix_projection.value;
		*format = FTG_DOUBLE;
		*length = 16;
	}
	else if (pname == FTG_DEPTH_RANGE)
	{
		*data = g_ctx->depth_range;
		*format = FTG_CLAMPD;
		*length = 2;
	}
	else if (pname == FTG_DEPTH_FUNC)
	{
		*data = &g_ctx->depth_func;
		*format = FTG_ENUM;
		*length = 1;
	}
	else if (pname == FTG_DEPTH_TEST)
	{
		*data = &g_ctx->depth_test;
		*format = FTG_BOOLEAN;
		*length = 1;
	}
	else if (pname == FTG_DEPTH_WRITEMASK)
	{
		*data = &g_ctx->depth_writemask;
		*format = FTG_BOOLEAN;
		*length = 1;
	}
	else if (pname == FTG_BLEND_SRC_RGB)
	{
		*data = &g_ctx->blend_src_rgb;
		*format = FTG_ENUM;
		*length = 1;
	}
	else if (pname == FTG_BLEND_SRC_ALPHA)
	{
		*data = &g_ctx->blend_src_alpha;
		*format = FTG_ENUM;
		*length = 1;
	}
	else if (pname == FTG_BLEND_DST_RGB)
	{
		*data = &g_ctx->blend_dst_rgb;
		*format = FTG_ENUM;
		*length = 1;
	}
	else if (pname == FTG_BLEND_DST_ALPHA)
	{
		*data = &g_ctx->blend_dst_alpha;
		*format = FTG_ENUM;
		*length = 1;
	}
	else if (pname == FTG_BLEND_COLOR)
	{
		*data = g_ctx->blend_color;
		*format = FTG_CLAMPF;
		*length = 4;
	}
	else if (pname == FTG_BLEND_EQUATION_RGB)
	{
		*data = &g_ctx->blend_equation_rgb;
		*format = FTG_ENUM;
		*length = 1;
	}
	else if (pname == FTG_BLEND_EQUATION_ALPHA)
	{
		*data = &g_ctx->blend_equation_alpha;
		*format = FTG_ENUM;
		*length = 1;
	}
	else if (pname == FTG_BLEND)
	{
		*data = &g_ctx->blend;
		*format = FTG_BOOLEAN;
		*length = 1;
	}
	else if (pname == FTG_FOG)
	{
		*data = &g_ctx->fog;
		*format = FTG_BOOLEAN;
		*length = 1;
	}
	else if (pname == FTG_FOG_COLOR)
	{
		*data = g_ctx->fog_color;
		*format = FTG_CLAMPF;
		*length = 4;
	}
	else if (pname == FTG_FOG_DENSITY)
	{
		*data = &g_ctx->fog_density;
		*format = FTG_CLAMPD;
		*length = 1;
	}
	else if (pname == FTG_FOG_END)
	{
		*data = &g_ctx->fog_end;
		*format = FTG_CLAMPD;
		*length = 1;
	}
	else if (pname == FTG_FOG_START)
	{
		*data = &g_ctx->fog_start;
		*format = FTG_CLAMPD;
		*length = 1;
	}
	else if (pname == FTG_FOG_INDEX)
	{
		*data = &g_ctx->fog_index;
		*format = FTG_CLAMPD;
		*length = 1;
	}
	else if (pname == FTG_FOG_MODE)
	{
		*data = &g_ctx->fog_mode;
		*format = FTG_ENUM;
		*length = 1;
	}
	else
	{
		g_ctx->errno = FTG_INVALID_ENUM;
		return (FTG_FALSE);
	}
	return (FTG_TRUE);
}
