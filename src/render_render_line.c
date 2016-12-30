/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_render_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:35:01 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 18:49:12 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

static void		calc_diff(t_vec4 *v1, t_vec4 *v2, t_vec4 *dif)
{
	ft_memset(dif, 0, sizeof(*dif));
	dif->x = v2->x - v1->x;
	dif->y = v2->y - v1->y;
	dif->z = v2->z - v1->z;
	dif->color = color_sub(&v2->color, &v1->color);
}

static void		do_draw(t_render *render, t_vec4 *start, t_vec4 *dif)
{
	t_vec4	tmp;
	double	iter;
	double	len;

	len = sqrt(pow(dif->x * render->width / 2, 2) + pow(dif->y * render->height / 2, 2));
	iter = 0;
	while (iter <= 1)
	{
		tmp.x = render->width / 2 + (start->x + dif->x * iter) * render->width / 2;
		tmp.y = render->height / 2 + (start->y + dif->y * iter) * render->height / 2;
		tmp.z = start->z + dif->z * iter;
		tmp.color.red = start->color.red + dif->color.red * iter;
		tmp.color.green = start->color.green + dif->color.green * iter;
		tmp.color.blue = start->color.blue + dif->color.blue * iter;
		tmp.color.alpha = start->color.alpha + dif->color.alpha * iter;
		render_put_pixel(render, tmp.x, tmp.y, tmp.z, &tmp.color);
		if (iter == 1)
			break;
		iter += 1 / len;
		if (iter > 1)
			iter = 1;
	}
}

void	render_render_line(t_render *render, t_vec4 *v1, t_vec4 *v2)
{
	t_vec4	dif;

	calc_diff(v1, v2, &dif);
	do_draw(render, v1, &dif);
}
