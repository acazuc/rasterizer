/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_rast_pixel_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:24:08 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:40:20 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_rast_pixel_set(int x, int y, t_color *color)
{
	float	*red;
	float	*green;
	float	*blue;
	float	*alpha;
	int		pos;

	if (y < 0 || y >= g_ctx->height || x < 0 || x >= g_ctx->width)
		return ;
	pos = (y * g_ctx->width + x) * 4;
	red = &g_ctx->color_buffer[pos + 0];
	green = &g_ctx->color_buffer[pos + 1];
	blue = &g_ctx->color_buffer[pos + 2];
	alpha = &g_ctx->color_buffer[pos + 3];
	if (color->alpha == 1)
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
	}
}
