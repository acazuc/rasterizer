/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 12:16:35 by acazuc            #+#    #+#             */
/*   Updated: 2016/10/09 12:23:19 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rasterizer.h"

static void	check_range(double *val)
{
	if (*val < 0)
		*val = 0;
	else if (*val > 1)
		*val = 1;
}

t_color		color_mult(t_color *color, double factor)
{
	t_color		new;

	new.red = color->red * factor;
	check_range(&new.red);
	new.green = color->green * factor;
	check_range(&new.green);
	new.blue = color->blue * factor;
	check_range(&new.blue);
	return (new);
}
