/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_ortho.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:26:22 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 17:33:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_ortho(t_ftg_double x_range[2], t_ftg_double y_range[2], t_ftg_double z_range[2])
{
	t_mat4	mat;

	if (x_range[0] == x_range[1]|| y_range[0] == y_range[1] || z_range[0] == z_range[1])
	{
		g_ctx->errno = FTG_INVALID_VALUE;
		return ;
	}
	mat4_clear(&mat);
	mat.value[0] = 2 / (x_range[1] - x_range[0]);
	mat.value[5] = 2 / (y_range[1] - y_range[0]);
	mat.value[10] = -2 / (z_range[1] - z_range[0]);
	mat.value[12] = -(x_range[1] + x_range[0]) / (x_range[1] - x_range[0]);
	mat.value[13] = -(y_range[1] + y_range[0]) / (y_range[1] - y_range[0]);
	mat.value[14] = -(z_range[1] + z_range[0]) / (z_range[1] - z_range[0]);
	mat.value[15] = 1;
	ftg_mult_matrixd(mat.value);
}
