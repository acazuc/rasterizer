/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 12:20:04 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 15:25:52 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

static void	check_range(double *val)
{
	if (*val < -1)
		*val = -1;
	else if (*val > 1)
		*val = 1;
}

void	color_add(t_color *dst, t_color *c1, t_color *c2)
{
	dst->red = c1->red + c2->red;
	check_range(&dst->red);
	dst->green = c1->green + c2->green;
	check_range(&dst->green);
	dst->blue = c1->blue + c2->blue;
	check_range(&dst->blue);
	dst->alpha = c1->alpha + c2->alpha;
	check_range(&dst->alpha);
}
