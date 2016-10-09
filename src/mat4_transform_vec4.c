/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_transform_vec4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 12:53:27 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 13:13:37 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	mat4_transform_vec4(t_mat4 *mat, t_vec4 *vec)
{
	double	x;
	double	y;
	double	z;

	x = vec->x * mat->value[0][0]
		+ vec->y * mat->value[0][1]
		+ vec->z * mat->value[0][2]
		+ vec->w * mat->value[0][3];
	y = vec->x * mat->value[1][0]
		+ vec->y * mat->value[1][1]
		+ vec->z * mat->value[1][2]
		+ vec->w * mat->value[1][3];
	z = vec->x * mat->value[2][0]
		+ vec->y * mat->value[2][1]
		+ vec->z * mat->value[2][2]
		+ vec->w * mat->value[2][3];
	vec->x = x;
	vec->y = y;
	vec->z = z;
	vec->w = 1;
}
