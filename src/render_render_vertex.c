/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_render_vertex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:39:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/12 14:39:17 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	render_render_vertex(t_render *render, t_vec4 *vec)
{
	double	x;
	double	y;
	double	z;

	x = (vec->x + 1) * render->width / 2 / (vec->z / 1000);
	y = (vec->y + 1) * render->height / 2 / (vec->z / 1000);
	z = render_get_zindex(render, x, y);
	if (z == 0 || vec->z < z)
	{
		render_set_zindex(render, x, y, vec->z);
		render_set_pixel(render, x, y, &vec->color);
	}
}
