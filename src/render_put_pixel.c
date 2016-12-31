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

void	render_put_pixel(t_render *render, t_vec4 *vec)
{
	double	current_z;

	if (vec->x < 0 || vec->x >= render->width || vec->y < 0 || vec->y >= render->height
			|| vec->z < Z_MIN || vec->z > Z_MAX)
		return ;
	current_z = render_get_zindex(render, vec->x, vec->y);
	if (current_z && vec->z >= current_z)
		return ;
	render_set_pixel(render, vec->x, vec->y, &vec->color);
	render_set_zindex(render, vec->x, vec->y, vec->z);
}
