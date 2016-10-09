/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_resize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 13:19:34 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 13:40:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

static void	do_copy(double **dst, int width, int height)
{
	if (!(*dst = malloc(sizeof(**dst) * (width * height))))
		ERROR("malloc failed");
	ft_memset(*dst, 0, sizeof(**dst) * (width * height));
}

void	render_resize(t_render *render, int width, int height)
{
	double	*z_index;
	double	*colors;
	double	*vertex;

	do_copy(&z_index, width, height);
	do_copy(&colors, width, height);
	do_copy(&vertex, width, height);
	free(render->z_index);
	free(render->colors);
	free(render->vertex);
	render->z_index = z_index;
	render->colors = colors;
	render->vertex = vertex;
	render->width = width;
	render->height = height;
}
