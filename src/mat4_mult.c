/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 12:05:59 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 12:13:56 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

static double	priv_patch(t_mat4 *m1, t_mat4 *m2, int x, int y)
{
	return (m1->value[y][0] * m2->value[0][x]
			+ m1->value[y][1] * m2->value[1][x]
			+ m1->value[y][2] * m2->value[2][x]
			+ m1->value[y][3] * m2->value[3][x]);
}

t_mat4			mat4_mult(t_mat4 *m1, t_mat4 *m2)
{
	t_mat4	new;
	int		y;
	int		x;

	mat4_clear(&new);
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			new.value[y][x] = priv_patch(m1, m2, x, y);
			x++;
		}
		y++;
	}
	return (new);
}
