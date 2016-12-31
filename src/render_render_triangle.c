/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_render_triangle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 12:02:18 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 18:42:40 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

static void		_render_bottom_flat(t_render *render, t_triangle *tr)
{
	t_vec4	v1;
	t_vec4	v2;
	t_vec4	step1;
	t_vec4	step2;

	double v2v1Diff = (tr->v2.y - tr->v1.y);
	step1.x = (tr->v2.x - tr->v1.x) / v2v1Diff;
	step1.z = (tr->v2.z - tr->v1.z) / v2v1Diff;
	step1.color.red = (tr->v2.color.red - tr->v1.color.red) / v2v1Diff;
	step1.color.green = (tr->v2.color.green - tr->v1.color.green) / v2v1Diff;
	step1.color.blue = (tr->v2.color.blue - tr->v1.color.blue) / v2v1Diff;
	step1.color.alpha = (tr->v2.color.alpha - tr->v1.color.alpha) / v2v1Diff;
	double v3v1Diff = (tr->v3.y - tr->v1.y);
	step2.x = (tr->v3.x - tr->v1.x) / v3v1Diff;
	step2.z = (tr->v3.z - tr->v1.z) / v3v1Diff;
	step2.color.red = (tr->v3.color.red - tr->v1.color.red) / v3v1Diff;
	step2.color.green = (tr->v3.color.green - tr->v1.color.green) / v3v1Diff;
	step2.color.blue = (tr->v3.color.blue - tr->v1.color.blue) / v3v1Diff;
	step2.color.alpha = (tr->v3.color.alpha - tr->v1.color.alpha) / v3v1Diff;
	v1.x = tr->v1.x;
	v1.z = tr->v1.z;
	v1.color.red = tr->v1.color.red;
	v1.color.green = tr->v1.color.green;
	v1.color.blue = tr->v1.color.blue;
	v1.color.alpha = tr->v1.color.alpha;
	v2.x = tr->v1.x + 0.5f;
	v2.z = tr->v1.z;
	v2.color.red = tr->v1.color.red;
	v2.color.green = tr->v1.color.green;
	v2.color.blue = tr->v1.color.blue;
	v2.color.alpha = tr->v1.color.alpha;
	if (step2.x < step1.x)
	{
		t_vec4 tmp = step1;
		step1 = step2;
		step2 = tmp;
	}
	for (int y = tr->v1.y; y <= tr->v2.y; ++y)
	{
		for (int x = (int)ceil(v1.x); x <= (int)v2.x; ++x)
		{
			t_vec4 tmp;
			double t = (x - v1.x) / (v2.x - v1.x);
			tmp.x = x;
			tmp.y = y;
			tmp.z = (1 - t) * v1.z + t * v2.z;
			tmp.color.red = (1 - t) * v1.color.red + t * v2.color.red;
			tmp.color.green = (1 - t) * v1.color.green + t * v2.color.green;
			tmp.color.blue = (1 - t) * v1.color.blue + t * v2.color.blue;
			tmp.color.alpha = (1 - t) * v1.color.alpha + t * v2.color.alpha;
			render_put_pixel(render, &tmp);
		}
		v1.x += step1.x;
		v1.z += step1.z;
		v1.color.red += step1.color.red;
		v1.color.green += step1.color.green;
		v1.color.blue += step1.color.blue;
		v1.color.alpha += step1.color.alpha;
		v2.x += step2.x;
		v2.z += step2.z;
		v2.color.red += step2.color.red;
		v2.color.green += step2.color.green;
		v2.color.blue += step2.color.blue;
		v2.color.alpha += step2.color.alpha;
	}
}

