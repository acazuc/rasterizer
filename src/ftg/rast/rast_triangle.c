#include "libftg.h"

t_ftg_ctx	*ctx;

static void		_render_bottom_flat(t_vec4 *v1, t_vec4 *v2, t_vec4 *v3)
{
	t_vec4	step1;
	t_vec4	step2;
	t_vec4	n1;
	t_vec4	n2;
	double	tmp;

	tmp = (v2->y - v1->y);
	step1.x = (v2->x - v1->x) / tmp;
	step1.z = (v2->z - v1->z) / tmp;
	step1.color.red = (v2->color.red - v1->color.red) / tmp;
	step1.color.green = (v2->color.green - v1->color.green) / tmp;
	step1.color.blue = (v2->color.blue - v1->color.blue) / tmp;
	step1.color.alpha = (v2->color.alpha - v1->color.alpha) / tmp;
	tmp = (v3->y - v1->y);
	step2.x = (v3->x - v1->x) / tmp;
	step2.z = (v3->z - v1->z) / tmp;
	step2.color.red = (v3->color.red - v1->color.red) / tmp;
	step2.color.green = (v3->color.green - v1->color.green) / tmp;
	step2.color.blue = (v3->color.blue - v1->color.blue) / tmp;
	step2.color.alpha = (v3->color.alpha - v1->color.alpha) / tmp;
	n1.x = v1->x;
	n1.z = v1->z;
	n1.color.red = v1->color.red;
	n1.color.green = v1->color.green;
	n1.color.blue = v1->color.blue;
	n1.color.alpha = v1->color.alpha;
	n2.x = v1->x + 0.5f;
	n2.z = v1->z;
	n2.color.red = v1->color.red;
	n2.color.green = v1->color.green;
	n2.color.blue = v1->color.blue;
	n2.color.alpha = v1->color.alpha;
	if (step2.x < step1.x)
	{
		t_vec4 tmp_v = step1;
		step1 = step2;
		step2 = tmp_v;
	}
	for (int y = v1->y; y <= v2->y; ++y)
	{
		for (int x = n1.x; x <= n2.x; ++x)
		{
			t_vec4 new;
			tmp = (x - n1.x) / (n2.x - n1.x);
			new.x = x;
			new.y = y;
			new.z = (1 - tmp) * n1.z + tmp * n2.z;
			new.color.red = (1 - tmp) * n1.color.red + tmp * n2.color.red;
			new.color.green = (1 - tmp) * n1.color.green + tmp * n2.color.green;
			new.color.blue = (1 - tmp) * n1.color.blue + tmp * n2.color.blue;
			new.color.alpha = (1 - tmp) * n1.color.alpha + tmp * n2.color.alpha;
			rast_pixel_put(&new);
		}
		n1.x += step1.x;
		n1.z += step1.z;
		n1.color.red += step1.color.red;
		n1.color.green += step1.color.green;
		n1.color.blue += step1.color.blue;
		n1.color.alpha += step1.color.alpha;
		n2.x += step2.x;
		n2.z += step2.z;
		n2.color.red += step2.color.red;
		n2.color.green += step2.color.green;
		n2.color.blue += step2.color.blue;
		n2.color.alpha += step2.color.alpha;
	}
}

static void		_render_top_flat(t_vec4 *v1, t_vec4 *v2, t_vec4 *v3)
{
	t_vec4	step1;
	t_vec4	step2;
	t_vec4	n1;
	t_vec4	n2;
	double	tmp;

	tmp = v3->y - v1->y;
	step1.x = (v3->x - v1->x) / tmp;
	step1.z = (v3->z - v1->z) / tmp;
	step1.color.red = (v3->color.red - v1->color.red) / tmp;
	step1.color.green = (v3->color.green - v1->color.green) / tmp;
	step1.color.blue = (v3->color.blue - v1->color.blue) / tmp;
	step1.color.alpha = (v3->color.alpha - v1->color.alpha) / tmp;
	tmp = v3->y - v2->y;
	step2.x = (v3->x - v2->x) / tmp;
	step2.z = (v3->z - v2->z) / tmp;
	step2.color.red = (v3->color.red - v2->color.red) / tmp;
	step2.color.green = (v3->color.green - v2->color.green) / tmp;
	step2.color.blue = (v3->color.blue - v2->color.blue) / tmp;
	step2.color.alpha = (v3->color.alpha - v2->color.alpha) / tmp;
	n1.x = v3->x;
	n1.z = v3->z;
	n1.color.red = v3->color.red;
	n1.color.green = v3->color.green;
	n1.color.blue = v3->color.blue;
	n1.color.alpha = v3->color.alpha;
	n2.x = v3->x + 0.5f;
	n2.z = v3->z;
	n2.color.red = v3->color.red;
	n2.color.green = v3->color.green;
	n2.color.blue = v3->color.blue;
	n2.color.alpha = v3->color.alpha;
	if (step1.x < step2.x)
	{
		t_vec4 tmp_v = step1;
		step1 = step2;
		step2 = tmp_v;
	}
	for (int y = v3->y; y >= v1->y; --y)
	{
		for (int x = n1.x; x <= n2.x; ++x)
		{
			t_vec4 new;
			tmp = (x - n1.x) / (n2.x - n1.x);
			new.x = x;
			new.y = y;
			new.z = (1 - tmp) * n1.z + tmp * n2.z;
			new.color.red = (1 - tmp) * n1.color.red + tmp * n2.color.red;
			new.color.green = (1 - tmp) * n1.color.green + tmp * n2.color.green;
			new.color.blue = (1 - tmp) * n1.color.blue + tmp * n2.color.blue;
			new.color.alpha = (1 - tmp) * n1.color.alpha + tmp * n2.color.alpha;
			rast_pixel_put(&new);
		}
		n1.x -= step1.x;
		n1.z -= step1.z;
		n1.color.red -= step1.color.red;
		n1.color.green -= step1.color.green;
		n1.color.blue -= step1.color.blue;
		n1.color.alpha -= step1.color.alpha;
		n2.x -= step2.x;
		n2.z -= step2.z;
		n2.color.red -= step2.color.red;
		n2.color.green -= step2.color.green;
		n2.color.blue -= step2.color.blue;
		n2.color.alpha -= step2.color.alpha;
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

void			rast_triangle(t_vec4 *p1, t_vec4 *p2, t_vec4 *p3)
{
	t_vec4	*points[3];

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
