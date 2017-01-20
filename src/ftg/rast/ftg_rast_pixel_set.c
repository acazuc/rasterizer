/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_rast_pixel_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:24:08 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 18:34:36 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_rast_pixel_set(int x, int y, t_color *color)
{
	float	*org[4];
	t_color	src;
	t_color	dst;
	int		pos;

	if (y < 0 || y >= g_ctx->height || x < 0 || x >= g_ctx->width)
		return ;
	pos = (y * g_ctx->width + x) * 4;
	org[0] = &g_ctx->color_buffer[pos + 0];
	org[1] = &g_ctx->color_buffer[pos + 1];
	org[2] = &g_ctx->color_buffer[pos + 2];
	org[3] = &g_ctx->color_buffer[pos + 3];
	dst.red = *org[0];
	dst.green = *org[1];
	dst.blue = *org[2];
	dst.alpha = *org[3];
	ft_memcpy(&src, color, sizeof(src));
	ftg_rast_pixel_set_blend_func_rgb(&src, color, &dst, g_ctx->blend_src_rgb);
	ftg_rast_pixel_set_blend_func_rgb(&dst, color, &dst, g_ctx->blend_dst_rgb);
	ftg_rast_pixel_set_blend_func_alpha(&src, color, &dst, g_ctx->blend_src_alpha);
	ftg_rast_pixel_set_blend_func_alpha(&dst, color, &dst, g_ctx->blend_dst_alpha);
	ftg_rast_pixel_set_blend_equ_rgb(&src, &dst, org);
	ftg_rast_pixel_set_blend_equ_alpha(&src, &dst, org);
	*org[0] = ftg_minf(1, ftg_maxf(0, *org[0]));
	*org[1] = ftg_minf(1, ftg_maxf(0, *org[1]));
	*org[2] = ftg_minf(1, ftg_maxf(0, *org[2]));
	*org[3] = ftg_minf(1, ftg_maxf(0, *org[3]));
}
