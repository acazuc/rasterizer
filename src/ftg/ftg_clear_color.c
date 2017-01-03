/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_clear_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:13:08 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:40:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_clear_color(t_ftg_clampf red, t_ftg_clampf green
		, t_ftg_clampf blue, t_ftg_clampf alpha)
{
	red = ftg_minf(1, ftg_maxf(0, red));
	green = ftg_minf(1, ftg_maxf(0, green));
	blue = ftg_minf(1, ftg_maxf(0, blue));
	alpha = ftg_minf(1, ftg_maxf(0, alpha));
	g_ctx->clear_color[0] = red;
	g_ctx->clear_color[1] = green;
	g_ctx->clear_color[2] = blue;
	g_ctx->clear_color[3] = alpha;
}
