/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_blend_equation_separate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:27:41 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 19:02:26 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*ctx;

static t_ftg_boolean	mode_is_valid(t_ftg_enum mode)
{
	if (mode == FTG_FUNC_ADD || mode == FTG_FUNC_SUBSTRACT
		|| mode == FTG_FUNC_REVERSE_SUBSTRACT || mode == FTG_MIN
		|| mode == FTG_MAX)
		return (FTG_TRUE);
	return (FTG_FALSE);
}

void					ftg_blend_equation_separate(t_ftg_enum mode_rgb
		, t_ftg_enum mode_alpha)
{
	if (!mode_is_valid(mode_rgb)
			|| !mode_is_valid(mode_alpha))
	{
		ctx->errno = FTG_INVALID_ENUM;
		return ;
	}
	ctx->blend_equation_rgb = mode_rgb;
	ctx->blend_equation_alpha = mode_alpha;
}
