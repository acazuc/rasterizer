/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_init_translation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 11:37:06 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/12 13:37:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	mat4_init_translation(t_mat4 *mat, double x, double y, double z)
{
	mat4_init_identity(mat);
	mat->value[0][3] = x;
	mat->value[1][3] = y;
	mat->value[2][3] = z;
}
