/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_init_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 11:42:08 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 12:27:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	mat4_init_rotation_x(t_mat4 *mat, double angle)
{
	mat4_clear(mat);
	mat->value[0] = 1;
	mat->value[5] = cos(angle);
	mat->value[9] = -sin(angle);
	mat->value[6] = sin(angle);
	mat->value[10] = cos(angle);
	mat->value[15] = 1;
}

void	mat4_init_rotation_y(t_mat4 *mat, double angle)
{
	mat4_clear(mat);
	mat->value[0] = cos(angle);
	mat->value[8] = sin(angle);
	mat->value[5] = 1;
	mat->value[2] = -sin(angle);
	mat->value[10] = cos(angle);
	mat->value[15] = 1;
}

void	mat4_init_rotation_z(t_mat4 *mat, double angle)
{
	mat4_clear(mat);
	mat->value[0] = cos(angle);
	mat->value[4] = -sin(angle);
	mat->value[1] = sin(angle);
	mat->value[5] = cos(angle);
	mat->value[10] = 1;
	mat->value[15] = 1;
}
