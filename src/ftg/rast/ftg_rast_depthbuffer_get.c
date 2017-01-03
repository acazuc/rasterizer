/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_rast_depthbuffer_get.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:19:48 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:25:01 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

double	ftg_rast_depthbuffer_get(int x, int y)
{
		if (x < 0 || x >= g_ctx->width || y < 0 || y >= g_ctx->height)
					return (0);
			return (g_ctx->depth_buffer[y * g_ctx->width + x]);
}

