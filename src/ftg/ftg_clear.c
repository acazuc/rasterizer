/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 19:08:50 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 19:09:23 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*ctx;

static void	clear_colors(void)
{
	int	i;

	i = 0;
	while (i < ctx->width * ctx->height)
	{
		ctx->color_buffer[i * 4 + 0] = ctx->clear_color[0];
		ctx->color_buffer[i * 4 + 1] = ctx->clear_color[1];
		ctx->color_buffer[i * 4 + 2] = ctx->clear_color[2];
		ctx->color_buffer[i * 4 + 3] = ctx->clear_color[3];
		++i;
	}
}

static void	clear_depth(void)
{
	int	i;

	i = 0;
	while (i < ctx->width * ctx->height)
	{
		ctx->depth_buffer[i] = 0;
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
		ctx->errno = FTG_INVALID_VALUE;
}
