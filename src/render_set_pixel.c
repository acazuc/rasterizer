/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_set_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:42:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 15:02:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	render_set_pixel(t_render *render, int x, int y, t_color *color)
{
	if (y < 0 || y >= render->height || x < 0 || x >= render->width)
		return ;
	render->colors[(y * render->width + x) * 3 + 0] = MAX(0, MIN(1, color->red));
	render->colors[(y * render->width + x) * 3 + 1] = MAX(0, MIN(1, color->green));
	render->colors[(y * render->width + x) * 3 + 2] = MAX(0, MIN(1, color->blue));
}
