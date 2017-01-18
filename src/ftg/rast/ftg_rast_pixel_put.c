/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_rast_pixel_put.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:24:19 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:39:44 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

static t_ftg_boolean	_test(double test, double cur)
{
	if (g_ctx->depth_func == FTG_NEVER)
		return (FTG_FALSE);
	else if (g_ctx->depth_func == FTG_LESS)
		return (test < cur ? FTG_TRUE : FTG_FALSE);
	else if (g_ctx->depth_func == FTG_EQUAL)
		return (test == cur ? FTG_TRUE : FTG_FALSE);
	else if (g_ctx->depth_func == FTG_LEQUAL)
		return (test <= cur ? FTG_TRUE : FTG_FALSE);
	else if (g_ctx->depth_func == FTG_GREATER)
		return (test > cur ? FTG_TRUE : FTG_FALSE);
	else if (g_ctx->depth_func == FTG_NOTEQUAL)
		return (test != cur ? FTG_TRUE : FTG_FALSE);
	else if (g_ctx->depth_func == FTG_GEQUAL)
		return (test >= cur ? FTG_TRUE : FTG_FALSE);
	else if (g_ctx->depth_func == FTG_ALWAYS)
		return (FTG_TRUE);
	return (FTG_TRUE);
}

void	ftg_rast_pixel_put(t_vec4 *vec)
{
	double	current_z;
	int	x;
	int	y;

	if (vec->x < 0 || vec->x >= g_ctx->width || vec->y < 0 || vec->y >= g_ctx->height
			|| vec->z < 0 || vec->z > 1)
		return ;
	x = round(vec->x);
	y = round(vec->y);
	if (g_ctx->depth_test)
	{
		current_z = ftg_rast_depthbuffer_get(x, y);
		if (current_z && !_test(vec->z, current_z))
			return ;
	}
	ftg_rast_pixel_set(x, y, &vec->color);
	if (g_ctx->depth_writemask)
		ftg_rast_depthbuffer_set(x, y, vec->z);
}
