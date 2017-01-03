#include "libftg.h"

t_ftg_ctx	*ctx;

void	rast_line_draw_top(t_vec4 *start, t_vec4 *dif)
{
	t_vec4	tmp;
	double	iter;
	double	fac;

	iter = 0;
	while (iter <= dif->y)
	{
		fac = iter / dif->y;
		vec4_mul(&tmp, dif, fac);
		vec4_add(&tmp, &tmp, start);
		rast_pixel_put(&tmp);
		++iter;
	}
}

void	rast_line_draw_bottom(t_vec4 *start, t_vec4 *dif)
{
	t_vec4	tmp;
	double	iter;
	double	fac;

	iter = 0;
	while (iter >= dif->y)
	{
		fac = iter / dif->y;
		vec4_mul(&tmp, dif, fac);
		vec4_add(&tmp, &tmp, start);
		rast_pixel_put(&tmp);
		--iter;
	}
}

void	rast_line_draw_right(t_vec4 *start, t_vec4 *dif)
{
	t_vec4	tmp;
	double	iter;
	double	fac;

	iter = 0;
	while (iter <= dif->x)
	{
		fac = iter / dif->x;
		vec4_mul(&tmp, dif, fac);
		vec4_add(&tmp, &tmp, start);
		rast_pixel_put(&tmp);
		++iter;
	}
}

void	rast_line_draw_left(t_vec4 *start, t_vec4 *dif)
{
	t_vec4	tmp;
	double	iter;
	double	fac;

	iter = 0;
	while (iter >= dif->x)
	{
		fac = iter / dif->x;
		vec4_mul(&tmp, dif, fac);
		vec4_add(&tmp, &tmp, start);
		rast_pixel_put(&tmp);
		--iter;
	}
}
