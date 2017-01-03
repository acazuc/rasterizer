/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:51:44 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:27:21 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_scaled(t_ftg_double x, t_ftg_double y, t_ftg_double z)
{
	t_mat4	scale;

	mat4_init_scale(&scale, x, y, z);
	ftg_mult_matrixd(scale.value);
}

void	ftg_scalef(t_ftg_float x, t_ftg_float y, t_ftg_float z)
{
	ftg_scaled(x, y, z);
}
