#include "libftg.h"

t_ftg_ctx	*ctx;

static void		do_draw_top(t_vec4 *start, t_vec4 *dif)
{
	t_vec4	tmp;
	double	iter;
	double	fac;

	iter = 0;
	while (iter <= dif->y)
	{
		fac = iter / dif->y;
		tmp.x = start->x + dif->x * fac;
		tmp.y = start->y + iter;
		tmp.z = start->z + dif->z * fac;
		tmp.color.red = start->color.red + dif->color.red * fac;
		tmp.color.green = start->color.green + dif->color.green * fac;
		tmp.color.blue = start->color.blue + dif->color.blue * fac;
		tmp.color.alpha = start->color.alpha + dif->color.alpha * fac;
		rast_pixel_put(&tmp);
		++iter;
	}
}

static void		do_draw_bottom(t_vec4 *start, t_vec4 *dif)
{
	t_vec4	tmp;
	double	iter;
	double	fac;

	iter = 0;
	while (iter >= dif->y)
	{
		fac = iter / dif->y;
		tmp.x = start->x + dif->x * fac;
		tmp.y = start->y + iter;
		tmp.z = start->z + dif->z * fac;
		tmp.color.red = start->color.red + dif->color.red * fac;
		tmp.color.green = start->color.green + dif->color.green * fac;
		tmp.color.blue = start->color.blue + dif->color.blue * fac;
		tmp.color.alpha = start->color.alpha + dif->color.alpha * fac;
		rast_pixel_put(&tmp);
		--iter;
	}
}

static void		do_draw_right(t_vec4 *start, t_vec4 *dif)
{
	t_vec4	tmp;
	double	iter;
	double	fac;

	iter = 0;
	while (iter <= dif->x)
	{
		fac = iter / dif->x;
		tmp.x = start->x + iter;
		tmp.y = start->y + dif->y * fac;
		tmp.z = start->z + dif->z * fac;
		tmp.color.red = start->color.red + dif->color.red * fac;
		tmp.color.green = start->color.green + dif->color.green * fac;
		tmp.color.blue = start->color.blue + dif->color.blue * fac;
		tmp.color.alpha = start->color.alpha + dif->color.alpha * fac;
		rast_pixel_put(&tmp);
		++iter;
	}
}

static void		do_draw_left(t_vec4 *start, t_vec4 *dif)
{
	t_vec4	tmp;
	double	iter;
	double	fac;

	iter = 0;
	while (iter >= dif->x)
	{
		fac = iter / dif->x;
		tmp.x = start->x + iter;
		tmp.y = start->y + dif->y * fac;
		tmp.z = start->z + dif->z * fac;
		tmp.color.red = start->color.red + dif->color.red * fac;
		tmp.color.green = start->color.green + dif->color.green * fac;
		tmp.color.blue = start->color.blue + dif->color.blue * fac;
		tmp.color.alpha = start->color.alpha + dif->color.alpha * fac;
		rast_pixel_put(&tmp);
		--iter;
	}
}

void			rast_line(t_vec4 *v1, t_vec4 *v2)
{
	t_vec4	start;
	t_vec4	dif;

	ft_memcpy(&start, v1, sizeof(start));
	start.x = round(ctx->width / 2 + start.x * ctx->width / 2);
	start.y = round(ctx->height / 2 + start.y * ctx->height / 2);
	dif.x = round((v2->x - v1->x) * ctx->width / 2);
	dif.y = round((v2->y - v1->y) * ctx->height / 2);
	dif.z = (v2->z - v1->z);
	dif.color = color_sub(&v2->color, &v1->color);
	if (fabs(dif.x) > fabs(dif.y))
	{
		if (dif.x < 0)
			do_draw_left(&start, &dif);
		else
			do_draw_right(&start, &dif);
	}
	else
	{
		if (dif.y < 0)
			do_draw_bottom(&start, &dif);
		else
			do_draw_top(&start, &dif);
	}
}