/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_draw_arrays_quads.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:30:31 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:30:38 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_draw_arrays_quads(t_ftg_int first, t_ftg_sizei count)
{
	t_vec4		v1;
	t_vec4		v2;
	t_vec4		v3;
	t_vec4		v4;
	t_ftg_int	pos;

	pos = 0;
	while (pos < count)
	{
		ftg_draw_arrays_get_vec(&v1, 4 * pos + first);
		ftg_rast_watch_vertex(&v1);
		ftg_draw_arrays_get_vec(&v2, 4 * pos + first + 1);
		ftg_rast_watch_vertex(&v2);
		ftg_draw_arrays_get_vec(&v3, 4 * pos + first + 2);
		ftg_rast_watch_vertex(&v3);
		ftg_draw_arrays_get_vec(&v4, 4 * pos + first + 3);
		ftg_rast_watch_vertex(&v4);
		ftg_rast_triangle(&v1, &v2, &v3);
		ftg_rast_triangle(&v3, &v4, &v1);
		++pos;
	}
}
