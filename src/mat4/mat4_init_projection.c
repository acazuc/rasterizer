/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_init_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 11:58:02 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 11:17:03 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	mat4_init_projection(t_mat4 *mat, double sfov, double ratio
		, double ranges[2])
{
	double	fov;

	mat4_clear(mat);
	fov = 1. / tan(ft_toradians(sfov / 2));
	mat->value[0][0] = fov / ratio;
	mat->value[1][1] = fov;
	mat->value[2][2] = (ranges[1] + ranges[0]) / (ranges[0] - ranges[1]);
	mat->value[3][2] = -1;
	mat->value[2][3] = (2 * ranges[0] * ranges[1]) / (ranges[0] - ranges[1]);
}
