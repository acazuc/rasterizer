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
	t_ftg_boolean	ret;
	double		ratio;

	ret = FTG_FALSE;
	if (v1->x < 0)
	{
		ratio = 1 - (-v1->x / dif->x);
		v1->x = 0;
		v1->y = v2->y - ratio * dif->y;
		v1->z = v2->z - ratio * dif->z;
		v1->color.red = v2->color.red - ratio * dif->color.red;
		v1->color.green = v2->color.green - ratio * dif->color.green;
		v1->color.blue = v2->color.blue - ratio * dif->color.blue;
		v1->color.alpha = v2->color.alpha - ratio * dif->color.alpha;
		_calc_dif(dif, v1, v2);
		ret |= FTG_TRUE;
	}
	if (v1->y < 0)
	{
		ratio = 1 - (-v1->y / dif->y);
		v1->x = v2->x - ratio * dif->x;
		v1->y = 0;
		v1->z = v2->z - ratio * dif->z;
		v1->color.red = v2->color.red - ratio * dif->color.red;
		v1->color.green = v2->color.green - ratio * dif->color.green;
		v1->color.blue = v2->color.blue - ratio * dif->color.blue;
		v1->color.alpha = v2->color.alpha - ratio * dif->color.alpha;
		_calc_dif(dif, v1, v2);
		ret |= FTG_TRUE;
	}
	if (v1->x >= ctx->width)
	{
		ratio = 1 - ((v1->x - (ctx->width - 1)) / -dif->x);
		v1->x = ctx->width - 1;
		v1->y = v2->y - ratio * dif->y;
		v1->z = v2->z - ratio * dif->z;
		v1->color.red = v2->color.red - ratio * dif->color.red;
		v1->color.green = v2->color.green - ratio * dif->color.green;
		v1->color.blue = v2->color.blue - ratio * dif->color.blue;
		v1->color.alpha = v2->color.alpha - ratio * dif->color.alpha;
		_calc_dif(dif, v1, v2);
		ret |= FTG_TRUE;
	}
	if (v1->y >= ctx->height)
	{
		ratio = 1 - ((v1->y - (ctx->height - 1)) / -dif->y);
		v1->x = v2->x - ratio * dif->x;
		v1->y = ctx->height - 1;
		v1->z = v2->z - ratio * dif->z;
		v1->color.red = v2->color.red - ratio * dif->color.red;
		v1->color.green = v2->color.green - ratio * dif->color.green;
		v1->color.blue = v2->color.blue - ratio * dif->color.blue;
		v1->color.alpha = v2->color.alpha - ratio * dif->color.alpha;
		_calc_dif(dif, v1, v2);
		ret |= FTG_TRUE;
	}
	return (ret);
}

static t_ftg_boolean	_truncate_v2(t_vec4 *dif, t_vec4 *v1, t_vec4 *v2)
{
	t_ftg_boolean	ret;
	double		ratio;

	ret = FTG_FALSE;
	if (v2->x < 0)
	{
		ratio = 1 - (-v2->x / -dif->x);
		v2->x = 0;
		v2->y = v1->y + ratio * dif->y;
		v2->z = v1->z + ratio * dif->z;
		v2->color.red = v1->color.red + ratio * dif->color.red;
		v2->color.green = v1->color.green + ratio * dif->color.green;
		v2->color.blue = v1->color.blue + ratio * dif->color.blue;
		v2->color.alpha = v1->color.alpha + ratio * dif->color.alpha;
		_calc_dif(dif, v1, v2);
		ret |= FTG_TRUE;
	}
	if (v2->y < 0)
	{
		ratio = 1 - (-v2->y / -dif->y);
		v2->x = v1->x + ratio * dif->x;
		v2->y = 0;
		v2->z = v1->z + ratio * dif->z;
		v2->color.red = v1->color.red + ratio * dif->color.red;
		v2->color.green = v1->color.green + ratio * dif->color.green;
		v2->color.blue = v1->color.blue + ratio * dif->color.blue;
		v2->color.alpha = v1->color.alpha + ratio * dif->color.alpha;
		_calc_dif(dif, v1, v2);
		ret |= FTG_TRUE;
	}
	if (v2->x >= ctx->width)
	{
		ratio = 1 - ((v2->x - (ctx->width - 1)) / dif->x);
		v2->x = ctx->width - 1;
		v2->y = v1->y + ratio * dif->y;
		v2->z = v1->z + ratio * dif->z;
		v2->color.red = v1->color.red + ratio * dif->color.red;
		v2->color.green = v1->color.green + ratio * dif->color.green;
		v2->color.blue = v1->color.blue + ratio * dif->color.blue;
		v2->color.alpha = v1->color.alpha + ratio * dif->color.alpha;
		_calc_dif(dif, v1, v2);
		ret |= FTG_TRUE;
	}
	if (v2->y >= ctx->height)
	{
		ratio = 1 - ((v2->y - (ctx->height - 1)) / dif->y);
		v2->x = v1->x + ratio * dif->x;
		v2->y = ctx->height - 1;
		v2->z = v1->z + ratio * dif->z;
		v2->color.red = v1->color.red + ratio * dif->color.red;
		v2->color.green = v1->color.green + ratio * dif->color.green;
		v2->color.blue = v1->color.blue + ratio * dif->color.blue;
		v2->color.alpha = v1->color.alpha + ratio * dif->color.alpha;
		_calc_dif(dif, v1, v2);
		ret |= FTG_TRUE;
	}
	return (ret);
}

t_ftg_boolean			rast_line_truncate(t_vec4 *v1, t_vec4 *v2, t_vec4 *dif)
{
	if (_is_out_of_screen(v1, v2) == FTG_TRUE)
		return (FTG_TRUE);
	_calc_dif(dif, v1, v2);
	if (_truncate_v1(dif, v1, v2) == FTG_TRUE)
	{
		if (_is_out_of_screen(v1, v2) == FTG_TRUE)
			return (FTG_TRUE);
	}
	if (_truncate_v2(dif, v1, v2) == FTG_TRUE)
	{
		if (_is_out_of_screen(v1, v2) == FTG_TRUE)
			return (FTG_TRUE);
	}
	if (_is_out_of_screen(v1, v2) == FTG_TRUE)
		return (FTG_TRUE);
	return (FTG_FALSE);
}
