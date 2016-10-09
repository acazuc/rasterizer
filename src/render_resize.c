/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 13:19:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 15:47:08 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

static void	vertex_set(short *arr, int width, int height)
{
	short	x;
	short	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			arr[(y * width + x) * 2] = x;
			arr[(y * width + x) * 2 + 1] = y;
			x++;
		}
		y++;
	}
}

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
	short			*vertex;

	do_copy((char**)&z_index, width, height, 1 + sizeof(*z_index));
	do_copy((char**)&colors, width, height, 3 + sizeof(*colors));
	do_copy((char**)&vertex, width, height, 2 + sizeof(*vertex));
	vertex_set(vertex, width, height);
	free(render->z_index);
	free(render->colors);
	free(render->vertex);
	render->z_index = z_index;
	render->colors = colors;
	render->vertex = vertex;
	render->width = width;
	render->height = height;
}
