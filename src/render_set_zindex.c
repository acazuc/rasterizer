/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_set_zindex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:45:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 16:53:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	render_set_zindex(t_ftg_ctx *ctx, int x, int y, double z)
{
	if (x < 0 || x >= ctx->width || y < 0 || y >= ctx->height)
		return ;
	ctx->depth_buffer[y * ctx->width + x] = z;
}
