/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_render_triangle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 12:02:18 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 15:29:33 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

static void		_render_span(t_render *render, t_triangle_span *span, double y)
{
	t_color	color;
	t_color tmp;
	t_vec4	dif;
	double	factor;
	double	factor_step;
	double	x;
	double	z;

	dif.x = span->x2 - span->x1;
	if (dif.x == 0)
		return ;
	dif.color = color_sub(&span->c2, &span->c1);
	dif.z = span->z2 - span->z1;
	factor = 0;
	factor_step = 1 / dif.x;
	x = span->x1;
	while (x < span->x2)
	{
		z = span->z1 + dif.z * factor;
		tmp = color_mult(&dif.color, factor);
		color = color_add(&span->c1, &tmp);
		render_put_pixel(render, x, y, z, &color);
		factor += factor_step;
		++x;
	}
}

static void		_render_span_edges(t_render *render, t_triangle_edge *e1
		, t_triangle_edge *e2)
{
	t_vec4			e1_dif = {color_sub(&e1->c2, &e1->c1), e1->x2 - e1->x1
		, e1->y2 - e1->y1, e1->z2 - e1->z1, 1};
	t_vec4			e2_dif = {color_sub(&e2->c2, &e2->c1), e2->x2 - e2->x1
		, e2->y2 - e2->y1, e2->z2 - e2->z1, 1};
	t_triangle_span	span;
	t_color			tmp;
	double			factors[4];
	double			y;

	if (e1_dif.y == 0 || e2_dif.y == 0)
		return ;
	factors[0] = (e2->y1 - e1->y1) / e1_dif.y;
	factors[1] = 1 / e1_dif.y;
	factors[2] = 0;
	factors[3] = 1 / e2_dif.y;
	y = e2->y1;
	while (y < e2->y2)
	{
		tmp = color_mult(&e1_dif.color, factors[0]);
		span.c1 = color_add(&e1->c1, &tmp);
		span.x1 = e1->x1 + e1_dif.x * factors[0];
		span.z1 = e1->z1 + e1_dif.z * factors[0];
		tmp = color_mult(&e2_dif.color, factors[2]);
		span.c2 = color_add(&e2->c1, &tmp);
		span.x2 = e1->x1 + e2_dif.x * factors[2];
		span.z2 = e2->z1 + e2_dif.z * factors[2];
		_render_span(render, &span, y);
		factors[0] += factors[1];
		factors[2] += factors[3];
		++y;
	}
}

void			render_render_triangle(t_render *render, t_triangle *triangle)
{
	t_triangle_edge		edges[3] = {{triangle->v1.color, triangle->v1.x
	, triangle->v1.y, triangle->v1.z, triangle->v2.color, triangle->v2.x
	, triangle->v2.y, triangle->v2.z}, {triangle->v2.color, triangle->v2.x
	, triangle->v2.y, triangle->v2.z, triangle->v3.color, triangle->v3.x
	, triangle->v3.y, triangle->v3.z}, {triangle->v3.color, triangle->v3.x
	, triangle->v3.y, triangle->v3.z, triangle->v1.color, triangle->v1.x
	, triangle->v1.y, triangle->v1.z}};
	double				max_length;
	int					long_edge;
	double				length;
	int					i;

	i = 0;
	length = 0;
	long_edge = 0;
	while (i < 3)
	{
		edges[i].x1 = render->width / 2 + edges[i].x1 * render->width / 2;
		edges[i].y1 = render->height / 2 + edges[i].y1 * render->height / 2;
		edges[i].x2 = render->width / 2 + edges[i].x2 * render->width / 2;
		edges[i].y2 = render->height / 2 + edges[i].y2 * render->height / 2;
		length = edges[i].y2 - edges[i].y1;
		if (length > max_length)
		{
			max_length = length;
			long_edge = i;
		}
		++i;
	}
	_render_span_edges(render, &edges[long_edge], &edges[(long_edge + 1) % 3]);
	_render_span_edges(render, &edges[long_edge], &edges[(long_edge + 2) % 3]);
}
