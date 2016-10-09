/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_set_zindex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:45:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 16:53:29 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	render_set_zindex(t_render *render, int x, int y, double z)
{
	if (x < 0 || x >= render->width || y < 0 || y >= render->height)
		return ;
	render->z_index[y * render->width + x] = z;
}
