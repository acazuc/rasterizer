/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_render_vertex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:39:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 15:28:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	render_render_vertex(t_render *render, t_vec4 *vec)
{
	double	x;
	double	y;

	x = vec->x * render->width / 2  + render->width / 2;
	y = vec->y * render->height / 2 + render->height / 2;
	render_put_pixel(render, x, y, vec->z, &vec->color);
}
