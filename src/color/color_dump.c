/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 14:15:40 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/21 14:15:41 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

void	color_dump(t_color *color)
{
	printf("red: %f, green: %f, blue: %f, alpha: %f\n", color->red, color->green, color->blue, color->alpha);
}
