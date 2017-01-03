/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_fog_mode_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:32:53 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:34:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_fog_mode(void *data, t_ftg_enum type)
{
	t_ftg_enum	mode;

	if (type == FTG_FLOAT)
		mode = ((t_ftg_float*)data)[0];
	else if (type == FTG_INT)
		mode = ((t_ftg_int*)data)[0];
	else
		return ;
	if (mode != FTG_EXP && mode != FTG_EXP2 && mode != FTG_LINEAR)
	{
		g_ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	g_ctx->fog_mode = mode;
}

void	ftg_fog_color(void *data, t_ftg_enum type)
{
	t_ftg_clampf	color[4];

	if (type == FTG_FLOAT)
	{
		color[0] = ((t_ftg_float*)data)[0];
		color[1] = ((t_ftg_float*)data)[1];
		color[2] = ((t_ftg_float*)data)[2];
		color[3] = ((t_ftg_float*)data)[3];
	}
	else if (type == FTG_INT)
	{
		color[0] = (t_ftg_clampf)(((t_ftg_int*)data)[0]) / INT_MAX;
		color[1] = (t_ftg_clampf)(((t_ftg_int*)data)[1]) / INT_MAX;
		color[2] = (t_ftg_clampf)(((t_ftg_int*)data)[2]) / INT_MAX;
		color[3] = (t_ftg_clampf)(((t_ftg_int*)data)[3]) / INT_MAX;
	}
	color[0] = ftg_minf(1, ftg_maxf(0, color[0]));
	color[1] = ftg_minf(1, ftg_maxf(0, color[1]));
	color[2] = ftg_minf(1, ftg_maxf(0, color[2]));
	color[3] = ftg_minf(1, ftg_maxf(0, color[3]));
	g_ctx->fog_color[0] = color[0];
	g_ctx->fog_color[1] = color[1];
	g_ctx->fog_color[2] = color[2];
	g_ctx->fog_color[3] = color[3];
}
