/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_get_zindex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:50:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/12 14:36:54 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

double	render_get_zindex(t_ftg_ctx *ctx, int x, int y)
{
	if (x < 0 || x >= ctx->width || y < 0 || y >= ctx->height)
		return (0);
	return (ctx->z_index[y * ctx->width + x]);
}
