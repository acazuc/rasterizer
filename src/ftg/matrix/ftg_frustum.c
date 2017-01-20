/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_frustum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:40:09 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 17:26:13 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_frustum(t_ftg_double x_range[2], t_ftg_double y_range[2], t_ftg_double z_range[2])
{
	t_mat4	mat;

	if (z_range[0] < 0 || z_range[1] < 0)
	{
		g_ctx->errno = FTG_INVALID_ENUM;
		return ;
	}
	mat4_clear(&mat);
	mat.value[0] = (2 * z_range[0]) / (x_range[1] - x_range[0]);
	mat.value[5] = (2 * z_range[0]) / (y_range[1] - y_range[0]);
	mat.value[8] = (x_range[1] + x_range[0]) / (x_range[1] - x_range[0]);
	mat.value[9] = (y_range[1] + y_range[0]) / (y_range[1] - y_range[0]);
	mat.value[10] = -(z_range[1] + z_range[0]) / (z_range[1] - z_range[0]);
	mat.value[11] = -1;
	mat.value[14] = -(2 * z_range[1] * z_range[0]) / (z_range[1] - z_range[0]);
	ftg_mult_matrixd(mat.value);
}
