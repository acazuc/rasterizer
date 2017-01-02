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

void	rast_line_draw_bottom(t_vec4 *start, t_vec4 *dif)
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

void	rast_line_draw_right(t_vec4 *start, t_vec4 *dif)
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

void	rast_line_draw_left(t_vec4 *start, t_vec4 *dif)
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
