/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_init_translation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 11:37:06 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 11:49:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	mat4_init_translation(t_mat4 *mat, double x, double y, double z)
{
	mat4_init_identity(mat);
	mat->value[12] = x;
	mat->value[13] = y;
	mat->value[14] = z;
}