static void		_render_top_flat(t_render *render, t_triangle *tr)
{
	t_vec4	v1;
	t_vec4	v2;
	t_vec4	step1;
	t_vec4	step2;

	double v3v1Diff = tr->v3.y - tr->v1.y;
	step1.x = (tr->v3.x - tr->v1.x) / v3v1Diff;
	step1.color.red = (tr->v3.color.red - tr->v1.color.red) / v3v1Diff;
	step1.color.green = (tr->v3.color.green - tr->v1.color.green) / v3v1Diff;
	step1.color.blue = (tr->v3.color.blue - tr->v1.color.blue) / v3v1Diff;
	step1.color.alpha = (tr->v3.color.alpha - tr->v1.color.alpha) / v3v1Diff;
	step1.z = (tr->v3.z - tr->v1.z) / v3v1Diff;
	double v3v2Diff = tr->v3.y - tr->v2.y;
	step2.x = (tr->v3.x - tr->v2.x) / v3v2Diff;
	step2.color.red = (tr->v3.color.red - tr->v2.color.red) / v3v2Diff;
	step2.color.green = (tr->v3.color.green - tr->v2.color.green) / v3v2Diff;
	step2.color.blue = (tr->v3.color.blue - tr->v2.color.blue) / v3v2Diff;
	step2.color.alpha = (tr->v3.color.alpha - tr->v2.color.alpha) / v3v2Diff;
	step2.z = (tr->v3.z - tr->v2.z) / v3v2Diff;
	v1.x = tr->v3.x;
	v1.z = tr->v3.z;
	v1.color.red = tr->v3.color.red;
	v1.color.green = tr->v3.color.green;
	v1.color.blue = tr->v3.color.blue;
	v1.color.alpha = tr->v3.color.alpha;
	v2.x = tr->v3.x + 0.5f;
	v2.z = tr->v3.z;
	v2.color.red = tr->v3.color.red;
	v2.color.green = tr->v3.color.green;
	v2.color.blue = tr->v3.color.blue;
	v2.color.alpha = tr->v3.color.alpha;
	if (step1.x < step2.x)
	{
		t_vec4 tmp = step1;
		step1 = step2;
		step2 = tmp;
	}
	for (int y = tr->v3.y; y >= tr->v1.y; --y)
	{
		for (int x = (int)ceil(v1.x); x <= (int)v2.x; ++x)
		{
			t_vec4 tmp;
			double t = (x - v1.x) / (v2.x - v1.x);
			tmp.x = x;
			tmp.y = y;
			tmp.z = (1 - t) * v1.z + t * v2.z;
			tmp.color.red = (1 - t) * v1.color.red + t * v2.color.red;
			tmp.color.green = (1 - t) * v1.color.green + t * v2.color.green;
			tmp.color.blue = (1 - t) * v1.color.blue + t * v2.color.blue;
			tmp.color.alpha = (1 - t) * v1.color.alpha + t * v2.color.alpha;
			render_put_pixel(render, &tmp);
		}
		v1.x -= step1.x;
		v1.z -= step1.z;
		v1.color.red -= step1.color.red;
		v1.color.green -= step1.color.green;
		v1.color.blue -= step1.color.blue;
		v1.color.alpha -= step1.color.alpha;
		v2.x -= step2.x;
		v2.z -= step2.z;
		v2.color.red -= step2.color.red;
		v2.color.green -= step2.color.green;
		v2.color.blue -= step2.color.blue;
		v2.color.alpha -= step2.color.alpha;
	}
}

static void		_render_not_flat(t_render *render, t_triangle *tr)
{
	double		factor;
	t_triangle	new;
	t_vec4		tmp;

	factor = (tr->v2.y - tr->v1.y) / (tr->v3.y - tr->v1.y);
	tmp.x = tr->v1.x + factor * (tr->v3.x - tr->v1.x);
	tmp.y = tr->v2.y;
	tmp.z = tr->v2.z;
	tmp.color.red = tr->v1.color.red + factor * (tr->v3.color.red - tr->v1.color.red);
	tmp.color.green = tr->v1.color.green + factor * (tr->v3.color.green - tr->v1.color.green);
	tmp.color.blue = tr->v1.color.blue + factor * (tr->v3.color.blue - tr->v1.color.blue);
	tmp.color.alpha = tr->v1.color.alpha + factor * (tr->v3.color.alpha - tr->v1.color.alpha);
	new.v1 = tr->v2;
	new.v2 = tmp;
	new.v3 = tr->v3;
	_render_top_flat(render, &new);
	new.v1 = tr->v1;
	new.v2 = tr->v2;
	new.v3 = tmp;
	_render_bottom_flat(render, &new);
}

static void		_get_vertices_sorted(t_triangle *triangle)
{
	t_vec4	tmp;

	if (triangle->v1.y > triangle->v2.y)
	{
		tmp = triangle->v1;
		triangle->v1 = triangle->v2;
		triangle->v2 = tmp;
	}
	if (triangle->v1.y > triangle->v3.y)
	{
		tmp = triangle->v1;
		triangle->v1 = triangle->v3;
		triangle->v3 = tmp;
	}
	if (triangle->v2.y > triangle->v3.y)
	{
		tmp = triangle->v2;
		triangle->v2 = triangle->v3;
		triangle->v3 = tmp;
	}
}

void			render_render_triangle(t_render *render, t_triangle *triangle)
{
	t_triangle	intern;

	intern = *triangle;
	intern.v1.x = (int)(render->width / 2 + intern.v1.x * render->width / 2);
	intern.v1.y = (int)(render->height / 2 + intern.v1.y * render->height / 2);
	intern.v2.x = (int)(render->width / 2 + intern.v2.x * render->width / 2);
	intern.v2.y = (int)(render->height / 2 + intern.v2.y * render->height / 2);
	intern.v3.x = (int)(render->width / 2 + intern.v3.x * render->width / 2);
	intern.v3.y = (int)(render->height / 2 + intern.v3.y * render->height / 2);
	_get_vertices_sorted(&intern);
	if (intern.v2.y == intern.v3.y)
		_render_bottom_flat(render, &intern);
	else if (intern.v1.y == intern.v2.y)
		_render_top_flat(render, &intern);
	else
		_render_not_flat(render, &intern);
}
