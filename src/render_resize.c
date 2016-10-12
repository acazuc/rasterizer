/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 13:19:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/12 14:31:46 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

static void	do_copy(char **dst, int width, int height, int mult)
{
	if (!(*dst = malloc(width * height * mult)))
		ERROR("malloc failed");
	ft_memset(*dst, 0, width * height * mult);
}

void	render_resize(t_render *render, int width, int height)
{
	double			*z_index;
	float			*colors;

	do_copy((char**)&z_index, width, height, 1 + sizeof(*z_index));
	do_copy((char**)&colors, width, height, 3 + sizeof(*colors));
	free(render->z_index);
	free(render->colors);
	render->z_index = z_index;
	render->colors = colors;
	render->width = width;
	render->height = height;
	render_render(render);
}
