/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_rast_pixel_set_blend_func_alpha.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 19:21:47 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 19:22:15 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

static void	do_4(t_color *color, t_color *src, t_color *dst, t_ftg_enum mode)
{
	if (mode == FTG_CONSTANT_ALPHA)
		color->alpha *= g_ctx->blend_color[3];
	else if (mode == FTG_ONE_MINUS_CONSTANT_ALPHA)
		color->alpha *= 1 - g_ctx->blend_color[3];
	else if (mode == FTG_SRC_ALPHA_SATURATE)
		color->alpha *= ftg_minf(src->alpha, 1 - dst->alpha);
}

static void	do_3(t_color *color, t_color *src, t_color *dst, t_ftg_enum mode)
{
	if (mode == FTG_DST_ALPHA)
		color->alpha *= dst->alpha;
	else if (mode == FTG_ONE_MINUS_DST_ALPHA)
		color->alpha *= 1 - dst->alpha;
	else if (mode == FTG_CONSTANT_COLOR)
		color->alpha *= g_ctx->blend_color[3];
	else if (mode == FTG_ONE_MINUS_CONSTANT_COLOR)
		color->alpha *= 1 - g_ctx->blend_color[3];
	else
		do_4(color, src, dst, mode);
}

static void	do_2(t_color *color, t_color *src, t_color *dst, t_ftg_enum mode)
{
	if (mode == FTG_DST_COLOR)
		color->alpha *= dst->alpha;
	else if (mode == FTG_ONE_MINUS_DST_COLOR)
		color->alpha *= 1 - dst->alpha;
	else if (mode == FTG_SRC_ALPHA)
		color->alpha *= src->alpha;
	else if (mode == FTG_ONE_MINUS_SRC_ALPHA)
		color->alpha *= 1 - src->alpha;
	else
		do_3(color, src, dst, mode);
}

void		ftg_rast_pixel_set_blend_func_alpha(t_color *color, t_color *src, t_color *dst, t_ftg_enum mode)
{
	if (mode == FTG_ZERO)
		color->alpha = 0;
	else if (mode == FTG_SRC_COLOR)
		color->alpha *= src->alpha;
	else if (mode == FTG_ONE_MINUS_SRC_COLOR)
		color->alpha *= 1 - src->alpha;
	else
		do_2(color, src, dst, mode);
}
