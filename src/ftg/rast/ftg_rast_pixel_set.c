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
	/*if (color->alpha == 1)
	{
		*red = ftg_maxf(0, ftg_minf(1, color->red));
		*green = ftg_maxf(0, ftg_minf(1, color->green));
		*blue = ftg_maxf(0, ftg_minf(1, color->blue));
		*alpha = 1;
	}
	else
	{
		*red = ftg_maxf(0, ftg_minf(1, color->red * color->alpha + *red * (1 - color->alpha)));
		*green = ftg_maxf(0, ftg_minf(1, color->green * color->alpha + *green * (1 - color->alpha)));
		*blue = ftg_maxf(0, ftg_minf(1, color->blue * color->alpha + *blue * (1 - color->alpha)));
		*alpha = ftg_maxf(0, ftg_minf(1, *alpha + color->alpha * (1 - *alpha)));
	}*/
	ftg_rast_pixel_set_blend_rgb(&src, color, &dst, g_ctx->blend_src_rgb);
	ftg_rast_pixel_set_blend_rgb(&dst, color, &dst, g_ctx->blend_src_rgb);
}
