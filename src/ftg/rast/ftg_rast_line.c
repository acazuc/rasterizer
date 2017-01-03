/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_rast_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:25:23 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:25:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void			ftg_rast_line(t_vec4 *v1, t_vec4 *v2)
{
	t_vec4	dif;

	if (ftg_rast_line_truncate(v1, v2, &dif))
		return ;
	if (fabs(dif.x) > fabs(dif.y))
	{
		if (dif.x < 0)
			ftg_rast_line_draw_left(v1, &dif);
		else
			ftg_rast_line_draw_right(v1, &dif);
	}
	else
	{
		if (dif.y < 0)
			ftg_rast_line_draw_bottom(v1, &dif);
		else
			ftg_rast_line_draw_top(v1, &dif);
	}
}
