/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_init_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 13:57:45 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/12 14:01:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	mat4_init_scale(t_mat4 *mat, double x, double y, double z)
{
	mat4_clear(mat);
	mat->value[0] = x;
	mat->value[5] = y;
	mat->value[10] = z;
	mat->value[15] = 1;
}
