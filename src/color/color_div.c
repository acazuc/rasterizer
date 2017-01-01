/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_div.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 12:16:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 16:02:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

static void	check_range(double *val)
{
	if (*val < -1)
		*val = -1;
	else if (*val > 1)
		*val = 1;
}

t_color		color_div(t_color *color, double factor)
{
	t_color		new;

	new.red = color->red / factor;
	check_range(&new.red);
	new.green = color->green / factor;
	check_range(&new.green);
	new.blue = color->blue / factor;
	check_range(&new.blue);
	new.alpha = color->alpha / factor;
	check_range(&new.alpha);
	return (new);
}
