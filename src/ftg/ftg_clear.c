/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:08:50 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:26:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

static void	clear_colors(void)
{
	int	i;

	i = 0;
	while (i < g_ctx->width * g_ctx->height)
	{
		g_ctx->color_buffer[i * 4 + 0] = g_ctx->clear_color[0];
		g_ctx->color_buffer[i * 4 + 1] = g_ctx->clear_color[1];
		g_ctx->color_buffer[i * 4 + 2] = g_ctx->clear_color[2];
		g_ctx->color_buffer[i * 4 + 3] = g_ctx->clear_color[3];
		++i;
	}
}

static void	clear_depth(void)
{
	int	i;

	i = 0;
	while (i < g_ctx->width * g_ctx->height)
	{
		g_ctx->depth_buffer[i] = 1;
		++i;
	}
}

void		ftg_clear(t_ftg_bitmask mask)
{
	if (mask & FTG_COLOR_BUFFER_BIT)
	{
		mask &= ~FTG_COLOR_BUFFER_BIT;
		clear_colors();
	}
	if (mask & FTG_DEPTH_BUFFER_BIT)
	{
		mask &= ~FTG_DEPTH_BUFFER_BIT;
		clear_depth();
	}
	if (mask)
		g_ctx->errno = FTG_INVALID_VALUE;
}
