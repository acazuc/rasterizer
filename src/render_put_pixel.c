/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_put_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 15:25:02 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 15:39:30 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	render_put_pixel(t_render *render, int x, int y, double z, t_color *color)
{
	double	current_z;

	if (x < 0 || x >= render->width || y < 0 || y >= render->height
			|| z < Z_MIN || z > Z_MAX)
		return ;
	current_z = render_get_zindex(render, x, y);
	if (current_z && z >= current_z)
		return ;
	render_set_pixel(render, x, y, color);
	render_set_zindex(render, x, y, z);
}
