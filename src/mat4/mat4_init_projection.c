/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_init_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 11:58:02 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 16:47:43 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	mat4_init_projection(t_mat4 *mat, double sfov, double ratio
		, double ranges[2])
{
	double	fov;

	mat4_clear(mat);
	fov = 1. / tan(ft_toradians(sfov / 2));
	mat->value[0] = fov / ratio;
	mat->value[5] = fov;
	mat->value[10] = (ranges[0] + ranges[1]) / (ranges[0] - ranges[1]);
	mat->value[11] = -1;
	mat->value[14] = (2 * ranges[0] * ranges[1]) / (ranges[0] - ranges[1]);
}
