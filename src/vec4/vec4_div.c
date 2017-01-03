/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acazuc <acazuc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:25:36 by acazuc            #+#    #+#             */
/*   Updated: 2017/01/03 15:48:58 by acazuc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

void	vec4_div(t_vec4 *dst, t_vec4 *v1, double factor)
{
	dst->x = v1->x / factor;
	dst->y = v1->y / factor;
	dst->z = v1->z / factor;
	dst->w = v1->w / factor;
	dst->u = v1->u / factor;
	dst->v = v1->v / factor;
}
