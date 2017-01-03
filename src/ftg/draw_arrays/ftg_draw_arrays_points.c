/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_draw_arrays_points.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:30:22 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:30:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_draw_arrays_points(t_ftg_int first, t_ftg_sizei count)
{
	t_vec4		vec;
	t_ftg_int	pos;

	pos = 0;
	while (pos < count)
	{
		ftg_draw_arrays_get_vec(&vec, pos + first);
		ftg_rast_watch_vertex(&vec);
		ftg_rast_vertex(&vec);
		++pos;
	}
}
