/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_rast_depthbuffer_set.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:22:42 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:37:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_rast_depthbuffer_set(int x, int y, double z)
{
	if (x < 0 || x >= g_ctx->width || y < 0 || y >= g_ctx->height)
		return ;
	g_ctx->depth_buffer[y * g_ctx->width + x] = z;
}
