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

	x = vec->x * mat->value[0]
		+ vec->y * mat->value[4]
		+ vec->z * mat->value[8]
		+ vec->w * mat->value[12];
	y = vec->x * mat->value[1]
		+ vec->y * mat->value[5]
		+ vec->z * mat->value[9]
		+ vec->w * mat->value[13];
	z = vec->x * mat->value[2]
		+ vec->y * mat->value[6]
		+ vec->z * mat->value[10]
		+ vec->w * mat->value[14];
	vec->x = x;
	vec->y = y;
	vec->z = z;
	vec->w = 1;
}
