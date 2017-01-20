/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_rast_pixel_set_blend_func_rgb.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:00:09 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 18:38:08 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

static void	do_4(t_color *color, t_color *src, t_color *dst, t_ftg_enum mode)
{
	if (mode == FTG_CONSTANT_ALPHA)
	{
		color->red *= g_ctx->blend_color[3];
		color->green *= g_ctx->blend_color[3];
		color->blue *= g_ctx->blend_color[3];
	}
	else if (mode == FTG_ONE_MINUS_CONSTANT_ALPHA)
	{
		color->red *= 1 - g_ctx->blend_color[3];
		color->green *= 1 - g_ctx->blend_color[3];
		color->blue *= 1 - g_ctx->blend_color[3];
	}
	else if (mode == FTG_SRC_ALPHA_SATURATE)
	{
		color->red *= ftg_minf(src->alpha, 1 - dst->alpha);
		color->green *= ftg_minf(src->alpha, 1 - dst->alpha);
		color->blue *= ftg_minf(src->alpha, 1 - dst->alpha);
	}
}

static void	do_3(t_color *color, t_color *src, t_color *dst, t_ftg_enum mode)
{
	if (mode == FTG_DST_ALPHA)
	{
		color->red *= dst->alpha;
		color->green *= dst->alpha;
		color->blue *= dst->alpha;
	}
	else if (mode == FTG_ONE_MINUS_DST_ALPHA)
	{
		color->red *= 1 - dst->alpha;
		color->green *= 1 - dst->alpha;
		color->blue *= 1 - dst->alpha;
	}
	else if (mode == FTG_CONSTANT_COLOR)
	{
		color->red *= g_ctx->blend_color[0];
		color->green *= g_ctx->blend_color[1];
		color->blue *= g_ctx->blend_color[2];
	}
	else if (mode == FTG_ONE_MINUS_CONSTANT_COLOR)
	{
		color->red *= 1 - g_ctx->blend_color[0];
		color->green *= 1 - g_ctx->blend_color[1];
		color->blue *= 1 - g_ctx->blend_color[2];
	}
	else
		do_4(color, src, dst, mode);
}

static void	do_2(t_color *color, t_color *src, t_color *dst, t_ftg_enum mode)
{
	if (mode == FTG_DST_COLOR)
	{
		color->red *= dst->red;
		color->green *= dst->green;
		color->blue *= dst->blue;
	}
	else if (mode == FTG_ONE_MINUS_DST_COLOR)
	{
		color->red *= 1 - dst->red;
		color->green *= 1 - dst->green;
		color->blue *= 1 - dst->blue;
	}
	else if (mode == FTG_SRC_ALPHA)
	{
		color->red *= src->alpha;
		color->green *= src->alpha;
		color->blue *= src->alpha;
	}
	else if (mode == FTG_ONE_MINUS_SRC_ALPHA)
	{
		color->red *= 1 - src->alpha;
		color->green *= 1 - src->alpha;
		color->blue *= 1 - src->alpha;
	}
	else
		do_3(color, src, dst, mode);
}

void		ftg_rast_pixel_set_blend_func_rgb(t_color *color, t_color *src, t_color *dst, t_ftg_enum mode)
{
	if (mode == FTG_ZERO)
	{
		color->red = 0;
		color->green = 0;
		color->blue = 0;
	}
	else if (mode == FTG_SRC_COLOR)
	{
		color->red *= src->red;
		color->green *= src->green;
		color->blue *= src->blue;
	}
	else if (mode == FTG_ONE_MINUS_SRC_COLOR)
	{
		color->red *= 1 - src->red;
		color->green *= 1 - src->green;
		color->blue *= 1 - src->blue;
	}
	else
		do_2(color, src, dst, mode);
}
