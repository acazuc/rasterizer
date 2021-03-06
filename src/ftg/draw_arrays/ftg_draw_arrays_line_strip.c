/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_draw_arrays_line_strip.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:31:21 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:31:28 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_draw_arrays_line_strip(t_ftg_int first, t_ftg_sizei count)
{
	t_vec4		v1;
	t_vec4		v2;
	t_ftg_int	pos;

	pos = 0;
	ftg_draw_arrays_get_vec(&v1, 2 * pos + first);
	ftg_rast_watch_vertex(&v1);
	while (pos < count - 1)
	{
		ftg_draw_arrays_get_vec(&v2, 2 * pos + first + 1);
		ftg_rast_watch_vertex(&v2);
		ftg_rast_line(&v1, &v2);
		v1 = v2;
		++pos;
	}
}
