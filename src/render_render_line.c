/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_render_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:35:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/12 16:13:51 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

static void		calc_vec(t_render *render, t_vec4 *dst, t_vec4 *src)
{
	ft_memset(dst, 0, sizeof(*dst));
	dst->x = (src->x + 1) * render->width / 2 / (src->z / 100);
	dst->y = (src->y + 1) * render->height / 2 / (src->z / 100);
	dst->z = src->z;
}

static void		calc_diff(t_vec4 *v1, t_vec4 *v2, t_vec4 *dif)
{
	ft_memset(dif, 0, sizeof(*dif));
	dif->x = v2->x - v1->x;
	dif->y = v2->y - v1->y;
	dif->z = v2->z - v1->z;
	dif->color.red = v2->color.red - v1->color.red;
	dif->color.green = v2->color.green - v1->color.green;
	dif->color.blue = v2->color.blue - v1->color.blue;
}

static void		loop_intern(t_render *render, t_vec4 *vec)
{
	double	zind;

	if (vec->z <= 0)
		return ;
	zind = render_get_zindex(render, vec->x, vec->y);
	if (zind == 0 || vec->z < zind)
	{
		render_set_zindex(render, vec->x, vec->y, vec->z);
		render_set_pixel(render, vec->x, vec->y, &vec->color);
	}
}

static void		do_draw(t_render *render, t_vec4 *start, t_vec4 *dif)
{
	t_vec4	tmp;
	double	iter;
	double	len;

	len = sqrt(pow(dif->x, 2) + pow(dif->y, 2));
	iter = 0;
	while (iter <= 1)
	{
		tmp.x = render->width / 2 + start->x + dif->x * iter;
		tmp.y = render->height / 2 + start->y + dif->y * iter;
		tmp.z = start->z + dif->z * iter;
		tmp.color.red = start->color.red + dif->color.red * iter;
		tmp.color.green = start->color.green + dif->color.green * iter;
		tmp.color.blue = start->color.blue + dif->color.blue * iter;
		loop_intern(render, &tmp);
		if (iter == 1)
			break;
		iter += 1 / len;
		if (iter > 1)
			iter = 1;
	}
}

void	render_render_line(t_render *render, t_vec4 *v1, t_vec4 *v2)
{
	t_vec4	start;
	t_vec4	end;
	t_vec4	dif;

	calc_vec(render, &start, v1);
	calc_vec(render, &end, v2);
	start.color = v1->color;
	end.color = v2->color;
	calc_diff(&start, &end, &dif);
	do_draw(render, &start, &dif);
}
