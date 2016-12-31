/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_render_vertex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 16:39:31 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 15:28:02 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

void	render_render_vertex(t_render *render, t_vec4 *vec)
{
	t_vec4	tmp;

	ft_memcpy(&tmp, vec, sizeof(tmp));
	tmp.x = render->width / 2 + tmp.x * render->width / 2;
	tmp.y = render->height / 2 + tmp.y * render->height / 2;
	render_put_pixel(render, &tmp);
}
