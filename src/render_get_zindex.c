/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_get_zindex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:50:50 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 16:53:34 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

double	render_get_zindex(t_render *render, int x, int y)
{
	if (x < 0 || x >= render->width || y < 0 || y >= render->height)
		return (-1);
	return (render->z_index[y * render->width + x]);
}
