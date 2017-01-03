/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_blend_func_separate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:28:59 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 17:29:54 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*ctx;

static t_ftg_boolean	factor_is_valid(t_ftg_enum s_factor
		, t_ftg_enum d_factor)
{
	if (s_factor == FTG_ZERO || s_factor == FTG_ONE
		|| s_factor == FTG_SRC_COLOR || s_factor == FTG_ONE_MINUS_SRC_COLOR
		|| s_factor == FTG_DST_COLOR || s_factor == FTG_ONE_MINUS_DST_COLOR
		|| s_factor == FTG_SRC_ALPHA || s_factor == FTG_ONE_MINUS_SRC_ALPHA
		|| s_factor == FTG_DST_ALPHA || s_factor == FTG_ONE_MINUS_DST_ALPHA
		|| s_factor == FTG_CONSTANT_COLOR
		|| s_factor == FTG_ONE_MINUS_CONSTANT_COLOR
		|| s_factor == FTG_CONSTANT_ALPHA
		|| s_factor == FTG_ONE_MINUS_CONSTANT_ALPHA
		|| s_factor == FTG_SRC_ALPHA_SATURATE)
		return (FTG_TRUE);
	if (d_factor == FTG_ZERO || d_factor == FTG_ONE
		|| d_factor == FTG_SRC_COLOR || d_factor == FTG_ONE_MINUS_SRC_COLOR
		|| d_factor == FTG_DST_COLOR || d_factor == FTG_ONE_MINUS_DST_COLOR
		|| d_factor == FTG_SRC_ALPHA || d_factor == FTG_ONE_MINUS_SRC_ALPHA
		|| d_factor == FTG_DST_ALPHA || d_factor == FTG_ONE_MINUS_DST_ALPHA
		|| d_factor == FTG_CONSTANT_COLOR
		|| d_factor == FTG_ONE_MINUS_CONSTANT_COLOR
		|| d_factor == FTG_CONSTANT_ALPHA
		|| d_factor == FTG_ONE_MINUS_CONSTANT_ALPHA)
		return (FTG_TRUE);
	return (FTG_FALSE);
}

void					ftg_blend_func_separate(t_ftg_enum src_rgb
		, t_ftg_enum dst_rgb, t_ftg_enum src_alpha, t_ftg_enum dst_alpha)
{
	if (!factor_is_valid(src_rgb, dst_rgb)
			|| !factor_is_valid(src_alpha, dst_alpha))
	{
		ctx->errno = FTG_INVALID_ENUM;
		return ;
	}
	ctx->blend_src_rgb = src_rgb;
	ctx->blend_src_alpha = src_alpha;
	ctx->blend_dst_rgb = dst_rgb;
	ctx->blend_dst_alpha = dst_alpha;
}
