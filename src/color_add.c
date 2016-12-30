/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 12:20:04 by acazuc            #+#    #+#             */
/*   Updated: 2016/12/30 15:07:06 by acazuc           ###   ########.fr       */
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

t_color		color_add(t_color *c1, t_color *c2)
{
	t_color		new;

	new.red = c1->red + c2->red;
	check_range(&new.red);
	new.green = c1->green + c2->green;
	check_range(&new.green);
	new.blue = c1->blue + c2->blue;
	check_range(&new.blue);
	return (new);
}
