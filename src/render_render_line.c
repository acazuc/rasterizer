/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_render_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:35:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/12 14:51:00 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

static void		calc_vec(t_render *render, t_vec4 *dst, t_vec4 *src)
{
	ft_memset(dst, 0, sizeof(*dst));
	dst->x = (src->x + 1) * render->width / 2 / (src->z / 100);
	dst->y = (src->y + 1) * render->height / 2 / (src->z / 100);
}

static void		calc_diff(t_vec4 *v1, t_vec4 *v2, t_vec4 *dif)
{
	ft_memset(dif, 0, sizeof(*dif));
	dif->x = v2->x - v1->x;
	dif->y = v2->y - v1->y;
	dif->z = v2->z - v1->z;
}

static void		loop_intern(t_render *render, double x, double y, double z)
{
	double	zind;

	zind = render_get_zindex(render, x, y);
	if (zind == 0 || z < zind)
	{
		render_set_zindex(render, x, y, z);
		render_set_pixel(render, x, y, &vec->color);
	}
}

void	render_render_line(t_render *render, t_vec4 *v1, t_vec4 *v2)
{
	t_vec4	start;
	t_vec4	end;
	t_vec4	dif;
	double	iter;
	double	len;

	calc_vec(render, v1, &start);
	calc_vec(render, v2, &end);
	calc_diff(&start, &end, &dif);
	len = sqrt(pow(dif.x, 2) + pow(dif.y, 2));
	iter = 0;
	while (iter < 1)
	{
		loop_intern(render, start.x + dif.x * iter, start.y + dif.y * iter
				, start.z + dif.z * iter);
		iter += 1 / len;
	}
}
