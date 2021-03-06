/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_rast_triangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:25:03 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/21 14:24:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

static void		_render_bottom_flat(t_vec4 *v1, t_vec4 *v2, t_vec4 *v3)
{
	t_vec4	step1;
	t_vec4	step2;
	t_vec4	tmp_v1;
	t_vec4	tmp_v2;
	t_vec4	n1;
	t_vec4	n2;
	double	tmp;

	tmp = (v2->y - v1->y);
	vec4_sub(&step1, v2, v1);
	vec4_div(&step1, &step1, tmp);
	tmp = (v3->y - v1->y);
	vec4_sub(&step2, v3, v1);
	vec4_div(&step2, &step2, tmp);
	n1 = *v1;
	n2 = *v1;
	if (step2.x < step1.x)
	{
		tmp_v1 = step1;
		step1 = step2;
		step2 = tmp_v1;
	}
	for (int y = v1->y; y <= v2->y; ++y)
	{
		for (int x = n1.x; x <= n2.x; ++x)
		{
			tmp = (x - n1.x) / (n2.x - n1.x);
			vec4_mul(&tmp_v1, &n1, 1 - tmp);
			vec4_mul(&tmp_v2, &n2, tmp);
			vec4_add(&tmp_v1, &tmp_v1, &tmp_v2);
			ftg_rast_pixel_put(&tmp_v1);
		}
		vec4_add(&n1, &n1, &step1);
		vec4_add(&n2, &n2, &step2);
	}
}

static void		_render_top_flat(t_vec4 *v1, t_vec4 *v2, t_vec4 *v3)
{
	t_vec4	step1;
	t_vec4	step2;
	t_vec4	tmp_v1;
	t_vec4	tmp_v2;
	t_vec4	n1;
	t_vec4	n2;
	double	tmp;

	tmp = v3->y - v1->y;
	vec4_sub(&step1, v3, v1);
	vec4_div(&step1, &step1, tmp);
	tmp = v3->y - v2->y;
	vec4_sub(&step2, v3, v2);
	vec4_div(&step2, &step2, tmp);
	n1 = *v3;
	n2 = *v3;
	if (step1.x < step2.x)
	{
		tmp_v1 = step1;
		step1 = step2;
		step2 = tmp_v1;
	}
	for (int y = v3->y; y >= v1->y; --y)
	{
		for (int x = n1.x; x <= n2.x; ++x)
		{
			tmp = (x - n1.x) / (n2.x - n1.x);
			vec4_mul(&tmp_v1, &n1, 1 - tmp);
			vec4_mul(&tmp_v2, &n2, tmp);
			vec4_add(&tmp_v1, &tmp_v1, &tmp_v2);
			ftg_rast_pixel_put(&tmp_v1);
		}
		vec4_sub(&n1, &n1, &step1);
		vec4_sub(&n2, &n2, &step2);
	}
}

static void		_render_not_flat(t_vec4 *v1, t_vec4 *v2, t_vec4 *v3)
{
	double		factor;
	t_vec4		new;

	factor = (v2->y - v1->y) / (v3->y - v1->y);
	new.x = v1->x + factor * (v3->x - v1->x);
	new.y = v2->y;
	new.z = v2->z + factor * (v3->z - v1->z);
	new.color.red = v1->color.red + factor * (v3->color.red - v1->color.red);
	new.color.green = v1->color.green + factor * (v3->color.green - v1->color.green);
	new.color.blue = v1->color.blue + factor * (v3->color.blue - v1->color.blue);
	new.color.alpha = v1->color.alpha + factor * (v3->color.alpha - v1->color.alpha);
	_render_top_flat(v2, &new, v3);
	_render_bottom_flat(v1, v2, &new);
}

static void		_get_vertices_sorted(t_vec4 **v1, t_vec4 **v2, t_vec4 **v3)
{
	t_vec4	*tmp;

	if ((*v1)->y > (*v2)->y)
	{
		tmp = *v1;
		*v1 = *v2;
		*v2 = tmp;
	}
	if ((*v1)->y > (*v3)->y)
	{
		tmp = *v1;
		*v1 = *v3;
		*v3 = tmp;
	}
	if ((*v2)->y > (*v3)->y)
	{
		tmp = *v2;
		*v2 = *v3;
		*v3 = tmp;
	}
}

void			ftg_rast_triangle(t_vec4 *p1, t_vec4 *p2, t_vec4 *p3)
{
	t_vec4	*points[3];

	if (ftg_rast_triangle_truncate(p1, p2, p3))
		return ;
	points[0] = p1;
	points[1] = p2;
	points[2] = p3;
	_get_vertices_sorted(&points[0], &points[1], &points[2]);
	if (points[1]->y == points[2]->y)
		_render_bottom_flat(points[0], points[1], points[2]);
	else if (points[0]->y == points[1]->y)
		_render_top_flat(points[0], points[1], points[2]);
	else
		_render_not_flat(points[0], points[1], points[2]);
}
