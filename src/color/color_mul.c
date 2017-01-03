/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 12:16:35 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 15:45:20 by acazuc           ###   ########.fr       */
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

void		color_mul(t_color *dst, t_color *c1, double factor)
{
	dst->red = c1->red * factor;
	check_range(&dst->red);
	dst->green = c1->green * factor;
	check_range(&dst->green);
	dst->blue = c1->blue * factor;
	check_range(&dst->blue);
	dst->alpha = c1->alpha * factor;
	check_range(&dst->alpha);
}
