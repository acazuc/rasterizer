#include "libftg.h"

t_ftg_ctx	*ctx;

static t_ftg_boolean	_is_out_of_screen(t_vec4 *v1, t_vec4 *v2)
{
	if (v1->x < 0 && v2->x < 0)
		return (FTG_TRUE);
	if (v1->x >= ctx->width && v2->x >= ctx->width)
		return (FTG_TRUE);
	if (v1->y < 0 && v2->y < 0)
		return (FTG_TRUE);
	if (v1->y >= ctx->height && v2->y >= ctx->height)
		return (FTG_TRUE);
	return (FTG_FALSE);
}

static void		_calc_dif(t_vec4 *dif, t_vec4 *v1, t_vec4 *v2)
{
	dif->x = v2->x - v1->x;
	dif->y = v2->y - v1->y;
	dif->z = v2->z - v1->z;
	dif->color = color_sub(&v2->color, &v1->color);
}

static t_ftg_boolean	_truncate_v1(t_vec4 *dif, t_vec4 *v1, t_vec4 *v2)
{
	if (v1->x < 0)
	{
		printf("dif x: %f, v1->x: %f, v2->x: %f, v1->y %f, v2->y : %f\n", dif->x, v1->x, v2->x, v1->y, v2->y);
		v1->y = v2->y - (1 - (-v1->x / dif->x)) * dif->y;
		v1->x = 0;
		return (FTG_TRUE);
	}
	if (v1->y < 0)
	{
		v1->x = v2->x - (1 - (-v1->y / dif->y)) * dif->x;
		v1->y = 0;
		return (FTG_TRUE);
	}
	if (v1->x >= ctx->width)
	{
		v1->y = v2->y - (1 - ((v1->x - (ctx->width - 1)) / -dif->x)) * dif->y;
		v1->x = ctx->width - 1;
		return (FTG_TRUE);
	}
	if (v1->y >= ctx->height)
	{
		v1->x = v2->x - (1 - ((v1->y - (ctx->height - 1)) / -dif->y)) * dif->x;
		v1->y = ctx->height - 1;
		return (FTG_TRUE);
	}
	return (FTG_FALSE);
}
/*
static t_ftg_boolean	_truncate_v2(t_vec4 *dif, t_vec4 *v1, t_vec4 *v2)
{
	(void)dif;
	(void)v1;
	(void)v2;
	return (FTG_FALSE);
}*/

void			rast_line(t_vec4 *v1, t_vec4 *v2)
{
	t_vec4	dif;

	if (_is_out_of_screen(v1, v2) == FTG_TRUE)
		return ;
	_calc_dif(&dif, v1, v2);
	while (_truncate_v1(&dif, v1, v2) == FTG_TRUE)
	{
		printf("truncated to: x: %f, y: %f\n", v1->x, v1->y);
		if (_is_out_of_screen(v1, v2) == FTG_TRUE)
			return ;
		_calc_dif(&dif, v1, v2);
	}
	if (_is_out_of_screen(v1, v2) == FTG_TRUE)
		return ;
	if (fabs(dif.x) > fabs(dif.y))
	{
		if (dif.x < 0)
			rast_line_draw_left(v1, &dif);
		else
			rast_line_draw_right(v1, &dif);
	}
	else
	{
		if (dif.y < 0)
			rast_line_draw_bottom(v1, &dif);
		else
			rast_line_draw_top(v1, &dif);
	}
}
