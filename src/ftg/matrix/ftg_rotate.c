/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:55:15 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:26:59 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_rotated(t_ftg_double angle, t_ftg_double x, t_ftg_double y
		, t_ftg_double z)
{
	t_mat4	rotation;

	x = ftg_mind(1, ftg_maxd(-1, x));
	y = ftg_mind(1, ftg_maxd(-1, y));
	z = ftg_mind(1, ftg_maxd(-1, z));
	mat4_clear(&rotation);
	rotation.value[0] = x * x * (1 - cos(angle)) + cos(angle);
	rotation.value[1] = y * x * (1 - cos(angle)) + z * sin(angle);
	rotation.value[2] = x * z * (1 - cos(angle)) - y * sin(angle);
	rotation.value[4] = x * y * (1 - cos(angle)) - z * sin(angle);
	rotation.value[5] = y * y * (1 - cos(angle)) + cos(angle);
	rotation.value[6] = y * z * (1 - cos(angle)) + x * sin(angle);
	rotation.value[8] = x * z * (1 - cos(angle)) + y * sin(angle);
	rotation.value[9] = y * z * (1 - cos(angle)) - x * sin(angle);
	rotation.value[10] = z * z * (1 - cos(angle)) + cos(angle);
	rotation.value[15] = 1;
	ftg_mult_matrixd(rotation.value);
}

void	ftg_rotatef(t_ftg_float angle, t_ftg_float x, t_ftg_float y
		, t_ftg_float z)
{
	ftg_rotated(angle, x, y, z);
}
