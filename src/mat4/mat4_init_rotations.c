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
	mat->value[0][0] = 1;
	mat->value[1][1] = cos(angle);
	mat->value[1][2] = -sin(angle);
	mat->value[2][1] = sin(angle);
	mat->value[2][2] = cos(angle);
	mat->value[3][3] = 1;
}

void	mat4_init_rotation_y(t_mat4 *mat, double angle)
{
	mat4_clear(mat);
	mat->value[0][0] = cos(angle);
	mat->value[0][2] = sin(angle);
	mat->value[1][1] = 1;
	mat->value[2][0] = -sin(angle);
	mat->value[2][2] = cos(angle);
	mat->value[3][3] = 1;
}

void	mat4_init_rotation_z(t_mat4 *mat, double angle)
{
	mat4_clear(mat);
	mat->value[0][0] = cos(angle);
	mat->value[0][1] = -sin(angle);
	mat->value[1][0] = sin(angle);
	mat->value[1][1] = cos(angle);
	mat->value[2][2] = 1;
	mat->value[3][3] = 1;
}
