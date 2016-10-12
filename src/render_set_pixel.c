/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_set_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:42:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/12 14:27:07 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	render_set_pixel(t_render *render, int x, int y, t_color *color)
{
	if (y < 0 || y >= render->height || x < 0 || x >= render->width)
		return ;
	render->colors[(y * render->width + x) * 3 + 0] = color->red;
	render->colors[(y * render->width + x) * 3 + 1] = color->green;
	render->colors[(y * render->width + x) * 3 + 2] = color->blue;
}
