/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_perspective.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:55:02 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/20 16:46:53 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_perspective(t_ftg_double fovy, t_ftg_double aspect
		, t_ftg_double z_near, t_ftg_double z_far)
{
	t_mat4	perspective;
	double	ranges[2];

	ranges[0] = z_near;
	ranges[1] = z_far;
	mat4_init_projection(&perspective, fovy, aspect, ranges);
	ftg_mult_matrixd(perspective.value);
}
