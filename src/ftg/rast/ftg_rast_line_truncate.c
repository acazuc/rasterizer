/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_rast_line_truncate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:22:46 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:39:05 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

static t_ftg_boolean	_is_out_of_screen(t_vec4 *v1, t_vec4 *v2)
{
	if (v1->z < 0 && v2->z < 0)
		return (FTG_TRUE);
	if (v1->z > 1 || v2->z > 1)
		return (FTG_TRUE);
	if (v1->x < 0 && v2->x < 0)
		return (FTG_TRUE);
	if (v1->x >= g_ctx->width && v2->x >= g_ctx->width)
		return (FTG_TRUE);
	if (v1->y < 0 && v2->y < 0)
		return (FTG_TRUE);
	if (v1->y >= g_ctx->height && v2->y >= g_ctx->height)
		return (FTG_TRUE);
	return (FTG_FALSE);
}

static void		_calc_dif(t_vec4 *dif, t_vec4 *v1, t_vec4 *v2)
{
	vec4_sub(dif, v2, v1);
}

static t_ftg_boolean	_truncate_v1(t_vec4 *dif, t_vec4 *v1, t_vec4 *v2)
{
	t_ftg_boolean	ret;
	t_vec4			tmp;
	double			ratio;

	ret = FTG_FALSE;
	if (v1->x < 0)
	{
		ratio = 1 - (-v1->x / dif->x);
		vec4_mul(&tmp, dif, ratio);
		vec4_sub(v1, v2, &tmp);
		v1->x = 0;
		_calc_dif(dif, v1, v2);
		ret |= FTG_TRUE;
	}
	if (v1->y < 0)
	{
		ratio = 1 - (-v1->y / dif->y);
		vec4_mul(&tmp, dif, ratio);
		vec4_sub(v1, v2, &tmp);
		v1->y = 0;
		_calc_dif(dif, v1, v2);
		ret |= FTG_TRUE;
	}
	if (v1->x >= g_ctx->width)
	{
		ratio = 1 - ((v1->x - (g_ctx->width - 1)) / -dif->x);
		vec4_mul(&tmp, dif, ratio);
		vec4_sub(v1, v2, &tmp);
		v1->x = g_ctx->width - 1;
		_calc_dif(dif, v1, v2);
		ret |= FTG_TRUE;
	}
	if (v1->y >= g_ctx->height)
	{
		ratio = 1 - ((v1->y - (g_ctx->height - 1)) / -dif->y);
		vec4_mul(&tmp, dif, ratio);
		vec4_sub(v1, v2, &tmp);
		v1->y = g_ctx->height - 1;
		_calc_dif(dif, v1, v2);
		ret |= FTG_TRUE;
	}
	return (ret);
}

static t_ftg_boolean	_truncate_v2(t_vec4 *dif, t_vec4 *v1, t_vec4 *v2)
{
	t_ftg_boolean	ret;
	t_vec4			tmp;
	double			ratio;

	ret = FTG_FALSE;
	if (v2->x < 0)
	{
		ratio = 1 - (-v2->x / -dif->x);
		vec4_mul(&tmp, dif, ratio);
		vec4_add(v2, v1, &tmp);
		v2->x = 0;
		_calc_dif(dif, v1, v2);
		ret |= FTG_TRUE;
	}
	if (v2->y < 0)
	{
		ratio = 1 - (-v2->y / -dif->y);
		vec4_mul(&tmp, dif, ratio);
		vec4_add(v2, v1, &tmp);
		v2->y = 0;
		_calc_dif(dif, v1, v2);
		ret |= FTG_TRUE;
	}
	if (v2->x >= g_ctx->width)
	{
		ratio = 1 - ((v2->x - (g_ctx->width - 1)) / dif->x);
		vec4_mul(&tmp, dif, ratio);
		vec4_add(v2, v1, &tmp);
		v2->x = g_ctx->width - 1;
		_calc_dif(dif, v1, v2);
		ret |= FTG_TRUE;
	}
	if (v2->y >= g_ctx->height)
	{
		ratio = 1 - ((v2->y - (g_ctx->height - 1)) / dif->y);
		vec4_mul(&tmp, dif, ratio);
		vec4_add(v2, v1, &tmp);
		v2->y = g_ctx->height - 1;
		_calc_dif(dif, v1, v2);
		ret |= FTG_TRUE;
	}
	return (ret);
}

t_ftg_boolean			ftg_rast_line_truncate(t_vec4 *v1, t_vec4 *v2, t_vec4 *dif)
{
	if (_is_out_of_screen(v1, v2))
		return (FTG_TRUE);
	_calc_dif(dif, v1, v2);
	if (_truncate_v1(dif, v1, v2))
	{
		if (_is_out_of_screen(v1, v2))
			return (FTG_TRUE);
	}
	if (_truncate_v2(dif, v1, v2))
	{
		if (_is_out_of_screen(v1, v2))
			return (FTG_TRUE);
	}
	if (_is_out_of_screen(v1, v2))
		return (FTG_TRUE);
	return (FTG_FALSE);
}
