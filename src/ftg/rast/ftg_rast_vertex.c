/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftg_rast_vertex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:25:37 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 22:25:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftg.h"

t_ftg_ctx	*g_ctx;

void	ftg_rast_vertex(t_vec4 *vec)
{
	t_vec4	tmp;

	ft_memcpy(&tmp, vec, sizeof(tmp));
	ftg_rast_pixel_put(&tmp);
}
