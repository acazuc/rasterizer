/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_set_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:42:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 15:59:35 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	render_set_pixel(t_ftg_ctx *ctx, int x, int y, t_color *color)
{
	float	*red;
	float	*green;
	float	*blue;
	float	*alpha;
	int	pos;

	if (y < 0 || y >= ctx->height || x < 0 || x >= ctx->width)
		return ;
	pos = (y * ctx->width + x) * 4;
	red = &ctx->color_buffer[pos + 0];
	green = &ctx->color_buffer[pos + 1];
	blue = &ctx->color_buffer[pos + 2];
	alpha = &ctx->color_buffer[pos + 3];
	*alpha = 1;
	if (color->alpha == 1)
	{
		*red = MAX(0, MIN(1, color->red));
		*green = MAX(0, MIN(1, color->green));
		*blue = MAX(0, MIN(1, color->blue));
	}
	else
	{
		*red = MAX(0, MIN(1, color->red * color->alpha + *red * (1 - color->alpha)));
		*green = MAX(0, MIN(1, color->green * color->alpha + *green * (1 - color->alpha)));
		*blue = MAX(0, MIN(1, color->blue * color->alpha + *blue * (1 - color->alpha)));
	}
}
