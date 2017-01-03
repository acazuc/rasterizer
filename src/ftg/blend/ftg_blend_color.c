/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_blend_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:26:14 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:35:47 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_blend_color(t_ftg_clampf red, t_ftg_clampf green, t_ftg_clampf blue
		, t_ftg_clampf alpha)
{
	red = ftg_maxf(0, ftg_minf(1, red));
	green = ftg_maxf(0, ftg_minf(1, green));
	blue = ftg_maxf(0, ftg_minf(1, blue));
	alpha = ftg_maxf(0, ftg_minf(1, alpha));
	g_ctx->blend_color[0] = red;
	g_ctx->blend_color[1] = green;
	g_ctx->blend_color[2] = blue;
	g_ctx->blend_color[3] = alpha;
}
